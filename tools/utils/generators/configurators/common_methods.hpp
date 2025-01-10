/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_COMMON_METHODS_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_COMMON_METHODS_HPP

#include "gendefs.hpp"

namespace gz_generator {
class CommonMethods {
public:
    static Gen8u  bsr_32(Gen32u number);
    static void   shuffle_32u(Gen32u* vector_ptr, Gen32u vectorLength, Gen32u seed);
    static Gen32u pick(Gen32u* vector_ptr, Gen32u vectorLength, Gen32u seed);
    static Gen32u code2Match(Gen32u code, Gen32u seed);
};
} // namespace gz_generator
#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_COMMON_METHODS_HPP
