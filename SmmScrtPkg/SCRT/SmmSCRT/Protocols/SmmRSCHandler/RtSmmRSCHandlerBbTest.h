/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmRSCHandlerBbTest.h

Abstract:

  Runtime SmmRSCHandler Protocol Test.

--*/

#ifndef _RT_SMM_RSCHANDLER_BB_TEST_H_
#define _RT_SMM_RSCHANDLER_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define REQUIRED_ELEMENTS_BB_TEST_GUID                \
{ 0x28a1a5a1, 0x1ff0, 0x4896, { 0xb3, 0x39, 0x23, 0xff, 0x35, 0xe7, 0x29, 0x21 } }


#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_001_GUID \
{ 0x233ad56b, 0xaaa2, 0x4ecf, { 0xb6, 0x31, 0x92, 0x85, 0xc3, 0x7f, 0xa7, 0x93 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_002_GUID \
{ 0xedcfafc2, 0x5636, 0x4f9f, { 0xa9, 0x67, 0xed, 0xb0, 0x15, 0x1e, 0xe4, 0x54 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_003_GUID \
{ 0x89579dac, 0xa806, 0x4709, { 0xa3, 0xe7, 0x77, 0x7d, 0x54, 0xad, 0x25, 0xba } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_004_GUID \
{ 0x185480fd, 0x3d97, 0x4c77, { 0x83, 0xdf, 0xd2, 0xab, 0x80, 0xd7, 0xea, 0x81 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_005_GUID \
{ 0x2f507f9a, 0xe809, 0x4aa7, { 0xbb, 0x87, 0xb4, 0x11, 0x0, 0x4e, 0xd5, 0xd0 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_006_GUID \
{ 0x3a05dfe8, 0xf0dd, 0x4835, { 0x89, 0x54, 0x7e, 0x95, 0x6b, 0x44, 0x11, 0xe1 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_007_GUID \
{ 0xdd350dfe, 0xac6c, 0x439a, { 0xaa, 0x4f, 0xc, 0x39, 0xa9, 0xb4, 0x34, 0x91 } }

#define EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_008_GUID \
{ 0x5c0fc6f4, 0x9b0e, 0x4558, { 0xae, 0x24, 0x4b, 0x26, 0x30, 0xf2, 0x8d, 0xdb } }



//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmRSCHandlerBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
