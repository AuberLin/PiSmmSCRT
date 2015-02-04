/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmPeriTimerDispatch2BbTest.h

Abstract:

  Runtime SmmPeriTimerDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_PERITIMERDISPATCH2_BB_TEST_H_
#define _RT_SMM_PERITIMERDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_PERIODIC_TIMER_DISPATCH2_BB_TEST_GUID          \
{ 0x93a52ba3, 0x5cf4, 0x44ac, { 0xba, 0x6b, 0xcf, 0xd1, 0x18, 0x10, 0x43, 0xe6 } }


#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x251ef8a4, 0xe6b9, 0x4848, 0x94, 0xc1, 0x7e, 0x1c, 0xaf, 0x55, 0x1e, 0xb9 }

#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0x5c6b7e2d, 0xf3e6, 0x4dbe, 0x9e, 0x13, 0x2b, 0x6e, 0x24, 0x5c, 0x89, 0x20 }

#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x50c18c27, 0xbddc, 0x4c5c, 0x98, 0xf5, 0xf5, 0x4f, 0xf5, 0x5b, 0xac, 0x40 }

#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0x1d9b8895, 0x1d9f, 0x40c5, 0x81, 0x25, 0x6f, 0x78, 0x2c, 0x75, 0x5d, 0xb7}

#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x2bcb0277, 0x6cf2, 0x470e, 0x97, 0xaa, 0x53, 0x20, 0x1c, 0xb6, 0x13, 0x46 }

#define EFI_TEST_SMM_PERIODIC_TIMER_DISPATCH2BBTEST_REQUIRED_ASSERTION_006_GUID \
{  0x33fc8bc2, 0xf957, 0x453a, 0x81, 0x1e, 0x91, 0x8f, 0xbc, 0x26, 0x96, 0x75 }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmPeriTimerDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
