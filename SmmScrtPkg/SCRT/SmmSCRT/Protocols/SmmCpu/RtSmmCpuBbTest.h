/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmCpuBbTest.h

Abstract:

  Runtime SmmCpu Protocol Test.

--*/

#ifndef _RT_SMM_CPU_BB_TEST_H_
#define _RT_SMM_CPU_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_CPU_BB_TEST_GUID          \
{ 0x728e41e2, 0x50a1, 0x4c5d, { 0x81, 0xfe, 0x0, 0x9e, 0x19, 0x2f, 0x73, 0x67 } }


#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x4e40076, 0x360e, 0x4747, { 0xb8, 0x3e, 0xf1, 0x59, 0xfe, 0x21, 0x3, 0xfc } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0xf83d0440, 0x689b, 0x4f57, { 0xbf, 0x7b, 0x1a, 0xd7, 0x82, 0xf5, 0x9e, 0x98 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0xb98de24, 0x48c4, 0x4933, { 0x9f, 0x28, 0xdc, 0x3a, 0xd1, 0x77, 0xc0, 0xc0 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0xba782636, 0x370, 0x4a9f, { 0x95, 0x71, 0x97, 0x4d, 0xa, 0x13, 0x73, 0x65 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0xa8b3b7db, 0x28a3, 0x43d7, { 0x8b, 0xcc, 0xef, 0x1c, 0x6e, 0x0, 0x2d, 0x88 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_006_GUID \
{ 0x8c070341, 0xd8ce, 0x4016, { 0x95, 0x9d, 0xdb, 0x1f, 0xc9, 0x25, 0xb, 0x6b } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_007_GUID \
{ 0xfcdb212b, 0x2b9e, 0x4de6, { 0x88, 0x50, 0xaa, 0x4c, 0x30, 0x9f, 0xb0, 0x76 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_008_GUID \
{ 0x951eace0, 0x849d, 0x4e3f, { 0xa1, 0x9b, 0xc7, 0x50, 0x69, 0x29, 0x8f, 0x2a } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_009_GUID \
{ 0xd1c06425, 0x29ae, 0x4f26, { 0x9c, 0xea, 0x5e, 0x5c, 0x7c, 0xf8, 0x5, 0x15 } }

#define EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_010_GUID \
{ 0xddac21bc, 0x2241, 0x4bea, { 0x97, 0xcf, 0x0, 0x5b, 0xde, 0x42, 0xeb, 0xaf } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmCpuBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
