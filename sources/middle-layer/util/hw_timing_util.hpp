/*******************************************************************************
 * Copyright (C) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_TIMING_UTIL_HPP
#define QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_TIMING_UTIL_HPP

#include <chrono>
#include <cstdint>
#include <limits>

#include "hw_definitions.h"

// middle-layer
#include "analytics/analytics_defs.hpp"
#include "compression/compression_defs.hpp"
#include "other/other_defs.hpp"

namespace qpl::ml::util {

struct execution_record_ext_t {
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time_;
    double                                                      elapsed_time_ = 0.0;
    uint32_t                                                    wq_idx_       = UINT32_MAX;
    uint32_t                                                    device_idx_   = UINT32_MAX;
};

/**
 * Record end_time to the execution_record
 * @todo Possibly change to += operator to account for multi-descriptor operations.
*/
inline void record_end_time(execution_record_ext_t* record) {
    if (record) {
        record->end_time_     = std::chrono::high_resolution_clock::now();
        record->elapsed_time_ = std::chrono::duration<double>(record->end_time_ - record->start_time_).count();
    }
}

/**
 * Record start_time to the execution_record
 */
inline void record_start_time(execution_record_ext_t* record) {
    if (record) { record->start_time_ = std::chrono::high_resolution_clock::now(); }
}

/**
 * Record wq_idx to the execution_record
 */
inline void record_wq_idx(execution_record_ext_t* record, uint32_t wq_idx) {
    if (record) { record->wq_idx_ = wq_idx; }
}

/**
 * Record device_idx to the execution_record
 */
inline void record_device_idx(execution_record_ext_t* record, uint32_t device_idx) {
    if (record) { record->device_idx_ = device_idx; }
}

template <class return_t>
inline void store_execution_record_to_result(execution_record_ext_t* exec_record, return_t& result) noexcept;

template <>
inline void store_execution_record_to_result<uint32_t>(execution_record_ext_t* exec_record, uint32_t& result) noexcept {
    (void)exec_record;
    (void)result;
}

template <>
inline void store_execution_record_to_result<analytics::analytic_operation_result_t>(
        execution_record_ext_t* exec_record, analytics::analytic_operation_result_t& result) noexcept {
    (void)exec_record;
    (void)result;
}

template <>
inline void
store_execution_record_to_result<other::crc_operation_result_t>(execution_record_ext_t*        exec_record,
                                                                other::crc_operation_result_t& result) noexcept {
    (void)exec_record;
    (void)result;
}

template <>
inline void store_execution_record_to_result<compression::verification_pass_result_t>(
        execution_record_ext_t* exec_record, compression::verification_pass_result_t& result) noexcept {
    (void)exec_record;
    (void)result;
}

template <>
inline void store_execution_record_to_result<compression::decompression_operation_result_t>(
        execution_record_ext_t* exec_record, compression::decompression_operation_result_t& result) noexcept {
    result.record_.elapsed_time_ = exec_record->elapsed_time_;
    result.record_.wq_idx_       = exec_record->wq_idx_;
    result.record_.device_idx_   = exec_record->device_idx_;
}

template <>
inline void store_execution_record_to_result<compression::compression_operation_result_t>(
        execution_record_ext_t* exec_record, compression::compression_operation_result_t& result) noexcept {
    result.record_.elapsed_time_ = exec_record->elapsed_time_;
    result.record_.wq_idx_       = exec_record->wq_idx_;
    result.record_.device_idx_   = exec_record->device_idx_;
}

} // namespace qpl::ml::util

#endif //QPL_SOURCES_MIDDLE_LAYER_UTIL_HW_TIMING_UTIL_HPP
