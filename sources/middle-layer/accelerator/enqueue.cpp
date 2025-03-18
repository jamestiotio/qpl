/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/**
 * @date 03/23/2020
 * @brief Internal HW API functions for @ref hw_enqueue_descriptor API implementation
 */

#include <unordered_map>

#include "dispatcher/hw_dispatcher.hpp"
#include "hw_definitions.h"
#include "hw_descriptors_api.h"
#include "util/hw_timing_util.hpp"

/* If we didn't successfully submit, we need to prioritize the return value
 * Priority is as follows:
 *   HW_ACCELERATOR_WQ_IS_BUSY                (found a workqueue that supports our descriptor, but it was busy)
 *   HW_ACCELERATOR_TRANSFER_SIZE_EXCEEDED    (found a workqueue that supports our operation, but the transfer size was too large)
 *   HW_ACCELERATOR_NOT_SUPPORTED_BY_WQ       (found an available workqueue, but it didn't support our operation)
 *   HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE (never found an available workqueue)
*/
static const std::unordered_map<hw_accelerator_status, uint8_t> hw_status_to_priority = {
        {HW_ACCELERATOR_WQ_IS_BUSY, 1U},
        {HW_ACCELERATOR_TRANSFER_SIZE_EXCEEDED, 2U},
        {HW_ACCELERATOR_NOT_SUPPORTED_BY_WQ, 3U},
        {HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE, 4U}};

extern "C" hw_accelerator_status hw_enqueue_descriptor(void* desc_ptr, int32_t user_specified_numa_id,
                                                       qpl::ml::util::execution_record_ext_t* record) {
    hw_accelerator_status result = HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE;

#if defined(__linux__)
    static auto&                      dispatcher   = qpl::ml::dispatcher::hw_dispatcher::get_instance();
    static const auto                 device_count = dispatcher.device_count();
    static thread_local std::uint32_t device_idx   = 0;

    if (device_count == 0) { return HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE; }

    for (uint64_t try_count = 0U; try_count < device_count; ++try_count) {
        const auto& device = dispatcher.device(device_idx);
        device_idx         = (device_idx + 1) % device_count;

        if (!device.is_matching_user_numa_policy(user_specified_numa_id)) { continue; }

        hw_iaa_descriptor_hint_cpu_cache_as_destination((hw_descriptor*)desc_ptr, device.get_cache_write_available());

        const hw_accelerator_status enqueue_result = device.enqueue_descriptor(desc_ptr, record);
        // if we successfully submitted return OK immediately
        if (enqueue_result == HW_ACCELERATOR_STATUS_OK) {
#if QPL_EXPERIMENTAL_LOG_IAA
            qpl::ml::util::record_device_idx(record, device_idx);
#endif
            return HW_ACCELERATOR_STATUS_OK;
        }
        if (hw_status_to_priority.at(enqueue_result) < hw_status_to_priority.at(result)) { result = enqueue_result; }
    }
#else
    // Not supported on Windows yet
    return HW_ACCELERATOR_SUPPORT_ERR;
#endif

    return result;
}
