/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmStdbyButtDispatch2BbTest.h

Abstract:

  Runtime SmmStdbyButtDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_STDBYBUTTONDISPATCH2_BB_TEST_H_
#define _RT_SMM_STDBYBUTTONDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_STANDBY_BUTTON_DISPATCH2_BB_TEST_GUID          \
{ 0xfe088c68, 0xac92, 0x4e90, { 0x86, 0x52, 0xa3, 0x7e, 0x23, 0x3e, 0x6, 0x83 } }


#define EFI_TEST_SMM_STANDBY_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x1090a261, 0xbfd4, 0x4fc6, 0x8f, 0xac, 0x32, 0x2e, 0xaf, 0x5, 0x29, 0x63 }

#define EFI_TEST_SMM_STANDBY_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0xdcadfb6b, 0xac2d, 0x49ac, 0xbe, 0x9d, 0xa8, 0x9a, 0x60, 0x70, 0x77, 0x70 }

#define EFI_TEST_SMM_STANDBY_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0xc41254af, 0x5ca5, 0x427c, 0x8e, 0xd5, 0xc3, 0x6, 0x68, 0x4a, 0xbb, 0x4f }

#define EFI_TEST_SMM_STANDBY_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0xc8df8ba, 0xba8a, 0x48b2, 0xbf, 0x24, 0xe5, 0x38, 0x1c, 0x20, 0xb7, 0x34 }

#define EFI_TEST_SMM_STANDBY_BUTTON_DISPATCH2_BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x154233c3, 0xa716, 0x4e86, 0xb8, 0x5, 0x7a, 0x9a, 0x92, 0x1b, 0xea, 0x4b }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmStdbyButtDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
