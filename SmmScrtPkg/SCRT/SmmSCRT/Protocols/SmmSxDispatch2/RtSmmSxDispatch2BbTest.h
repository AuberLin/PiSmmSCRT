/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmSxDispatch2BbTest.h

Abstract:

  Runtime SmmSxDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_SXDISPATCH2_BB_TEST_H_
#define _RT_SMM_SXDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_SXDISPATCH2_BB_TEST_GUID          \
{ 0x4476f77a, 0x1134, 0x4236, { 0xa4, 0x1f, 0xcd, 0xb1, 0x2, 0x8e, 0x67, 0xb3 } }


#define EFI_TEST_SMMSXDISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x6d9b1147, 0x7968, 0x486d, 0xa2, 0x31, 0x9a, 0xd4, 0xa4, 0x74, 0x4f, 0xfc }

#define EFI_TEST_SMMSXDISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0x7210ac23, 0xcc6, 0x4d31, 0x8e, 0x8a, 0xb3, 0x2a, 0xd2, 0x60, 0xf5, 0xaa }

#define EFI_TEST_SMMSXDISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x9331c639, 0xb49e, 0x43f0, 0xa1, 0x1d, 0x1a, 0x47, 0x25, 0xc4, 0x74, 0x5a }

#define EFI_TEST_SMMSXDISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0xc8631fc3, 0x6df7, 0x4f87, 0xa7, 0x3e, 0x55, 0x30, 0xf6, 0x7c, 0x50, 0x6e }

#define EFI_TEST_SMMSXDISPATCH2BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0xdc1f302d, 0xb906, 0x4ecf, 0xad, 0x87, 0x1a, 0xad, 0x8a, 0xfd, 0xb4, 0x5b }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmSxDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
