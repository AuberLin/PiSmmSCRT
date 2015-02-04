/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmAllocatePagesBbTest.h

Abstract:

  Runtime SmmAllocatePages Service Test.

--*/

#ifndef _RT_SMM_ALLOCPAGE_BB_TEST_H_
#define _RT_SMM_ALLOCPAGE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_ALLOCATE_PAGES_CONF_BB_TEST_GUID                \
{ 0xc7acdd7e, 0x10f2, 0x4f78, { 0x8f, 0xf4, 0xb4, 0xb8, 0xbc, 0x74, 0x7f, 0x40 } }

#define SMM_ALLOCATE_PAGES_FUNC_BB_TEST_GUID                \
{ 0x132a19f0, 0xc237, 0x40d2, { 0x9b, 0xf8, 0x17, 0x57, 0xcd, 0x90, 0x42, 0x18 } }


#define EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xe63d3f54, 0xe0d7, 0x4a14, { 0xa9, 0xac, 0x90, 0x4c, 0x3b, 0xe5, 0x14, 0xdd } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0xcb1579c0, 0x312e, 0x4368, { 0xac, 0x7a, 0x14, 0xb3, 0x68, 0x9d, 0xc6, 0xf5 } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xfd65b49f, 0x3521, 0x4fe7, { 0x9d, 0x57, 0xa9, 0xe7, 0xef, 0xd3, 0x68, 0x2f } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0xe70b6e1, 0x99e4, 0x42e3, { 0x9a, 0xd3, 0x66, 0x6c, 0x81, 0x6e, 0x34, 0x8a } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0xad384b07, 0x7005, 0x47ba, { 0xa4, 0xf4, 0xd6, 0x80, 0x56, 0xaa, 0x7e, 0x3b } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0xc1fe878b, 0x99fb, 0x40e1, { 0x95, 0x73, 0xd5, 0x36, 0x61, 0x5d, 0xf5, 0x93 } }

#define EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0x8f5aab87, 0x5326, 0x429e, { 0x9d, 0x1, 0x6c, 0xcd, 0x1a, 0x6c, 0x22, 0xa3 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmAllocatePagesFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmAllocatePagesConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
