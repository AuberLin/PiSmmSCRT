/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmFreePoolBbTest.h

Abstract:

  Runtime SmmFreePool Service Test.

--*/

#ifndef _RT_SMM_FREEPOOL_BB_TEST_H_
#define _RT_SMM_FREEPOOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_FREE_POOL_CONF_BB_TEST_GUID                \
{ 0x98125978, 0xe83f, 0x42dd, { 0x9b, 0xf7, 0x93, 0x48, 0x55, 0x42, 0x1a, 0xcb } }

#define SMM_FREE_POOL_FUNC_BB_TEST_GUID                \
{ 0xee092281, 0xaf61, 0x4386, { 0xbe, 0x96, 0xea, 0x21, 0x76, 0xab, 0xfa, 0xbb } }


#define EFI_TEST_SMM_FREE_POOL_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xe63d3f54, 0xe0d7, 0x4a14, { 0xa9, 0xac, 0x90, 0x4c, 0x3b, 0xe5, 0x14, 0xdd } }

#define EFI_TEST_SMM_FREE_POOL_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x8a5bcf27, 0x249, 0x42f5, { 0xa7, 0x13, 0xf7, 0x8f, 0x5f, 0x9a, 0x28, 0x5e } }

#define EFI_TEST_SMM_FREE_POOL_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xfd65b49f, 0x3521, 0x4fe7, { 0x9d, 0x57, 0xa9, 0xe7, 0xef, 0xd3, 0x68, 0x2f } }

#define EFI_TEST_SMM_FREE_POOL_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0xe70b6e1, 0x99e4, 0x42e3, { 0x9a, 0xd3, 0x66, 0x6c, 0x81, 0x6e, 0x34, 0x8a } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmFreePoolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmFreePoolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
