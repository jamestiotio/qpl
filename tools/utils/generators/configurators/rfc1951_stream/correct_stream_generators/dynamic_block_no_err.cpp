/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "dynamic_block_no_err.hpp"

GenStatus gz_generator::DynamicBlockNoErrorConfigurator::generate() {
    TestConfigurator::declareDynamicBlock();
    TestConfigurator::writeRandomReferenceSequence(static_cast<Gen8u>(update_range_m_randomTokenCount(5000U, 10000U)));
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
