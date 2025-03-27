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

struct extract_properties {
    uint16_t       destination_size    = 0;
    uint32_t       input_bit_width     = 0;
    size_t         number_of_elements  = 0;
    qpl_out_format output_bit_width    = qpl_ow_nom;
    uint32_t       high_index_boundary = 0;
    uint32_t       low_index_boundary  = 0;
};

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {
    if (0 == Size) { return 0; }

    qpl_parser parser = static_cast<qpl_parser>(Data[0] % 3);

    Data++;
    Size--;

    if (Size > sizeof(extract_properties)) {
        auto*                properties_ptr = reinterpret_cast<const extract_properties*>(Data);
        std::vector<uint8_t> source(Data + sizeof(extract_properties), Data + Size);
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

        job_ptr->next_in_ptr        = source.data();
        job_ptr->available_in       = source.size();
        job_ptr->next_out_ptr       = destination.data();
        job_ptr->available_out      = destination.size();
        job_ptr->op                 = qpl_op_extract;
        job_ptr->num_input_elements = properties_ptr->number_of_elements;
        job_ptr->src1_bit_width     = properties_ptr->input_bit_width;
        job_ptr->param_low          = properties_ptr->low_index_boundary;
        job_ptr->param_high         = properties_ptr->high_index_boundary;
        job_ptr->out_bit_width      = properties_ptr->output_bit_width;
        job_ptr->parser             = parser;

        status = qpl_execute_job(job_ptr);
    }

    return 0;
}
