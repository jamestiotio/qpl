/*******************************************************************************
 * Copyright (C) 2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_TOOLS_UTILS_COMMON_EXCEPTION_HANDLER_HPP
#define QPL_TOOLS_UTILS_COMMON_EXCEPTION_HANDLER_HPP

#include <exception>
#include <iostream>

namespace qpl::test {

inline int exception_handler() {
    try {
        throw;
    } catch (const std::exception& std_exception) {
        std::cout << "std::exception was caught: " << std_exception.what() << "\n";
        return -2;
    } catch (...) {
        std::cout << "An unrecognized exception was caught!\n";
        return -1;
    }
    return 0;
}

} // namespace qpl::test

#endif //QPL_TOOLS_UTILS_COMMON_EXCEPTION_HANDLER_HPP
