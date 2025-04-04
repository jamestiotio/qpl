/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "fixed_block_no_err.hpp"

GenStatus gz_generator::FixedBlockNoErrorConfigurator::generate() {
    TestConfigurator::declareFixedBlock();
    TestConfigurator::writeRandomReferenceSequence(static_cast<Gen8u>(update_range_m_randomTokenCount(5000U, 10000U)));
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
