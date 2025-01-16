/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_THREAD_TESTS_TT_COMMON_HPP
#define QPL_TOOLS_TESTS_THREAD_TESTS_TT_COMMON_HPP

// tests_common
#include "check_result.hpp"
#include "test_cases.hpp"
#include "test_name_format.hpp"

#define QPL_LOW_LEVEL_API_ALGORITHMIC_TEST(operation, test) TEST(QPL_LOW_LEVEL_SUITE_NAME(tt, operation), test)

#endif //QPL_TOOLS_TESTS_THREAD_TESTS_TT_COMMON_HPP
