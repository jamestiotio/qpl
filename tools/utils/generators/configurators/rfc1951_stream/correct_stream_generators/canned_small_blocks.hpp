/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_SMALL_BLOCKS_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_SMALL_BLOCKS_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class CannedSmallBlocksConfigurator : public TestConfigurator {
public:
    CannedSmallBlocksConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    CannedSmallBlocksConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_SMALL_BLOCKS_HPP
