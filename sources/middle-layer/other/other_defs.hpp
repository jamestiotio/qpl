/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_OTHER_OTHER_DEFS_HPP
#define QPL_SOURCES_MIDDLE_LAYER_OTHER_OTHER_DEFS_HPP

#include <cstdint>

namespace qpl::ml::other {

struct crc_operation_result_t {
    uint32_t status_code_     = 0U;
    uint32_t processed_bytes_ = 0U;
    uint64_t crc_             = 0U;
};

} // namespace qpl::ml::other

#endif //QPL_SOURCES_MIDDLE_LAYER_OTHER_OTHER_DEFS_HPP
