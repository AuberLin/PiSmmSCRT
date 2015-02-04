/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmIoTrapDispatch2BbTest.h

Abstract:

  Runtime SmmIoTrapDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_IOTRAPDISPATCH2_BB_TEST_H_
#define _RT_SMM_IOTRAPDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_IO_TRAP_DISPATCH2_BB_TEST_GUID          \
{ 0xe37f5b89, 0x64c0, 0x4bbc, { 0x8a, 0x80, 0x37, 0x3e, 0xd7, 0xda, 0x43, 0x29 } }


#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0xfa144cff, 0xbee4, 0x437d, 0xa2, 0xbb, 0xf7, 0x48, 0x75, 0xd8, 0xc4, 0x8e }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0xfacfd632, 0x3ec4, 0x47cd, 0xb2, 0x2a, 0x6e, 0x51, 0x90, 0x72, 0xed, 0xd8 }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x7d47a17b, 0xb793, 0x4bce, 0x8a, 0x79, 0x9e, 0xb5, 0x4a, 0xad, 0x13, 0x3d }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0x39719dbf, 0xb677, 0x412c, 0xaa, 0x62, 0x99, 0xde, 0xc9, 0xa4, 0xee, 0x1c }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x4a6592f1, 0xcb3c, 0x4cb3, 0xbd, 0xd8, 0xab, 0xa6, 0xc3, 0xa7, 0xcb, 0xbf }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_006_GUID \
{ 0x26b96031, 0x66ca, 0x4d77, 0xad, 0x93, 0xa5, 0x33, 0xab, 0x50, 0x33, 0x8 }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_007_GUID \
{ 0x68893942, 0x38d7, 0x43f6, 0x97, 0x27, 0x89, 0x7, 0xac, 0x2d, 0x58, 0xa6 }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_008_GUID \
{ 0xe88f79c5, 0x6c7f, 0x4f2c, 0x9a, 0x85, 0xb7, 0x51, 0xe4, 0xfa, 0xbb, 0x25 }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_009_GUID \
{ 0x67df1860, 0xf18a, 0x4943, 0x8c, 0x42, 0xd8, 0x60, 0xee, 0xba, 0xab, 0x5d }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_010_GUID \
{ 0xae006844, 0xbcca, 0x4a5e, 0xb7, 0x48, 0x19, 0xf7, 0xba, 0xef, 0x1c, 0xaa }

#define EFI_TEST_SMM_IO_TRAP_DISPATCH2_BBTEST_REQUIRED_ASSERTION_011_GUID \
{ 0x838fb99d, 0xf050, 0x463e, 0x94, 0x9a, 0x4f, 0x8b, 0x30, 0x91, 0x55, 0x3c }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmIoTrapDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
