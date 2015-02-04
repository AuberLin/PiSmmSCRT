/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmStartupThisApBbTest.h

Abstract:

  Runtime SmmStartupThisAp Service Test.

--*/

#ifndef _RT_SMM_STARTUPTHISAP_BB_TEST_H_
#define _RT_SMM_STARTUPTHISAP_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_STARTUP_THIS_AP_CONF_BB_TEST_GUID                \
{ 0xcd14b9, 0xcf6, 0x4f6f, { 0xa3, 0x8a, 0xc5, 0x24, 0xf9, 0x0, 0x24, 0x4d } }

#define SMM_STARTUP_THIS_AP_FUNC_BB_TEST_GUID                \
{ 0x155075a0, 0xb395, 0x4a14, { 0x81, 0x98, 0x83, 0xee, 0x8a, 0xbf, 0x6d, 0x29 } }


#define EFI_TEST_SMM_STARTUP_THIS_AP_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x7b313e7c, 0x52b, 0x4686, { 0x97, 0xbb, 0x8e, 0x2d, 0x47, 0xb1, 0x19, 0x18 } }

#define EFI_TEST_SMM_STARTUP_THIS_AP_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0x14e02e38, 0xf767, 0x43d8, { 0x9a, 0xb, 0x6e, 0x61, 0x37, 0x64, 0x4e, 0x16 } }

#define EFI_TEST_SMM_STARTUP_THIS_AP_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0xbde72dac, 0x44b0, 0x43de, { 0x97, 0xf, 0x42, 0x72, 0xb0, 0x7b, 0x48, 0xa9 } }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmStartupThisApFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmmStartupThisApConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
