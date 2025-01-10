/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_DISPATCHER_HPP
#define QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_DISPATCHER_HPP

#include <types.hpp>

#include "c_api/crc64.hpp"
#include "c_api/deflate.hpp"
#include "c_api/inflate.hpp"

namespace bench::ops {
template <api_e api, path_e path, operation_e operation>
struct api_dispatcher_t {};
template <path_e path>
struct api_dispatcher_t<api_e::c, path, operation_e::deflate> {
    using impl_t = c_api::deflate_t<path>;
};
template <path_e path>
struct api_dispatcher_t<api_e::c, path, operation_e::inflate> {
    using impl_t = c_api::inflate_t<path>;
};

template <path_e path>
struct api_dispatcher_t<api_e::c, path, operation_e::crc64> {
    using impl_t = c_api::crc64_t<path>;
};
} // namespace bench::ops

#endif // QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_DISPATCHER_HPP
