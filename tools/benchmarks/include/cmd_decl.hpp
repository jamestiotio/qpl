/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_BENCHMARKS_INCLUDE_CMD_DECL_HPP
#define QPL_TOOLS_BENCHMARKS_INCLUDE_CMD_DECL_HPP

#include <algorithm>
#include <commandlineflags.h>
#include <types.hpp>

namespace bench::cmd {
BM_DECLARE_string(dataset);
BM_DECLARE_string(block_size);
BM_DECLARE_int32(queue_size);
BM_DECLARE_int32(threads);
BM_DECLARE_int32(node);
BM_DECLARE_bool(full_time);
BM_DECLARE_bool(no_hw);
BM_DECLARE_string(in_mem);
BM_DECLARE_string(out_mem);

std::int32_t get_block_size();
mem_loc_e    get_in_mem();
mem_loc_e    get_out_mem();
} // namespace bench::cmd
#endif // QPL_TOOLS_BENCHMARKS_INCLUDE_CMD_DECL_HPP
