/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmGpiDispatch2BbTest.h

Abstract:

  Runtime SmmGpiDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_GPIDISPATCH2_BB_TEST_H_
#define _RT_SMM_GPIDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_GPIDISPATCH2_BB_TEST_GUID          \
{ 0xfedd5314, 0x9362, 0x407e, { 0x9d, 0x3a, 0x3b, 0x65, 0x2a, 0x64, 0xeb, 0x9b } }

#define EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x13612059, 0x95e0, 0x41f5, 0x9b, 0x29, 0xa2, 0xcd, 0xfe, 0x2d, 0x8a, 0xc8 }

#define EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0x3b680fc7, 0x4a0c, 0x4f62, 0xbc, 0xb2, 0xed, 0xbc, 0x4, 0x34, 0x72, 0xd2 }

#define EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0xec55768f, 0xaf5d, 0x4379, 0xb6, 0xe5, 0xad, 0x60, 0xa3, 0x9e, 0x12, 0xda }

#define EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0x48cd57d8, 0x1954, 0x4ea9, 0xb5, 0x41, 0x49, 0x6a, 0x3e, 0xa1, 0x7d, 0x17 }

#define EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_005_GUID \
{0x9ebd6805, 0x8642, 0x478e, 0xbc, 0xd8, 0x55, 0xb7, 0x57, 0xbb, 0xd7, 0xff }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmGpiDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
