/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_CROSS_TESTS_DEFLATE_TEST_CASES_HPP
#define QPL_TOOLS_TESTS_CROSS_TESTS_DEFLATE_TEST_CASES_HPP

#include <cstdint>

// tool_common
#include "source_provider.hpp"
#include "util.hpp"

namespace qpl::test {
enum HeaderType { no_header = 0, gzip_header = QPL_FLAG_GZIP_MODE, zlib_header = QPL_FLAG_ZLIB_MODE };

enum BlockType : std::uint8_t { block_fixed, block_dynamic, block_static };

struct SimpleDeflateTestCase {
    HeaderType  header;
    BlockType   block_type;
    std::string file_name;
};

std::ostream& operator<<(std::ostream& os, const SimpleDeflateTestCase& test_case);
} // namespace qpl::test

#endif //QPL_TOOLS_TESTS_CROSS_TESTS_DEFLATE_TEST_CASES_HPP
