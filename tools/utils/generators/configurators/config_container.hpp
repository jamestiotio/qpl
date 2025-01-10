/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/
#ifndef QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_CONFIG_CONTAINER_HPP
#define QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_CONFIG_CONTAINER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "gendefs.hpp"

namespace gz_generator {
class ConfigContainer {
private:
    std::stringstream m_configuration;

public:
    ConfigContainer()  = default;
    ~ConfigContainer() = default;

    void clean() { m_configuration.str(""); }
    /*each token must begin on the new line!*/

    void declareTestModeToken(Gen32u testMode) { m_configuration << "testmode " << std::to_string(testMode) << '\n'; }

    void declareTestModeToken(Gen32u testMode, Gen32u testGroup) {
        m_configuration << "testmode " << std::to_string(testMode) << " " << std::to_string(testGroup) << '\n';
    }

    void saveConfigToFile(std::string filename) {
        std::ofstream file;
        file.open(filename, std::ofstream::binary);
        file << m_configuration.str();
        file.close();
    }
};
} // namespace gz_generator
#endif // QPL_TOOLS_UTILS_GENERATORS_CONFIGURATORS_CONFIG_CONTAINER_HPP
