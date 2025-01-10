/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_STORED_LENGTH_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_STORED_LENGTH_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class BadStoredLengthConfigurator : public TestConfigurator {
public:
    BadStoredLengthConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    BadStoredLengthConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_BLOCK_CONFIGURATORS_BAD_STORED_LENGTH_HPP
