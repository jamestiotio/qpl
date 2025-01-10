/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_UTILS_GENERATORS_DEFLATE_GENERATOR_INCLUDE_MYINTRIN_H
#define QPL_TOOLS_UTILS_GENERATORS_DEFLATE_GENERATOR_INCLUDE_MYINTRIN_H

#ifdef WIN32
#include <intrin.h>
static int bsr(int val) {
    unsigned long int result;
    if (val == 0) return 0;
    _BitScanReverse(&result, val);
    return result;
}
static int bsf(int val) {
    unsigned long int result;
    if (val == 0) return 0;
    _BitScanForward(&result, val);
    return result;
}
#else
// assume LINUX
static int bsr(int val) {
    if (val == 0) return 0;
    return (31 - __builtin_clz(val));
}
static int bsf(int val) {
    if (val == 0) return 0;
    return (__builtin_ctz(val));
}
#endif

#endif //QPL_TOOLS_UTILS_GENERATORS_DEFLATE_GENERATOR_INCLUDE_MYINTRIN_H
