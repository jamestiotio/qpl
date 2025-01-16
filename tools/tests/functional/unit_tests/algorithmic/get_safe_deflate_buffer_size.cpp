/*******************************************************************************
 * Copyright (C) 2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include <cstdint>

#include "qpl/qpl.h"

#include "t_common.hpp"

namespace qpl::test {

/**
 * @brief Tests the get_safe_deflate_compression_buffer_size() function across the full range of input sizes.
 * The function should return 0 if the input size is too large, accounting for the overhead when a stored block is used.
 * In all other cases, the function should return a value greater than the input size.
 */
QPL_UNIT_API_ALGORITHMIC_TEST(get_safe_deflate_buffer_size, full_input_size_range) {
    for (uint32_t i = UINT32_MAX; i > 0; i--) {
        const uint32_t buffer_size = qpl_get_safe_deflate_compression_buffer_size(i);
        ASSERT_TRUE(buffer_size > i || buffer_size == 0) << "Buffer size: " << buffer_size << " Input size: " << i;
    }
}

} // namespace qpl::test
