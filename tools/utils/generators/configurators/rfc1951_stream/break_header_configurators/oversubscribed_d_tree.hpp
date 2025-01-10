/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_OVERSUBSCRIBED_D_TREE_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_OVERSUBSCRIBED_D_TREE_HPP

#include "base_configurator.hpp"

namespace gz_generator {
class OversubscribedDistanceTreeConfigurator : public TestConfigurator {
public:
    OversubscribedDistanceTreeConfigurator(Gen32u seed) : TestConfigurator(seed) {}

    OversubscribedDistanceTreeConfigurator() = delete;

    GenStatus generate() override;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_RFC1951_STREAM_BREAK_HEADER_CONFIGURATORS_OVERSUBSCRIBED_D_TREE_HPP
