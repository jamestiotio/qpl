/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_DISTANCE_BEFORE_START_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_DISTANCE_BEFORE_START_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class DistanceCodeBeforeStartConfigurator : public TestConfigurator {
public:
    DistanceCodeBeforeStartConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    DistanceCodeBeforeStartConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_DISTANCE_BEFORE_START_HPP
