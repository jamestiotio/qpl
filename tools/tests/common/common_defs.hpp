/*******************************************************************************
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_TESTS_COMMON_COMMON_DEFS_HPP
#define QPL_TOOLS_TESTS_COMMON_COMMON_DEFS_HPP

#include <cstdint>

// Required for PF testing.
// Based on the value, we choose to swap out the pages
// in src-1/src-2 (READ PF) or dst (WRITE PF).
typedef enum : std::uint8_t { READ_SRC_1_PAGE_FAULT, READ_SRC_2_PAGE_FAULT, WRITE_PAGE_FAULT } PageFaultType;

#endif // QPL_TOOLS_TESTS_COMMON_COMMON_DEFS_HPP
