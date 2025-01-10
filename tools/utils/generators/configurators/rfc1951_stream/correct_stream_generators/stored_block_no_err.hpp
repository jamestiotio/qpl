/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_STORED_BLOCK_NO_ERR_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_STORED_BLOCK_NO_ERR_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class StoredBlockNoErrorConfigurator : public TestConfigurator {
public:
    StoredBlockNoErrorConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    StoredBlockNoErrorConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_CORRECT_STREAM_GENERATORS_STORED_BLOCK_NO_ERR_HPP
