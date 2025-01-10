/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_DISTANCE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_DISTANCE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class BadDistanceConfigurator : public TestConfigurator {
public:
    BadDistanceConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    BadDistanceConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator
#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_DISTANCE_HPP
