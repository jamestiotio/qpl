/*******************************************************************************
 * Copyright (C) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_COMMON_TOPOLOGY_HPP
#define QPL_TOOLS_UTILS_COMMON_TOPOLOGY_HPP

#include <cstdint>

namespace qpl::test {

int32_t get_numa_id() noexcept;

uint64_t get_socket_id() noexcept;

uint64_t get_socket_id(int numa_node) noexcept;

} // namespace qpl::test

#endif //QPL_TOOLS_UTILS_COMMON_TOPOLOGY_HPP
