/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_DYNAMIC_BLOCK_NO_ERR_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_DYNAMIC_BLOCK_NO_ERR_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class DynamicBlockNoErrorConfigurator : public TestConfigurator {
public:
    DynamicBlockNoErrorConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    DynamicBlockNoErrorConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_DYNAMIC_BLOCK_NO_ERR_HPP
