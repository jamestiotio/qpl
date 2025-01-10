/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_BIG_REPEAT_COUNT_LL_CODES_H
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_BIG_REPEAT_COUNT_LL_CODES_H

#include "base_configurator.hpp"

namespace gz_generator {
class BigRepeatCountLiteralLengthCodesConfigurator : public TestConfigurator {
public:
    BigRepeatCountLiteralLengthCodesConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    BigRepeatCountLiteralLengthCodesConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_BIG_REPEAT_COUNT_LL_CODES_H
