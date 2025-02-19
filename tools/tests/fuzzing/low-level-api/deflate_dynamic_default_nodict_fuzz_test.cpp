/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#include "deflate_nodict_fuzz_test.hpp"

#ifndef QPL_EXECUTION_PATH
#define QPL_EXECUTION_PATH qpl_path_software
#endif

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {
    return deflate_nodict_fuzz(Data, Size, QPL_FLAG_DYNAMIC_HUFFMAN, qpl_default_level, QPL_EXECUTION_PATH);
}
