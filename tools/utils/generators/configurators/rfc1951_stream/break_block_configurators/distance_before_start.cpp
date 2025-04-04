/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "distance_before_start.hpp"

GenStatus gz_generator::DistanceCodeBeforeStartConfigurator::generate() {
    Gen32u offset          = 0;
    Gen32u match           = 0;
    Gen32u literalsEncoded = 0;

    qpl::test::random tmp = update_range_m_randomTokenCount(0U, 32U);
    TestConfigurator::declareRandomHuffmanBlock();

    literalsEncoded = TestConfigurator::writeRandomReferenceSequence(static_cast<Gen32u>(tmp), 0U, 3800U);
    if (0.5F > static_cast<float>(get_m_random())) {
        offset = literalsEncoded + static_cast<Gen32u>(update_range_m_randomOffset(1U, 16U));
    } else {
        offset = static_cast<Gen32u>(update_range_m_randomOffset(literalsEncoded + 1U, 4096U));
    }

    match = static_cast<Gen32u>(update_range_m_randomMatch(MIN_MATCH, GEN_MIN(literalsEncoded, MAX_MATCH)));

    TestConfigurator::declareReference(match, offset);

    TestConfigurator::writeRandomHuffmanBlock();
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
