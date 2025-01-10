/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_LL_CODES_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_LL_CODES_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class ManyLiteralLengthCodesConfigurator : public TestConfigurator {
public:
    ManyLiteralLengthCodesConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    ManyLiteralLengthCodesConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_MANY_LL_CODES_HPP
