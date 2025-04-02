/*******************************************************************************
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************/

#ifndef QPL_SOURCES_ISAL_IGZIP_IGZIP_CHECKSUMS_H
#define QPL_SOURCES_ISAL_IGZIP_IGZIP_CHECKSUMS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ADLER_BUF (1 << 28)
#define ADLER_MOD     65521

uint32_t qpl_isal_adler32(uint32_t init_crc, const unsigned char* buf, //NOLINT(readability-redundant-declaration)
                          uint64_t len);
uint32_t qpl_isal_adler32_bam1(uint32_t init_crc, const unsigned char* buf, uint64_t len);

#ifdef __cplusplus
}
#endif
#endif //QPL_SOURCES_ISAL_IGZIP_IGZIP_CHECKSUMS_H
