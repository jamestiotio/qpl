/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "qpl/qpl.h"

struct deflate_properties {
    size_t destination_size;
};

#ifndef QPL_EXECUTION_PATH
#define QPL_EXECUTION_PATH qpl_path_software
#endif

constexpr qpl_path_t execution_path = QPL_EXECUTION_PATH;

enum compression_mode {
    fixed_compression   = 0,
    dynamic_compression = 1,
    static_compression  = 2,
    canned_compression  = 3,
};

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {
    if (Size < 2) { return 0; }

    qpl_compression_levels compression_level = qpl_default_level;
    if ((Data[0] % 2) == 0) { compression_level = qpl_high_level; }

    compression_mode compression_type = static_cast<compression_mode>(Data[0] % 4);

    Data += 2;
    Size -= 2;

    const uint8_t* source_data_ptr  = Data;
    size_t         source_size      = Size;
    size_t         destination_size = Size;

    if (Size > sizeof(deflate_properties)) {
        deflate_properties* properties = (deflate_properties*)source_data_ptr;
        source_data_ptr += sizeof(deflate_properties);
        source_size -= sizeof(deflate_properties);
        destination_size = properties->destination_size;
        if (0 == destination_size) { destination_size = 1; }
        destination_size %= (source_size + source_size);
        if (0 == destination_size) { destination_size = source_size + source_size; }
    }

    std::vector<uint8_t> source(source_data_ptr, source_data_ptr + source_size);
    std::vector<uint8_t> destination(destination_size, 0xaa);

    {
        qpl_huffman_table_t c_huffman_table {};

        // Get size of the job
        uint32_t job_size = 0;

        qpl_status status = qpl_get_job_size(execution_path, &job_size);
        if (status != QPL_STS_OK) { return 0; }

        // Initialize the job
        auto job_buffer = std::make_unique<uint8_t[]>(job_size);
        auto job_ptr    = reinterpret_cast<qpl_job*>(job_buffer.get());

        status = qpl_init_job(execution_path, job_ptr);
        if (status != QPL_STS_OK) { return 0; }

        // Set up the Huffman table
        if (compression_type == canned_compression || compression_type == static_compression) {
            qpl_histogram histogram {};

            status = qpl_gather_deflate_statistics(source.data(), source.size(), &histogram, compression_level,
                                                   execution_path);

            if (status != QPL_STS_OK) { return 0; }

            status = qpl_deflate_huffman_table_create(combined_table_type, execution_path, DEFAULT_ALLOCATOR_C,
                                                      &c_huffman_table);
            if (status != QPL_STS_OK) { return 0; }

            status = qpl_huffman_table_init_with_histogram(c_huffman_table, &histogram);

            if (status != QPL_STS_OK) {
                qpl_huffman_table_destroy(c_huffman_table);
                return 0;
            }
            job_ptr->huffman_table = c_huffman_table;
        }

        job_ptr->next_in_ptr   = source.data();
        job_ptr->available_in  = source.size();
        job_ptr->next_out_ptr  = destination.data();
        job_ptr->available_out = static_cast<uint32_t>(destination.size());
        job_ptr->total_out     = 0;

        job_ptr->op    = qpl_op_compress;
        job_ptr->level = compression_level;
        job_ptr->flags = QPL_FLAG_FIRST | QPL_FLAG_LAST | QPL_FLAG_OMIT_VERIFY;
        switch (compression_type) {
            case (dynamic_compression): job_ptr->flags |= QPL_FLAG_DYNAMIC_HUFFMAN; break;
            case (canned_compression): job_ptr->flags |= QPL_FLAG_CANNED_MODE; break;
            default: break;
        }

        status = qpl_execute_job(job_ptr);
    }

    return 0;
}
