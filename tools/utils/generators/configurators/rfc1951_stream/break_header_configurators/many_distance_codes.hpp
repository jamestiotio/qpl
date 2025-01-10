/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_DISTANCE_CODES_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_DISTANCE_CODES_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class ManyDistanceCodesConfigurator : public TestConfigurator {
public:
    ManyDistanceCodesConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    ManyDistanceCodesConfigurator() = delete;

    GenStatus generate() override;

    /**
             * return true if given POINT in run of length N is a breakpoint between sequences
             */
    static bool breakInRun(Gen32u a, Gen32u b);
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_DISTANCE_CODES_HPP
