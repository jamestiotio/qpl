/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_FIRST_LL_16_CODE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_FIRST_LL_16_CODE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class FirstLiteralLengthCode16Configurator : public TestConfigurator {
public:
    FirstLiteralLengthCode16Configurator(Gen32u seed) : TestConfigurator(seed) {}

    FirstLiteralLengthCode16Configurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_FIRST_LL_16_CODE_HPP
