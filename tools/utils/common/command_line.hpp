/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

/*
 *  Intel® Query Processing Library (Intel® QPL)
 *  Tests
 */

#ifndef QPL_TOOLS_UTILS_COMMON_COMMAND_LINE_HPP
#define QPL_TOOLS_UTILS_COMMON_COMMAND_LINE_HPP

#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <variant>

namespace qpl::test {
class CommandLine {
public:
    CommandLine(char** arguments_pptr, int arguments_count);

    template <class type>
    auto find(const std::string& parameter_name) -> std::optional<type>;

private:
    using argument_t = std::variant<bool, int, std::string>;

    std::map<std::string, argument_t> parsed_arguments_;

    static argument_t convertType(const std::string& parsed_argument);
};
} // namespace qpl::test
#endif //QPL_TOOLS_UTILS_COMMON_COMMAND_LINE_HPP
