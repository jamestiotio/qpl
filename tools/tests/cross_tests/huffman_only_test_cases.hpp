/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_CROSS_TESTS_HUFFMAN_ONLY_TEST_CASES_HPP
#define QPL_TOOLS_TESTS_CROSS_TESTS_HUFFMAN_ONLY_TEST_CASES_HPP

// tool_common
#include "source_provider.hpp"
#include "util.hpp"

namespace qpl::test {

struct SimpleHuffmanOnlyTestCase {
    bool        is_huffman_be;
    std::string file_name;
};

std::ostream& operator<<(std::ostream& os, const SimpleHuffmanOnlyTestCase& test_case);
} // namespace qpl::test

#endif //QPL_TOOLS_TESTS_CROSS_TESTS_HUFFMAN_ONLY_TEST_CASES_HPP
