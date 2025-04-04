/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_BASE_CONFIGURATOR_H
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_BASE_CONFIGURATOR_H

#include <algorithm>
#include <cstdint>
#include <sstream>
#include <vector>

#include "common_methods.hpp"
#include "igenerator.h"
#include "random_generator.h"

namespace gz_generator {
class ITestConfigurator {
public:
    virtual GenStatus                          generate()  = 0;
    virtual std::unique_ptr<std::stringstream> getConfig() = 0;
    ITestConfigurator()                                    = default;
    virtual ~ITestConfigurator()                           = default;

    ITestConfigurator(const ITestConfigurator& other)                    = delete;
    ITestConfigurator(ITestConfigurator&& other)                         = delete;
    auto operator=(const ITestConfigurator& other) -> ITestConfigurator& = delete;
    auto operator=(ITestConfigurator&& other) -> ITestConfigurator&      = delete;
};

static const float        STORED_BLOCK_PROBABILITY  = 0.33F;
static const float        FIXED_BLOCK_PROBABILITY   = 0.25F;
static const float        HUFFMAX_BLOCK_PROBABILITY = 0.5F;
static const unsigned int DEFAULT_TOKEN_COUNT       = 100U;

class TestConfigurator : public ITestConfigurator {
protected:
    enum VectorTokenType : std::uint8_t {
        LL_VECTOR,
        LL_ENCODED_VECTOR,
        D_VECTOR,
        D_ENCODED_VECTOR,
        CL_VECTOR,
        CL_VECTOR_ALT,
        CL_ENCODED_VECTOR,
        L_VECTOR
    };

    std::unique_ptr<std::stringstream> m_config; //NOLINT(misc-non-private-member-variables-in-classes)

    /*TODO ADD COMMON RANDOM + TABLES*/
    /*writers*/
    void writeRandomBlock();
    void writeRandomStoredBlock();
    void writeRandomHuffmanBlock(uint32_t minElementsCount = 0U);
    void writeRandomLiteralSequence(const Gen32u sequenceLength);

    Gen32u writeRandomReferenceSequence(const Gen32u sequenceLength, const Gen32u previouslyLiteralsEncoded = 0U,
                                        const Gen32u encodedLiteralsCountLimit = GEN_MAX_32U);

    /*delegates to ConfigContainerClass*/
    void declareRandomBlock();
    void declareRandomHuffmanBlock();
    void declareFixedBlock();
    void declareInvalidBlock();
    void declareDynamicBlock();
    void declareStoredBlock();
    void declareFinishBlock();

    void declareExtraLengths();
    void declareLiteral(Gen32u literal);
    void declareRandomLiterals(Gen32u count);
    void declareReference(Gen32u match, Gen32u offset);
    void declareTestToken(const Gen32u testNumber);
    void declareTestToken(const Gen32u testNumber, const Gen32u testGroup);
    void declareVectorToken(const VectorTokenType type, const Gen32u* vector, const Gen32u length);

    Gen32u makeRandomLengthCodesTable(Gen32u* pLengthCodeTable, Gen32u lengthTableSize, Gen8u maxLengthCodeValue) const;

public:
    TestConfigurator(Gen32u seed)
        : m_seed(seed)
        , m_random(0U, 1U, m_seed)
        , m_randomOffset(0U, MAX_OFFSET, m_seed)
        , m_randomMatch(MIN_MATCH, MAX_MATCH, m_seed)
        , m_randomLiteralCode(LITERALS_LOW_BORDER, LITERALS_HIGH_BORDER, m_seed)
        , m_randomTokenCount(0U, DEFAULT_TOKEN_COUNT, m_seed) {
        m_config = std::make_unique<std::stringstream>();
    }

    TestConfigurator() = delete;

    std::unique_ptr<std::stringstream> getConfig() override;

    Gen32u            get_m_seed() const { return m_seed; }
    qpl::test::random get_m_random() const { return m_random; }
    qpl::test::random update_range_m_randomOffset(double min, double max) {
        m_randomOffset.set_range(min, max);
        return m_randomOffset;
    }

    qpl::test::random update_range_m_randomMatch(double min, double max) {
        m_randomMatch.set_range(min, max);
        return m_randomMatch;
    }
    qpl::test::random update_range_m_randomLiteralCode(double min, double max) {
        m_randomLiteralCode.set_range(min, max);
        return m_randomLiteralCode;
    }

    qpl::test::random get_m_randomLiteralCode() const { return m_randomLiteralCode; }

    qpl::test::random update_range_m_randomTokenCount(double min, double max) {
        m_randomTokenCount.set_range(min, max);
        return m_randomTokenCount;
    }

    qpl::test::random get_m_randomTokenCount() const { return m_randomTokenCount; }

private:
    Gen32u            m_seed; //Can be used for custom randomizers in generators
    qpl::test::random m_random;
    qpl::test::random m_randomOffset;
    qpl::test::random m_randomLiteralCode;
    qpl::test::random m_randomMatch;
    qpl::test::random m_randomTokenCount;
};
} // namespace gz_generator

#endif //QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_BASE_CONFIGURATOR_H
