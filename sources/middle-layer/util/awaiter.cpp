/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "awaiter.hpp"

#include <chrono>

#include "hw_status.h"

#if defined(__linux__)
#include <x86intrin.h>
#else
#include <emmintrin.h>
#include <intrin.h>
#endif

namespace qpl::ml {

#if defined(HAVE_CXX_KNOWS_WAITPKG) || defined(QPL_EFFICIENT_WAIT)
#if defined(__linux__)
__attribute__((target("waitpkg")))
#endif
void wait_for(volatile uint8_t* address, uint8_t initial_value) {
    const auto start_time = std::chrono::high_resolution_clock::now();
    double     age        = 0.0;

    while ((initial_value == *address) && (age < QPL_AWAITER_TIMEOUT_SECONDS)) {
        _mm_pause();
        auto future_wait_to = __rdtsc() + QPL_AWAITER_PERIOD_CYCLES;
        _umonitor(const_cast<uint8_t*>(address)); // Technically casting off volatile is undefined but the unlikely
                                                  // side effect of non-volatile would be only lack of an optimization.
        _umwait(0, future_wait_to);
        auto sample_time = std::chrono::high_resolution_clock::now();
        age              = std::chrono::duration<double>(sample_time - start_time).count();
    }

    if ((initial_value == *address) && (age > QPL_AWAITER_TIMEOUT_SECONDS)) *address = AD_ERROR_CODE_TIMEOUT;
}
#endif

#if defined(HAVE_CXX_KNOWS_WAITPKG) || !defined(QPL_EFFICIENT_WAIT)
#if defined(__linux__)
__attribute__((target("default")))
#endif
void wait_for(volatile uint8_t* address, uint8_t initial_value) {
    const auto start_time = std::chrono::high_resolution_clock::now();
    double     age        = 0.0;

    while ((initial_value == *address) && (age < QPL_AWAITER_TIMEOUT_SECONDS)) {
        _mm_pause();
        auto sample_time = std::chrono::high_resolution_clock::now();
        age              = std::chrono::duration<double>(sample_time - start_time).count();
    }

    if ((initial_value == *address) && (age > QPL_AWAITER_TIMEOUT_SECONDS)) *address = AD_ERROR_CODE_TIMEOUT;
}
#endif

} // namespace qpl::ml
