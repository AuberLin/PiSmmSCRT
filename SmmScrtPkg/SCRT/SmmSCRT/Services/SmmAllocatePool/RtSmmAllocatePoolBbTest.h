/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmAllocatePoolBbTest.h

Abstract:

  Runtime SmmAllocatePool Service Test.

--*/

#ifndef _RT_SMM_ALLOCPOOL_BB_TEST_H_
#define _RT_SMM_ALLOCPOOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_ALLOCATE_POOL_CONF_BB_TEST_GUID                \
{ 0xc1294c51, 0xde5, 0x4148, { 0xbe, 0xe6, 0xb5, 0x28, 0xb9, 0xc1, 0xea, 0x7c } }

#define SMM_ALLOCATE_POOL_FUNC_BB_TEST_GUID                \
{ 0xa46bc755, 0x9c2c, 0x4871, { 0x9f, 0x8e, 0x2b, 0x7e, 0x5b, 0x30, 0x71, 0xeb } }


#define EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xe63d3f54, 0xe0d7, 0x4a14, { 0xa9, 0xac, 0x90, 0x4c, 0x3b, 0xe5, 0x14, 0xdd } }

#define EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xfd65b49f, 0x3521, 0x4fe7, { 0x9d, 0x57, 0xa9, 0xe7, 0xef, 0xd3, 0x68, 0x2f } }

#define EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0xe70b6e1, 0x99e4, 0x42e3, { 0x9a, 0xd3, 0x66, 0x6c, 0x81, 0x6e, 0x34, 0x8a } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmAllocatePoolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmAllocatePoolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
