/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_COMPRESSION_DEFLATE_HISTOGRAM_HPP
#define QPL_SOURCES_MIDDLE_LAYER_COMPRESSION_DEFLATE_HISTOGRAM_HPP

#include <cstddef>

#include "qpl/c_api/statistics.h"

#include "common/defs.hpp"

namespace qpl::ml::compression {

using deflate_histogram = qpl_histogram;
using deflate_level     = qpl_compression_levels;

template <
        execution_path_t path, class iterator_t,
        class = typename std::enable_if<path == execution_path_t::software || path == execution_path_t::hardware>::type>
auto update_histogram(iterator_t begin, iterator_t end, deflate_histogram& histogram,
                      deflate_level level = qpl_default_level) noexcept -> qpl_ml_status;
} // namespace qpl::ml::compression

#endif //QPL_SOURCES_MIDDLE_LAYER_COMPRESSION_DEFLATE_HISTOGRAM_HPP
