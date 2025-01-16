/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_CROSS_TESTS_CANNED_TEST_CASES_HPP
#define QPL_TOOLS_TESTS_CROSS_TESTS_CANNED_TEST_CASES_HPP

// tool_common
#include "source_provider.hpp"
#include "util.hpp"

namespace qpl::test {

struct SimpleCannedOneChuckTestCase {
    std::string file_name;
};

std::ostream& operator<<(std::ostream& os, const SimpleCannedOneChuckTestCase& test_case);
} // namespace qpl::test

#endif //QPL_TOOLS_TESTS_CROSS_TESTS_CANNED_TEST_CASES_HPP
