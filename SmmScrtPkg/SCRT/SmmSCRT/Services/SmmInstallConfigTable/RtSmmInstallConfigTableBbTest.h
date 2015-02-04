/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmInstallConfigTableBbTest.h

Abstract:

  Runtime SmmInstallConfigTable Service Test.

--*/

#ifndef _RT_SMM_INSTALLCONFIGTABLE_BB_TEST_H_
#define _RT_SMM_INSTALLCONFIGTABLE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_INSTALL_CONFIGURATION_TABLE_FUNC_BB_TEST_GUID                \
{ 0x740035d9, 0x12ae, 0x462c, { 0xbb, 0xdf, 0x6d, 0x9, 0xc3, 0x1c, 0x59, 0xf3 } }

#define SMM_INSTALL_CONFIGURATION_TABLE_CONF_BB_TEST_GUID                \
{ 0xfd2361a8, 0x93a2, 0x432e, { 0xa6, 0x40, 0xd4, 0x24, 0xcd, 0x4c, 0x2d, 0x5a } }


#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x8e45ecf5, 0x9b4d, 0x4232, { 0x87, 0x5c, 0x5, 0xd6, 0xc1, 0x8, 0xca, 0xf3 } } 

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x8b1f6aa8, 0xb66f, 0x4369, { 0x8b, 0x43, 0xd1, 0x53, 0x6b, 0xf9, 0x14, 0x2d } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x76642d57, 0x38a7, 0x43f7, { 0xa0, 0xb7, 0x53, 0xfb, 0x4a, 0x34, 0xd4, 0x8a } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0xfb367236, 0xae7f, 0x4245, { 0x83, 0x3c, 0xd3, 0x65, 0x20, 0xed, 0xcf, 0x51 } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x1478cf6b, 0x168e, 0x40ca, { 0xaf, 0x93, 0x74, 0xbb, 0xd9, 0x36, 0x69, 0x59 } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0xc1e48c75, 0x490c, 0x44ef, { 0xa3, 0x68, 0x46, 0x10, 0xb5, 0x51, 0x44, 0x33 } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0x9f34bbfb, 0xa9b6, 0x4b0d, { 0x9b, 0xd5, 0x73, 0x58, 0xb6, 0x28, 0xde, 0x1e } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_006_GUID \
{ 0x618dc77c, 0x6954, 0x44ef, { 0xbc, 0x3b, 0xc6, 0x4f, 0x34, 0xff, 0x5, 0xd4 } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_007_GUID \
{ 0xee9a1793, 0x9161, 0x4c89, { 0xbc, 0x5e, 0xf4, 0xd1, 0x96, 0x7c, 0xd, 0xca } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_008_GUID \
{ 0x2e5a8ba1, 0xfa27, 0x429d, { 0x85, 0x8c, 0xb9, 0xe, 0xb2, 0x17, 0xe7, 0x37 } }

#define EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_009_GUID \
{ 0x4fce101c, 0xdf11, 0x4479, { 0xb1, 0xfd, 0x43, 0xa7, 0x79, 0xa7, 0x1d, 0x99 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmInstallConfigTableFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmInstallConfigTableConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
