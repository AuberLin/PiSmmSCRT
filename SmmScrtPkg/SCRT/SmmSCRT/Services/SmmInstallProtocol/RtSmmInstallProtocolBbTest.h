/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmInstallProtocolBbTest.h

Abstract:

  Runtime SmmInstallProtocol Service Test.

--*/

#ifndef _RT_SMM_INSTALLPROTOCOL_BB_TEST_H_
#define _RT_SMM_INSTALLPROTOCOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_INSTALL_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID                \
{ 0x5a15d1e5, 0x791f, 0x4fb3, { 0xa6, 0x7b, 0x42, 0xf4, 0x12, 0x3e, 0xdf, 0x72 } }

#define SMM_INSTALL_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID                \
{ 0x5b08eda9, 0x97d9, 0x4bd3, { 0x94, 0x49, 0x9e, 0x37, 0xed, 0xa7, 0xc8, 0x72 } }


#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xd6d570d6, 0xa8d6, 0x4b6c, { 0xa6, 0x60, 0xb9, 0x9d, 0xed, 0x6e, 0x3c, 0x6a } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0xa4f30595, 0xeca4, 0x4a2e, { 0x8b, 0x57, 0x58, 0xf4, 0xe0, 0x4e, 0xfc, 0x7d } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0x9e1eefb5, 0xe149, 0x4ef2, { 0x80, 0xf7, 0x17, 0x7, 0x64, 0xa1, 0x54, 0x8f } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0xeb9a5169, 0x96f4, 0x4d7e, { 0xba, 0x13, 0x32, 0x76, 0xdb, 0xe3, 0x86, 0xf5 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_005_GUID \
{ 0x416e4051, 0x1239, 0x44ac, { 0xb1, 0xa5, 0xcf, 0x15, 0x85, 0x86, 0x96, 0x63 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x7085fbb6, 0xb9a6, 0x46c0, { 0xb2, 0x89, 0xba, 0x34, 0xe, 0xc3, 0x72, 0x90 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x77c05e43, 0x8f79, 0x47e5, { 0x88, 0x33, 0x2a, 0x97, 0xe7, 0x4b, 0x37, 0xc } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x35db3fa5, 0xf4f9, 0x47ba, { 0x83, 0xb, 0x18, 0xef, 0x6f, 0x57, 0x7b, 0x89 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0x38999980, 0xf4d3, 0x4f9b, { 0x99, 0xb3, 0xbd, 0xb9, 0xf5, 0xfc, 0xda, 0x56 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0x56020f26, 0xd5de, 0x43aa, { 0x85, 0xb4, 0x57, 0x4d, 0x67, 0x60, 0x87, 0xe1 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_006_GUID \
{ 0xbd697654, 0x7cc0, 0x4cc2, { 0xa6, 0x5e, 0x6, 0x93, 0x3a, 0x61, 0x9b, 0x82 } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_007_GUID \
{ 0xd3617336, 0x43ac, 0x4d4e, { 0xa6, 0x23, 0x70, 0x3a, 0xf8, 0x50, 0x88, 0x1f } }

#define EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_008_GUID \
{ 0x1722b3be, 0x521a, 0x4f32, { 0xa2, 0xe7, 0x70, 0xae, 0x8a, 0x4a, 0x2c, 0x70 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmInstallProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmInstallProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
