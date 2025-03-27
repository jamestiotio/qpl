/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include <memory>
#include <vector>

#include "qpl/qpl.h"

#ifndef QPL_EXECUTION_PATH
#define QPL_EXECUTION_PATH qpl_path_software
#endif

constexpr qpl_path_t execution_path = QPL_EXECUTION_PATH;

enum scan_comparator {
    not_in_range      = 0u,
    in_range          = 1u,
    equals            = 2u,
    not_equals        = 3u,
    less_than         = 4u,
    less_or_equals    = 5u,
    greater_than      = 6u,
    greater_or_equals = 7u,
};

struct scan_properties {
    uint16_t        destination_size   = 0;
    uint32_t        input_bit_width    = 0;
    size_t          number_of_elements = 0;
    qpl_out_format  output_bit_width   = qpl_ow_nom;
    uint32_t        lower_boundary     = 0;
    uint32_t        upper_boundary     = 0;
    scan_comparator comparator;
};

static inline qpl_operation convert_comparator_to_scan_operation(scan_comparator comparator) {

    qpl_operation result = qpl_op_scan_eq;

    // Make sure that the comparator is within the valid range
    comparator = static_cast<scan_comparator>(comparator % (greater_or_equals + 1));

    switch (comparator) {
        case equals: result = qpl_op_scan_eq; break;
        case not_equals: result = qpl_op_scan_ne; break;
        case less_than: result = qpl_op_scan_lt; break;
        case less_or_equals: result = qpl_op_scan_le; break;
        case greater_than: result = qpl_op_scan_gt; break;
        case greater_or_equals: result = qpl_op_scan_ge; break;
        case in_range: result = qpl_op_scan_range; break;
        case not_in_range: result = qpl_op_scan_not_range; break;
        default: break;
    }

    return result;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {
    if (0 == Size) { return 0; }

    qpl_parser parser = static_cast<qpl_parser>(Data[0] % 3);

    Data++;
    Size--;

    if (Size > sizeof(scan_properties)) {
        auto*                properties_ptr = reinterpret_cast<const scan_properties*>(Data);
        std::vector<uint8_t> source(Data + sizeof(scan_properties), Data + Size);
        std::vector<uint8_t> destination(properties_ptr->destination_size);

        qpl_status status;
        uint32_t   job_size = 0;

        // Job initialization
        status = qpl_get_job_size(execution_path, &job_size);
        if (status != QPL_STS_OK) { return 0; }

        auto     job_buffer = std::make_unique<uint8_t[]>(job_size);
        qpl_job* job_ptr    = reinterpret_cast<qpl_job*>(job_buffer.get());

        status = qpl_init_job(execution_path, job_ptr);
        if (status != QPL_STS_OK) { return 0; }

        qpl_operation operation = convert_comparator_to_scan_operation(properties_ptr->comparator);

        job_ptr->next_in_ptr        = source.data();
        job_ptr->available_in       = source.size();
        job_ptr->next_out_ptr       = destination.data();
        job_ptr->available_out      = destination.size();
        job_ptr->op                 = operation;
        job_ptr->num_input_elements = properties_ptr->number_of_elements;
        job_ptr->src1_bit_width     = properties_ptr->input_bit_width;
        job_ptr->param_low          = properties_ptr->lower_boundary;
        job_ptr->param_high         = properties_ptr->upper_boundary;
        job_ptr->out_bit_width      = properties_ptr->output_bit_width;
        job_ptr->parser             = parser;

        status = qpl_execute_job(job_ptr);
    }

    return 0;
}
