/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmFreePagesBbTest.h

Abstract:

  Runtime SmmFreePages Service Test.

--*/

#ifndef _RT_SMM_FREEPAGE_BB_TEST_H_
#define _RT_SMM_FREEPAGE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_FREE_PAGES_CONF_BB_TEST_GUID                \
{ 0x2ac406e, 0xa28b, 0x4819, { 0xb9, 0x61, 0xa7, 0x22, 0xa6, 0x1a, 0x78, 0x8d } }

#define SMM_FREE_PAGES_FUNC_BB_TEST_GUID                \
{ 0xae12b52f, 0x7537, 0x4243, { 0x81, 0x3e, 0x94, 0x58, 0x3f, 0x7e, 0xea, 0xf4 } }


#define EFI_TEST_SMM_FREE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xcbe44c5a, 0x2e8e, 0x4c5c, { 0xb8, 0xaf, 0x8e, 0x60, 0x46, 0xd1, 0xff, 0xca } }

#define EFI_TEST_SMM_FREE_PAGES_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x4cc7c9c0, 0x2205, 0x4b55, { 0x8b, 0x76, 0xa1, 0xac, 0xd9, 0x95, 0xbe, 0x33 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmFreePagesFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmFreePagesConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
