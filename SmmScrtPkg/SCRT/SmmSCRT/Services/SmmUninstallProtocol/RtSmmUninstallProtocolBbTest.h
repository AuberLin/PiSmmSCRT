/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmUninstallProtocolBbTest.h

Abstract:

  Runtime SmmUninstallProtocol Service Test.

--*/

#ifndef _RT_SMM_UNINSTALLPROTOCOL_BB_TEST_H_
#define _RT_SMM_UNINSTALLPROTOCOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_UNINSTALL_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID                \
{ 0x4ffcedac, 0xefec, 0x4880, { 0x97, 0xd6, 0xdb, 0x87, 0xa, 0x49, 0xfe, 0xdd } }

#define SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID                \
{ 0xa4a1643, 0x13d, 0x40ab, { 0xaf, 0x9a, 0x21, 0x63, 0x4a, 0xe7, 0x9f, 0xf8 } }


#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xfffc2648, 0xb85a, 0x4485, { 0xae, 0x60, 0x60, 0x30, 0x91, 0x51, 0x82, 0x91 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0xb992a12c, 0xa9d9, 0x44fd, { 0xb8, 0x34, 0xcc, 0x46, 0x6c, 0x2f, 0x77, 0x92 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0x3c7be12f, 0x5666, 0x426b, { 0x87, 0x35, 0x70, 0x35, 0x5b, 0x7a, 0xa2, 0xc4 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0xdf8dac67, 0x1246, 0x4393, { 0xbf, 0xad, 0xeb, 0xd9, 0x86, 0x58, 0x9b, 0xa3 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_005_GUID \
{ 0x4fa40932, 0x1787, 0x4067, { 0xa6, 0x95, 0xa2, 0x7e, 0xc2, 0x45, 0x6d, 0x27 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xc7ee82a2, 0x2ca2, 0x4c30, { 0x95, 0xde, 0x1d, 0x77, 0x2, 0xd6, 0x2b, 0x65 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x9a911793, 0x5701, 0x4b24, { 0x94, 0x5d, 0xa8, 0xac, 0xe7, 0x27, 0x86, 0x75 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x3894730f, 0xb4d2, 0x4a32, { 0x83, 0xad, 0xbd, 0x38, 0x80, 0xcd, 0x8, 0x9e } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0xeb79d6b1, 0x3468, 0x4ef0, { 0xbf, 0x9f, 0x72, 0x6b, 0xa0, 0xc, 0xb, 0x93 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0x425153e0, 0x5028, 0x48b3, { 0xa4, 0x53, 0xd4, 0x1b, 0xe4, 0x28, 0x5c, 0x42 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_006_GUID \
{ 0x6cfd594, 0x7313, 0x4ca6, { 0x86, 0x41, 0x8c, 0xff, 0xdb, 0xdb, 0xf8, 0xe4 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_007_GUID \
{ 0xa9e505ea, 0x48fe, 0x49ae, { 0x80, 0xb2, 0xce, 0x46, 0xf8, 0x6a, 0x30, 0x69 } }

#define EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_008_GUID \
{ 0x54436e60, 0xd9bf, 0x484b, { 0xb2, 0x3e, 0x3, 0x17, 0x3d, 0xb4, 0xd9, 0x74 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmUninstallProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmUninstallProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
