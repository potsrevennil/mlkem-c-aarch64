/*
 * Copyright (c) 2024-2025 The mlkem-native project authors
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MLK_FIPS202_NATIVE_X86_64_SRC_XKCP_IMPL_H
#define MLK_FIPS202_NATIVE_X86_64_SRC_XKCP_IMPL_H
/* Default FIPS202 assembly profile for AArch64 systems */

#ifdef MLK_FIPS202_PROFILE_IMPL_H
#error Only one FIPS202 assembly profile can be defined -- did you include multiple profiles?
#else
#define MLK_FIPS202_PROFILE_IMPL_H

#include "../../../../common.h"

#define KeccakP1600times4_PermuteAll_24rounds \
  MLK_NAMESPACE(KeccakP1600times4_PermuteAll_24rounds)
void KeccakP1600times4_PermuteAll_24rounds(void *states);

#define MLK_USE_FIPS202_X4_NATIVE
static MLK_INLINE void keccak_f1600_x4_native(uint64_t *state)
{
  KeccakP1600times4_PermuteAll_24rounds(state);
}

#endif /* MLK_FIPS202_PROFILE_IMPL_H */

#endif /* MLK_FIPS202_NATIVE_X86_64_SRC_XKCP_IMPL_H */
