/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmLocateProtocolBbTest.h

Abstract:

  Runtime SmmLocateProtocol Service Test.

--*/

#ifndef _RT_SMM_LOCATEPROTOCOL_BB_TEST_H_
#define _RT_SMM_LOCATEPROTOCOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_LOCATE_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID                \
{ 0xf9afd7eb, 0x1034, 0x4d82, { 0xae, 0x21, 0xc, 0x7b, 0x8c, 0x6f, 0x1a, 0x19 } }

#define SMM_LOCATE_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID                \
{ 0xd471bbac, 0x50bd, 0x4083, { 0xb9, 0xed, 0x79, 0x54, 0x3a, 0xe8, 0x9d, 0x51 } }


#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x9f356286, 0xf3b6, 0x492c, { 0xb6, 0x22, 0xc5, 0xdc, 0x54, 0x4c, 0xb2, 0xe8 } }

#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x4a829d6f, 0x3d80, 0x4887, { 0x89, 0xae, 0x65, 0xe4, 0x3f, 0x42, 0x6b, 0x6c } }

#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x1e02b772, 0xd08c, 0x4e81, { 0x83, 0xa3, 0x69, 0x27, 0x7c, 0x2e, 0x2, 0x1d } }

#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x59f3c41a, 0x698c, 0x4271, { 0x85, 0xad, 0xe8, 0x10, 0xf4, 0xfa, 0xe6, 0xd0 } }

#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0x7713169, 0x998a, 0x4c72, { 0x89, 0xe6, 0x27, 0x64, 0x46, 0x32, 0x12, 0xd3 } }

#define EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0xe6e570da, 0x81c1, 0x40ef, { 0x93, 0x5d, 0x79, 0xb8, 0x73, 0xd, 0x98, 0x84 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmLocateProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmLocateProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
