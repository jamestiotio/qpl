/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "unallowable_ll_code.hpp"

/**
 * @brief Generate stream where literal is more 285 and uses reserved symbols 286 and 287
 * @return
 */
GenStatus gz_generator::UnallowableLiteralLengthCodeConfigurator::generate() {
    Gen32u            literalsEncoded = 0;
    qpl::test::random randomUndefinedLiteral(286, 287, get_m_seed());

    qpl::test::random tmp = update_range_m_randomTokenCount(1, 50);

    TestConfigurator::declareFixedBlock();

    if (0.9F > static_cast<float>(get_m_random())) {
        literalsEncoded = TestConfigurator::writeRandomReferenceSequence(static_cast<Gen32u>(tmp));
    }
    TestConfigurator::declareLiteral(static_cast<Gen32u>(randomUndefinedLiteral));
    literalsEncoded += 1;

    if (0.9F > static_cast<float>(get_m_random())) {
        TestConfigurator::writeRandomReferenceSequence(static_cast<Gen32u>(tmp), literalsEncoded);
    }

    TestConfigurator::writeRandomHuffmanBlock();
    TestConfigurator::declareFinishBlock();
    return GEN_OK;
}
