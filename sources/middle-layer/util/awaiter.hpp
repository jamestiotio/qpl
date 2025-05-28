/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/*
 *  Intel® Query Processing Library (Intel® QPL)
 *  Middle Layer API (private C++ API)
 */

#ifndef QPL_SOURCES_MIDDLE_LAYER_UTIL_AWAITER_HPP
#define QPL_SOURCES_MIDDLE_LAYER_UTIL_AWAITER_HPP

#include <cstdint>

namespace qpl::ml {

#define QPL_AWAITER_PERIOD_CYCLES   2000U
#define QPL_AWAITER_TIMEOUT_SECONDS 8.0

/**
 * @brief Wait function looks for changes in address until timeout time reached
 *
 * @param[in] address         Pointer to memory that should be asynchronously changed
 * @param[in] initial_value   Value to compare with
 *
 * @return none
 */
void wait_for(volatile uint8_t* address, uint8_t initial_value);

} // namespace qpl::ml

#endif //QPL_SOURCES_MIDDLE_LAYER_UTIL_AWAITER_HPP
