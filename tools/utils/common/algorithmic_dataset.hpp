/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/*
 *  Intel® Query Processing Library (Intel® QPL)
 *  Tools
 */

#ifndef QPL_TOOLS_UTILS_COMMON_ALGORITHMIC_DATASET_HPP
#define QPL_TOOLS_UTILS_COMMON_ALGORITHMIC_DATASET_HPP

#include "dataset.hpp"

namespace qpl::tools {
class algorithmic_dataset_t : public dataset_t {
public:
    explicit algorithmic_dataset_t(const std::string& path);
};
} // namespace qpl::tools
#endif //QPL_TOOLS_UTILS_COMMON_ALGORITHMIC_DATASET_HPP
