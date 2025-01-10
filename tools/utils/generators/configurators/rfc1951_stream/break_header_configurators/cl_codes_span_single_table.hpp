/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_CL_CODES_SPAN_SINGLE_TABLE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_CL_CODES_SPAN_SINGLE_TABLE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class StradingCodeLengthCodesConfigurator : public TestConfigurator {
public:
    StradingCodeLengthCodesConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    StradingCodeLengthCodesConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_CL_CODES_SPAN_SINGLE_TABLE_HPP
