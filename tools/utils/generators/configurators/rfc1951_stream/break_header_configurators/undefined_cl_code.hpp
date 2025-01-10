/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_UNDEFINED_CL_CODE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_UNDEFINED_CL_CODE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class UndefinedCodeLengthCodeConfigurator : public TestConfigurator {
public:
    UndefinedCodeLengthCodeConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    UndefinedCodeLengthCodeConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_UNDEFINED_CL_CODE_HPP
