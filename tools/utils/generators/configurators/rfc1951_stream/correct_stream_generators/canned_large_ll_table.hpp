/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_LARGE_LL_TABLE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_LARGE_LL_TABLE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class CannedLargeLiteralLengthTableConfigurator : public TestConfigurator {
public:
    CannedLargeLiteralLengthTableConfigurator(Gen32u seed) : TestConfigurator(seed) {} // need to redesign base class

    CannedLargeLiteralLengthTableConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_CANNED_LARGE_LL_TABLE_HPP
