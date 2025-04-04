/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_C_API_BASE_HPP
#define QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_C_API_BASE_HPP

#include <memory.h>
#include <ops/base.hpp>
#include <ops/params.hpp>
#include <ops/results.hpp>
#include <qpl/qpl.h>
#include <stdexcept>
#include <types.hpp>

namespace bench::ops::c_api {
template <path_e path>
static inline qpl_path_t to_qpl_path() {
    if constexpr (path == path_e::cpu)
        return qpl_path_software;
    else if (path == path_e::iaa)
        return qpl_path_hardware;
    else if (path == path_e::auto_)
        return qpl_path_auto;
    else
        throw std::runtime_error("Invalid path conversion!");
}

template <typename DerivedT>
class operation_base_t : public ops::operation_base_t<DerivedT> {
public:
    using base_t = ops::operation_base_t<DerivedT>;

    operation_base_t() noexcept {}
    ~operation_base_t() noexcept {}
    operation_base_t(const operation_base_t& other) {
        base_t::set_cache_control(other.get_cache_control());
        base_t::set_numa_id(other.get_numa_id());
        if (other.job_) { init_lib_impl(); }
    }

    operation_base_t& operator=(const operation_base_t& other) {
        if (this != &other) {
            deinit_lib_impl();
            base_t::set_cache_control(other.get_cache_control());
            base_t::set_numa_id(other.get_numa_id());
            if (other.job_) { init_lib_impl(); }
        }
        return *this;
    }

    operation_base_t(operation_base_t&&)            = delete;
    operation_base_t& operator=(operation_base_t&&) = delete;

    void init_lib_impl() {
        if (!base_t::get_cache_control())
            throw std::runtime_error("manual cache control option is not supported in C API");

        std::uint32_t size   = 0U;
        auto          status = qpl_get_job_size(to_qpl_path<DerivedT::path_v>(), &size);
        if (QPL_STS_OK != status) throw std::runtime_error(format("qpl_get_job_size() failed with status %d", status));

        job_ = (qpl_job*)malloc(size); //NOLINT(cppcoreguidelines-no-malloc)
        if (!job_) throw std::runtime_error("malloc() failed");

        status = qpl_init_job(to_qpl_path<DerivedT::path_v>(), job_);
        if (QPL_STS_OK != status) {
            free(job_); //NOLINT(cppcoreguidelines-no-malloc)
            job_ = nullptr;
            throw std::runtime_error(format("qpl_init_job() failed with status %d", status));
        }
        job_->numa_id = base_t::get_numa_id();
    }

    void deinit_lib_impl() {
        if (job_) {
            auto status = qpl_fini_job(job_);
            free(job_); //NOLINT(cppcoreguidelines-no-malloc)
            job_ = nullptr;
            if (QPL_STS_OK != status) throw std::runtime_error(format("qpl_fini_job() failed with status %d", status));
        }
    }

protected:
    friend class ops::operation_base_t<DerivedT>;

    qpl_job* job_ {nullptr}; //NOLINT(misc-non-private-member-variables-in-classes)
};
} // namespace bench::ops::c_api

extern "C" {
typedef enum {
    QPL_EXECUTION_INFO_ELAPSED_TIME = 0,
    QPL_EXECUTION_INFO_WQ_IDX,
    QPL_EXECUTION_INFO_DEVICE_IDX
} qpl_execution_info_t;

extern qpl_status qpl_get_execution_record(const qpl_job* const job_ptr, qpl_execution_info_t info_type,
                                           void* info_value);
}

#endif // QPL_TOOLS_BENCHMARKS_INCLUDE_OPS_C_API_BASE_HPP
