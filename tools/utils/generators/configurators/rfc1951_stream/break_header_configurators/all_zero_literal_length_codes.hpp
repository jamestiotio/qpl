/*******************************************************************************
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_ALL_ZERO_LITERAL_LENGTH_CODES_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_ALL_ZERO_LITERAL_LENGTH_CODES_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class AllZeroLiteralLengthCodesConfigurator : public TestConfigurator {
    // Not a seed dependent test, but here for consistency with other tests
public:
    AllZeroLiteralLengthCodesConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    AllZeroLiteralLengthCodesConfigurator() = delete;

    GenStatus generate() override;
};

} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_ALL_ZERO_LITERAL_LENGTH_CODES_HPP
