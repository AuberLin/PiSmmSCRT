/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmSwDispatch2BbTest.h

Abstract:

  Runtime SmmSwDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_SWDISPATCH2_BB_TEST_H_
#define _RT_SMM_SWDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_SWDISPATCH2_BB_TEST_GUID          \
{ 0xf74574e3, 0xe271, 0x4b95, { 0x95, 0xba, 0x45, 0x3c, 0xda, 0x30, 0x68, 0xfe } }


#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x91ee43b0, 0x5e47, 0x4832, 0x95, 0x42, 0xee, 0x75, 0x3d, 0x4d, 0x55, 0xa }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0xdbe6a67f, 0x3afd, 0x4e8b, 0x99, 0xdd, 0x4f, 0xb5, 0x13, 0x8e, 0x62, 0xf2 }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x89c717a2, 0xbb98, 0x4e8a, 0xa8, 0xe9, 0x4e, 0x38, 0xee, 0xad, 0xf2, 0x6c }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0x1ae5ca58, 0xa7e7, 0x4611, 0x87, 0x12, 0x31, 0xb4, 0x92, 0x1e, 0x83, 0x1c }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x4ec680e1, 0x3012, 0x42cd, 0x82, 0xdc, 0x19, 0x5, 0x6d, 0x70, 0xed, 0x7b }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_006_GUID \
{ 0xb365a425, 0xb42a, 0x4c3a, 0xad, 0x38, 0xd, 0x84, 0x81, 0xdf, 0xce, 0xa4 }

#define EFI_TEST_SMMSWDISPATCH2BBTEST_REQUIRED_ASSERTION_007_GUID \
{ 0xa470e7d9, 0xb52d, 0x4c23, 0x8b, 0xe6, 0xe9, 0x21, 0xb6, 0x88, 0xdf, 0x90 }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmSwDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
