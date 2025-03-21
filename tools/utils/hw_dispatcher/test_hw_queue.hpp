/*******************************************************************************
 * Copyright (C) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_HW_DISPATCHER_TEST_HW_QUEUE_HPP
#define QPL_TOOLS_UTILS_HW_DISPATCHER_TEST_HW_QUEUE_HPP

#if defined(__linux__)

#include <array>
#include <atomic>

#include "test_hw_configuration_driver.h"
#include "test_hw_status.h"

// DEFINITIONS
#define QPL_TEST_TOTAL_OP_CFG_BIT_GROUPS 8U /**< 256 bits / 32 bit groups */

namespace qpl::test {

/**
 * This hw_queue class is just used to query and receive properties from libaccel-config 
 * for the purpose of enabling tests to be dependent on different configurations.
 * It doesn't provide the functionality of submission of descriptors
 */
class hw_queue {
public:
    using descriptor_t = void;

    using op_config_register_t = std::array<uint32_t, QPL_TEST_TOTAL_OP_CFG_BIT_GROUPS>;

    hw_queue() noexcept = default;

    hw_queue(const hw_queue&) noexcept = delete;

    auto operator=(const hw_queue& other) noexcept -> hw_queue& = delete;

    hw_queue(hw_queue&& other) noexcept = default;

    auto operator=(hw_queue&& other) noexcept -> hw_queue& = default;

    auto initialize_new_queue(descriptor_t* wq_descriptor_ptr) noexcept -> qpl_test_hw_accelerator_status;

    [[nodiscard]] auto priority() const noexcept -> int32_t;

    [[nodiscard]] auto get_op_configuration_support() const noexcept -> bool;

    [[nodiscard]] auto get_op_config_register() const noexcept -> op_config_register_t;

    [[nodiscard]] auto get_size() const noexcept -> uint64_t;

    [[nodiscard]] auto get_transfer_size() const noexcept -> uint64_t;

    virtual ~hw_queue() noexcept = default;

private:
    int32_t              priority_        = 0U;
    bool                 op_cfg_enabled_  = false;
    op_config_register_t op_cfg_register_ = {}; /**< OPCFG register content */
    uint64_t             size_            = 0U; /**< Size of queue */
    uint64_t             transfer_size_   = 0U; /**< Transfer size for WQ */
};

} // namespace qpl::test

#endif //__linux__
#endif //QPL_TOOLS_UTILS_HW_DISPATCHER_TEST_HW_QUEUE_HPP
