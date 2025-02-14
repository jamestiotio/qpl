/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_FUNCTIONAL_UNIT_TESTS_ALGORITHMIC_T_COMMON_HPP
#define QPL_TOOLS_TESTS_FUNCTIONAL_UNIT_TESTS_ALGORITHMIC_T_COMMON_HPP

#include "gtest/gtest.h"

// tests_common
#include "check_result.hpp"
#include "test_name_format.hpp"

#define QPL_UNIT_API_ALGORITHMIC_TEST(entity, test) TEST(QPL_UNIT_SUITE_NAME(ta, entity), test)

#define QPL_UNIT_API_BAD_ARGUMENT_TEST(entity, test) TEST(QPL_UNIT_SUITE_NAME(tb, entity), test)

#endif //QPL_TOOLS_TESTS_FUNCTIONAL_UNIT_TESTS_ALGORITHMIC_T_COMMON_HPP
