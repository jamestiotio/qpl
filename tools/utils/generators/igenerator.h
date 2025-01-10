/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_GENERATORS_IGENERATOR_H
#define QPL_TOOLS_UTILS_GENERATORS_IGENERATOR_H

#include <memory>
#include <vector>

#include "gendefs.hpp"

namespace gz_generator {
class InflateGenerator {
protected:
    static std::unique_ptr<std::stringstream> getStreamDescription(TestFactor& testFactor);

public:
    static GenStatus generate(std::vector<Gen8u>& pBinaryData, std::vector<Gen8u>& pReferenceData, TestFactor& factor);
};
} // namespace gz_generator
#endif //QPL_TOOLS_UTILS_GENERATORS_IGENERATOR_H
