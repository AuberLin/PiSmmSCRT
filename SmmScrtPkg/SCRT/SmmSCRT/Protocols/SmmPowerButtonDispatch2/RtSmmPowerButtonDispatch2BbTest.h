/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmPowerButtonDispatch2BbTest.h

Abstract:

  Runtime SmmPowerButtonDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_POWERBUTTONDISPATCH2_BB_TEST_H_
#define _RT_SMM_POWERBUTTONDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_POWER_BUTTON_DISPATCH2_BB_TEST_GUID          \
{ 0x23c88c6, 0xf8a6, 0x4370, { 0x9b, 0x43, 0xf5, 0x83, 0x66, 0x34, 0x72, 0x11 } }


#define EFI_TEST_SMM_POWER_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0xb166c0a0, 0x9b4c, 0x4f66, 0x92, 0x3f, 0x3f, 0xe7, 0x4e, 0xfb, 0xa7, 0x1c }

#define EFI_TEST_SMM_POWER_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0x670606df, 0x896d, 0x49b7, 0x97, 0x53, 0x30, 0x24, 0xb2, 0x74, 0x46, 0xcc }

#define EFI_TEST_SMM_POWER_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x466cef09, 0x2b89, 0x42cf, 0x8b, 0xaf, 0x28, 0x68, 0x60, 0xde, 0xde, 0xb9 }

#define EFI_TEST_SMM_POWER_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0xd6236ba3, 0xf176, 0x4042, 0xa6, 0x95, 0x3b, 0x1c, 0x9a, 0x9f, 0xb8, 0xd7 }

#define EFI_TEST_SMM_POWER_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x17b7195f, 0x4fd3, 0x4994, 0xb5, 0xe9, 0xf6, 0x21, 0x37, 0xdb, 0xe7, 0x32 }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmPowerButtonDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
