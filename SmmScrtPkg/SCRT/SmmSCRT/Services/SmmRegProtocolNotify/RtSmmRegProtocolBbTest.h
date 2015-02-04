/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmRegProtocolBbTest.h

Abstract:

  Runtime SmmRegProtocolNotify Service Test.

--*/

#ifndef _RT_SMM_REGPROTOCOL_BB_TEST_H_
#define _RT_SMM_REGPROTOCOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_REG_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID                \
{ 0xa981d5d2, 0xe143, 0x4436, { 0xab, 0xed, 0x98, 0xcd, 0x3f, 0xab, 0x70, 0x24 } }

#define SMM_REG_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID                \
{ 0x1d311a76, 0x9371, 0x4bc1, { 0x98, 0x1c, 0x82, 0xc9, 0x41, 0x89, 0x8a, 0xd6 } }


#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x50c68170, 0xb1d9, 0x4a1a, { 0xb2, 0x78, 0xe1, 0x6c, 0x32, 0xf8, 0x67, 0xfd } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x17b9134, 0xd032, 0x4f2f, { 0x90, 0x82, 0x9c, 0x8a, 0x1, 0xd6, 0x92, 0xc2 } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0xfc324d59, 0x6564, 0x44ed, { 0x92, 0x1, 0x52, 0x11, 0x78, 0x69, 0x2a, 0xb } }

// Add following GUID for conformance test case to check EFI_NOT_FOUND
#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0xc7ddb676, 0x5a6a, 0x3419, { 0x99, 0x53, 0x1f, 0x5e, 0xad, 0x48, 0xc2, 0x92 } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xb9382978, 0xe3fa, 0x48b3, { 0xb5, 0xcc, 0xe0, 0x4d, 0x21, 0xd3, 0x74, 0xed } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x618d02f0, 0x6cd1, 0x4bd1, { 0xaa, 0x64, 0xf1, 0x37, 0xc7, 0xeb, 0xbb, 0x5e } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x31ca3acb, 0xb717, 0x43e3, { 0x89, 0xa1, 0x96, 0xd4, 0x55, 0x7, 0xcf, 0x15 } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0x17b9134, 0xd032, 0x4f2f, { 0x90, 0x82, 0x9c, 0x8a, 0x1, 0xd6, 0x92, 0xc2 } }

#define EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0xc7ddb676, 0x5a6a, 0x3419, { 0x99, 0x53, 0x1f, 0x5e, 0xad, 0x48, 0xc2, 0x92 } }


//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmRegProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmRegProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
