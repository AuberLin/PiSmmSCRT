/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmUsbDispatch2BbTest.h

Abstract:

  Runtime SmmUsbDispatch2 Protocol Test.

--*/

#ifndef _RT_SMM_USBDISPATCH2_BB_TEST_H_
#define _RT_SMM_USBDISPATCH2_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_USBDISPATCH2_BB_TEST_GUID          \
{ 0xd8ee9962, 0x7dfc, 0x48bc, { 0xa3, 0x94, 0x33, 0x1a, 0x52, 0x4b, 0xc6, 0xfc } }


#define EFI_TEST_SMMUSBDISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID \
{ 0x55377984, 0x9871, 0x4a6f, 0xaf, 0x77, 0x6d, 0xec, 0x15, 0xc5, 0x69, 0x55 }

#define EFI_TEST_SMMUSBDISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID \
{ 0xc049ee41, 0xbd90, 0x40e1, 0xa1, 0x3f, 0xab, 0x88, 0x2, 0x6e, 0xb2, 0x6b }

#define EFI_TEST_SMMUSBDISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID \
{ 0x45f400b1, 0x8cf0, 0x4ae1, 0xa6, 0x39, 0x3a, 0xb, 0xdf, 0xd6, 0xed, 0xbb }

#define EFI_TEST_SMMUSBDISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID \
{ 0x5b9cbff0, 0x8eeb, 0x4ed0, 0xb9, 0x9, 0x81, 0x15, 0x25, 0x61, 0x9b, 0xfb }

#define EFI_TEST_SMMUSBDISPATCH2BBTEST_REQUIRED_ASSERTION_005_GUID \
{ 0x88fb39, 0x54a9, 0x41f0, 0xbf, 0xa, 0xad, 0xdf, 0xc7, 0x7c, 0x11, 0xf5 }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmUsbDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
