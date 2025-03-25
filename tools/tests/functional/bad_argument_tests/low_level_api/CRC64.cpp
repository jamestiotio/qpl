/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/*
 *@file
 *@brief Bad Args tests for CRC64 function
 *
 */

#include "qpl/qpl.h"

#include "gtest/gtest.h"
#include "tb_ll_common.hpp"

// tests_common
#include "dispatcher_checks.hpp"
#include "operation_test.hpp"

// tool_common
#include <array>

#include "operation_test.hpp"
#include "util.hpp"

extern uint32_t perform_crc64(qpl_job* const job_ptr) noexcept;

namespace qpl::test {

static qpl_job* fill_job(qpl_job* job_ptr, uint8_t* src_ptr, int srcLength, uint64_t polynomial) {
    job_ptr->next_in_ptr  = src_ptr;
    job_ptr->available_in = srcLength;
    job_ptr->crc64_poly   = polynomial;

    return job_ptr;
}

QPL_LOW_LEVEL_API_BAD_ARGUMENT_TEST(crc64, base) {
    std::array<uint8_t, SOURCE_ARRAY_SIZE> source {};

    EXPECT_EQ(QPL_STS_NULL_PTR_ERR, perform_crc64(nullptr));
    EXPECT_EQ(QPL_STS_NULL_PTR_ERR, perform_crc64(fill_job(job_ptr, nullptr, 1, 1)));
    EXPECT_EQ(QPL_STS_SIZE_ERR, perform_crc64(fill_job(job_ptr, source.data(), 0, 1)));
    EXPECT_EQ(QPL_STS_CRC64_BAD_POLYNOM, perform_crc64(fill_job(job_ptr, source.data(), 1, 0)));
}

/**
 * @brief A basic @ref qpl_op_crc operation based on accelerator configuration
 */
QPL_LOW_LEVEL_API_BAD_ARGUMENT_TEST(crc64, max_transfer_size) {
    QPL_SKIP_TEST_FOR(qpl_path_software);
    QPL_SKIP_TEST_FOR(qpl_path_auto);

    uint64_t max_transfer_size = get_max_transfer_size();

    // need to allocate one more byte to exceed the transfer size
    auto source = std::unique_ptr<uint8_t[]>(new uint8_t[max_transfer_size + 1]);

    EXPECT_EQ(QPL_STS_TRANSFER_SIZE_INVALID,
              perform_crc64(fill_job(job_ptr, source.get(), static_cast<uint32_t>(max_transfer_size + 1), 1)));
}

} // namespace qpl::test
