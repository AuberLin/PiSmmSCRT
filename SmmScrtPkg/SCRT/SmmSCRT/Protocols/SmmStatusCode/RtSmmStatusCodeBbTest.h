/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmStatusCodeBbTest.h

Abstract:

  Runtime SmmStatusCode Protocol Test.

--*/

#ifndef _RT_SMM_STATUSCODE_BB_TEST_H_
#define _RT_SMM_STATUSCODE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define RSC_REQUIRED_ELEMENTS_BB_TEST_GUID                \
{ 0xaadcdc32, 0xbcff, 0x44a8, { 0x80, 0x20, 0xe0, 0xa9, 0x24, 0x58, 0x95, 0x65 } }


#define EFI_TEST_SMM_STATUS_CODE_BBTEST_ASSERTION_001_GUID \
{ 0xd9f03be, 0xe3, 0x4182, { 0x81, 0x6f, 0xdb, 0xc, 0x7, 0xcc, 0xd6, 0x41 } }


#define EFI_TEST_SMM_STATUS_CODE_BBTEST_ASSERTION_002_GUID \
{ 0x3ab0999d, 0x9273, 0x4a18, { 0xb1, 0xee, 0x56, 0x64, 0x94, 0x58, 0x49, 0x60 } }



//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmStatusCodeBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
