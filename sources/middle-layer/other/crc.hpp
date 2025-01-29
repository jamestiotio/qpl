/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_OTHER_CRC_HPP
#define QPL_SOURCES_MIDDLE_LAYER_OTHER_CRC_HPP

#include "common/defs.hpp"
#include "other/other_defs.hpp"

namespace qpl::ml::other {

template <execution_path_t path>
auto call_crc(const uint8_t* src_ptr, uint32_t length, uint64_t polynomial, bool is_be_bit_order, bool is_inverse,
              int32_t numa_id = -1) noexcept -> crc_operation_result_t;

} // namespace qpl::ml::other

#endif //QPL_SOURCES_MIDDLE_LAYER_OTHER_CRC_HPP
