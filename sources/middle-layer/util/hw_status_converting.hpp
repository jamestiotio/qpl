/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_STATUS_CONVERTING_HPP
#define QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_STATUS_CONVERTING_HPP

#include "qpl/c_api/status.h"

#include "hw_status.h"

namespace qpl::ml::util {

inline qpl_status convert_hw_accelerator_status_to_qpl_status(const uint32_t status) {
    switch (status) {
        case HW_ACCELERATOR_STATUS_OK: return QPL_STS_OK;
        case HW_ACCELERATOR_WQ_IS_BUSY: return QPL_STS_QUEUES_ARE_BUSY_ERR;
        case HW_ACCELERATOR_NULL_PTR_ERR: return QPL_STS_NULL_PTR_ERR;
        case HW_ACCELERATOR_SUPPORT_ERR: return QPL_STS_INIT_HW_NOT_SUPPORTED;
        case HW_ACCELERATOR_LIBACCEL_NOT_FOUND: return QPL_STS_INIT_LIBACCEL_NOT_FOUND;
        case HW_ACCELERATOR_LIBACCEL_ERROR: return QPL_STS_INIT_LIBACCEL_ERROR;
        case HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE: return QPL_STS_INIT_WORK_QUEUES_NOT_AVAILABLE;
        case HW_ACCELERATOR_NOT_SUPPORTED_BY_WQ: return QPL_STS_NOT_SUPPORTED_BY_WQ;
        case HW_ACCELERATOR_TRANSFER_SIZE_EXCEEDED: return QPL_STS_TRANSFER_SIZE_INVALID;
        default: return QPL_STS_LIBRARY_INTERNAL_ERR;
    }
}

} // namespace qpl::ml::util

#endif //QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_STATUS_CONVERTING_HPP
