/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "bad_stored_length.hpp"

GenStatus gz_generator::BadStoredLengthConfigurator::generate() {
    Gen32u            testGroup = 0U;
    qpl::test::random randomTestGroup;

    TestConfigurator::declareStoredBlock();

    qpl::test::random tmp;

    if (static_cast<float>(get_m_random()) < 0.67F) {
        tmp = update_range_m_randomTokenCount(0U, 32U);
    } else {
        tmp = update_range_m_randomTokenCount(0U, 0xFFFF);
    }

    TestConfigurator::writeRandomLiteralSequence((Gen32u)tmp);

    if (static_cast<float>(get_m_random()) < 0.5F) {
        randomTestGroup.set_range(0U, 15U);
        testGroup = 1U << static_cast<Gen32u>(randomTestGroup);
    } else {
        randomTestGroup.set_range(0U, 0xFFFFU);
        testGroup = static_cast<Gen32u>(randomTestGroup);
    }

    TestConfigurator::declareTestToken(8U, testGroup);

    TestConfigurator::writeRandomHuffmanBlock();
    TestConfigurator::declareFinishBlock();

    return GEN_OK;
}
