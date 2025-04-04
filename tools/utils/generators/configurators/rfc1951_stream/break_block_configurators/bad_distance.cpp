/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "bad_distance.hpp"

GenStatus gz_generator::BadDistanceConfigurator::generate() {
    Gen32u offset          = 0U;
    Gen32u match           = 0U;
    Gen32u literalsEncoded = 0U;

    declareRandomHuffmanBlock();

    literalsEncoded = TestConfigurator::writeRandomReferenceSequence(DEFAULT_MAX_OFFSET + 1U, literalsEncoded,
                                                                     DEFAULT_MAX_OFFSET + 1U);

    if (0.5F > static_cast<float>(get_m_random())) {
        offset = MAX_OFFSET + static_cast<Gen32u>(update_range_m_randomOffset(1U, 16U));
    } else {
        offset = static_cast<Gen32u>(update_range_m_randomOffset(MAX_OFFSET + 1U, DEFAULT_MAX_OFFSET));
    }

    match = static_cast<Gen32u>(update_range_m_randomMatch(MIN_MATCH, GEN_MIN(literalsEncoded, MAX_MATCH)));

    TestConfigurator::declareReference(match, offset);

    TestConfigurator::writeRandomHuffmanBlock();
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
