/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiManageBbTest.h

Abstract:

  Runtime SmiManage Service Test.

--*/

#ifndef _RT_SMM_SMIMANAGE_BB_TEST_H_
#define _RT_SMM_SMIMANAGE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMI_MANAGE_CONFORMANCE_BB_TEST_GUID                \
{ 0x3b880585, 0xc100, 0x4d26, { 0x93, 0xb1, 0xac, 0xb2, 0xac, 0xfb, 0x75, 0x6b } }

#define SMI_MANAGE_FUNCTION_BB_TEST_GUID                \
{ 0xc82a4811, 0xcdf7, 0x4525, { 0x8c, 0x2d, 0x22, 0x11, 0x41, 0x41, 0xf6, 0x4a } }


#define EFI_TEST_SMI_MANAGE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x459c206d, 0xdcc, 0x4a6d, 0x8a, 0x0, 0x3b, 0xf1, 0x29, 0x91, 0xd1, 0x72 }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x709ca95d, 0x6bee, 0x48be, 0xb3, 0x82, 0xca, 0xc0, 0x5, 0x4d, 0x60, 0x33 }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x7bca1047, 0x6e53, 0x4b21, 0x9c, 0x9c, 0x57, 0x12, 0x89, 0x1a, 0x51, 0x4f }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0xab26ebb6, 0x80d, 0x4e1f, 0x8e, 0xd8, 0xa6, 0xa4, 0x25, 0x94, 0xf0, 0xcf }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0xaf204ee6, 0x7c52, 0x4982, 0x85, 0x3a, 0xca, 0x65, 0xc7, 0x65, 0x99, 0xce  }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0xa1d601b8, 0x7c5e, 0x4763, 0x83, 0x4e, 0x4b, 0x88, 0x15, 0xdd, 0x73, 0xa9 }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_006_GUID \
{ 0xfbe2b0df, 0x6192, 0x4558, 0xa7, 0xcc, 0x5f, 0xe3, 0xfc, 0xb1, 0x98, 0x9e }

#define EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_007_GUID \
{ 0xbede4222, 0x81df, 0x4aed, 0xb2, 0xb4, 0x21, 0x46, 0xaf, 0x67, 0x7d, 0xbe }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmiManageFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmiManageConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
