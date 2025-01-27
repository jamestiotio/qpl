/*******************************************************************************
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_CORE_SW_DISPATCHER_SIMPLE_MEMORY_OPS_C_BIND_H
#define QPL_SOURCES_CORE_SW_DISPATCHER_SIMPLE_MEMORY_OPS_C_BIND_H

#include <stdint.h>

void call_c_copy_uint8_t(const uint8_t* source, uint8_t* destination, uint32_t length);
void call_c_set_zeros_uint8_t(uint8_t* destination, uint32_t length);

#endif //QPL_SOURCES_CORE_SW_DISPATCHER_SIMPLE_MEMORY_OPS_C_BIND_H
