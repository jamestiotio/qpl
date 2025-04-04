/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "unallowable_d_code.hpp"

GenStatus gz_generator::UnallowableDistanceCodeConfigurator::generate() {
    Gen32u match           = 0U;
    Gen32u offset          = 0U;
    Gen32u literalsEncoded = 0U;

    qpl::test::random tmp = update_range_m_randomTokenCount(1U, 50U);

    TestConfigurator::declareFixedBlock();
    if (0.9F > static_cast<float>(get_m_random())) {
        literalsEncoded = TestConfigurator::writeRandomReferenceSequence(static_cast<Gen32u>(tmp));
    }

    match = static_cast<Gen32u>(
            update_range_m_randomMatch(MIN_MATCH, GEN_MIN(GEN_MAX(literalsEncoded, MIN_MATCH), MAX_MATCH)));
    offset = DEFAULT_MAX_OFFSET + static_cast<Gen32u>(update_range_m_randomOffset(30U, 31U));
    literalsEncoded += match;

    TestConfigurator::declareReference(match, offset);

    if (0.9F > static_cast<float>(get_m_random())) {
        TestConfigurator::writeRandomReferenceSequence(static_cast<Gen32u>(tmp), literalsEncoded);
    }

    TestConfigurator::writeRandomHuffmanBlock();
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
