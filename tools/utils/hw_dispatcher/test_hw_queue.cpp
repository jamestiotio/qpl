/*******************************************************************************
 * Copyright (C) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#if defined(__linux__)

#include "test_hw_queue.hpp"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define QPL_TEST_HWSTS_RET(expr, err_code) \
    {                                      \
        if (expr) { return (err_code); }   \
    }

namespace qpl::test {

auto hw_queue::initialize_new_queue(void* wq_descriptor_ptr) noexcept -> qpl_test_hw_accelerator_status {

    auto* work_queue_ptr = reinterpret_cast<accfg_wq*>(wq_descriptor_ptr);
    char  path[64];

    if (ACCFG_WQ_ENABLED != qpl_test_accfg_wq_get_state(work_queue_ptr)) {
        return QPL_TEST_HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE;
    }

    if (ACCFG_WQ_SHARED != qpl_test_accfg_wq_get_mode(work_queue_ptr)) {
        return QPL_TEST_HW_ACCELERATOR_WORK_QUEUES_NOT_AVAILABLE;
    }

    auto status = qpl_test_accfg_wq_get_user_dev_path(work_queue_ptr, path, 64 - 1);
    QPL_TEST_HWSTS_RET((0 > status), QPL_TEST_HW_ACCELERATOR_LIBACCEL_ERROR);

    priority_ = qpl_test_accfg_wq_get_priority(work_queue_ptr);
    size_     = qpl_test_accfg_wq_get_size(work_queue_ptr);

    accfg_op_config op_cfg;
    const int32_t   get_op_cfg_status = qpl_test_accfg_wq_get_op_config(work_queue_ptr, &op_cfg);
    if (get_op_cfg_status) {
        op_cfg_enabled_ = false;
    } else {
        for (uint8_t bit_group_index = 0; bit_group_index < QPL_TEST_TOTAL_OP_CFG_BIT_GROUPS; bit_group_index++) {
            op_cfg_register_[bit_group_index] = op_cfg.bits[bit_group_index];
        }
        op_cfg_enabled_ = true;
    }

    transfer_size_ = qpl_test_accfg_wq_get_max_transfer_size(work_queue_ptr);

    return QPL_TEST_HW_ACCELERATOR_STATUS_OK;
}

auto hw_queue::priority() const noexcept -> int32_t {
    return priority_;
}

auto hw_queue::get_op_configuration_support() const noexcept -> bool {
    return op_cfg_enabled_;
}

auto hw_queue::get_op_config_register() const noexcept -> op_config_register_t {
    return op_cfg_register_;
}

auto hw_queue::get_size() const noexcept -> uint64_t {
    return size_;
}

auto hw_queue::get_transfer_size() const noexcept -> uint64_t {
    return transfer_size_;
}

} // namespace qpl::test
#endif //__linux__
