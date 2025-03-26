/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_BENCHMARKS_INCLUDE_DETAILS_MEASURE_SYNC_HPP
#define QPL_TOOLS_BENCHMARKS_INCLUDE_DETAILS_MEASURE_SYNC_HPP

#include <benchmark/benchmark.h>
#include <ops/ops.hpp>
#include <stdexcept>
#include <utility.hpp>

namespace bench::details {
template <path_e path, typename OperationT, typename ParamsT>
static statistics_t measure_sync(benchmark::State& state, const case_params_t& common_params, OperationT& operations,
                                 ParamsT& params) {
    statistics_t res;
    if constexpr (path == path_e::cpu) {
        res.queue_size = 1;
        res.operations = 1;
    } else {
        res.queue_size = common_params.queue_size_;
        res.operations = res.queue_size;
    }

    if (res.queue_size != 1 && common_params.use_sync_api_) {
        throw std::runtime_error("Using --sync_api for measurements do not support queue size > 1");
    }
    if (!common_params.use_sync_api_ && common_params.report_accel_time_) {
        throw std::runtime_error("Reporting accelerator time requires --sync_api");
    }

    res.operations_per_thread = res.operations;
    if (state.threads() > 1) throw std::runtime_error("Synchronous measurements do not support threading");

    operations.resize(res.queue_size);
    for (auto& operation : operations) {
        operation.init(params, common_params.node_, get_mem_cc(common_params.out_mem_), common_params.full_time_);
        operation.mem_control(common_params.in_mem_, mem_loc_mask_e::src);
    }

    // Non-timed warm-up
    for (auto& operation : operations) {
        if (common_params.use_sync_api_) {
            operation.sync_execute();
        } else {
            operation.async_submit();
            operation.async_wait();
        }
        operation.light_reset();
    }

    // Timed measurements
    for (auto _ : state) {
        if (common_params.use_sync_api_) {
            for (auto& operation : operations) {
                operation.sync_execute();
                operation.light_reset();

                res.completed_operations++;
                res.data_read += operation.get_bytes_read();
                res.data_written += operation.get_bytes_written();
                res.elapsed_iaa_time = operation.get_elapsed_time();
            }
        } else {
            for (auto& operation : operations) {
                operation.async_submit();
            }
            for (auto& operation : operations) {
                operation.async_wait();
                operation.light_reset();

                res.completed_operations++;
                res.data_read += operation.get_bytes_read();
                res.data_written += operation.get_bytes_written();
            }
        }
    }

    return res;
}
} // namespace bench::details
#endif // QPL_TOOLS_BENCHMARKS_INCLUDE_DETAILS_MEASURE_SYNC_HPP
