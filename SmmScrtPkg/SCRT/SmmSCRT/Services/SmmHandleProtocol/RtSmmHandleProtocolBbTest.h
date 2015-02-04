/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmHandleProtocolBbTest.h

Abstract:

  Runtime SmmHandleProtocol Service Test.

--*/

#ifndef _RT_SMM_HANDLEPROTOCOL_BB_TEST_H_
#define _RT_SMM_HANDLEPROTOCOL_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_HANDLE_PROTOCOL_CONF_BB_TEST_GUID                \
{ 0x93dcb089, 0x9fad, 0x498b, { 0xbe, 0x57, 0xd6, 0x36, 0x73, 0xb2, 0xff, 0x93 } }


#define EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xc262f62c, 0x9eb9, 0x4144, { 0xb5, 0x81, 0xf2, 0x5c, 0xb1, 0xab, 0x69, 0x5e } }

#define EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x14a7801b, 0x920f, 0x4431, { 0xb3, 0xf4, 0x86, 0x60, 0x55, 0x2, 0x70, 0xcf } }

#define EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0x2c3f58cc, 0x9da9, 0x4948, { 0x87, 0x4e, 0xac, 0x34, 0x5, 0x7e, 0xbf, 0x10 } }

#define EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0xa268a22, 0xe152, 0x4576, { 0x9f, 0x9f, 0xe1, 0x19, 0xb6, 0xb0, 0xab, 0x69 } }

//
// Prototype of conformance tests
//


  
EFI_STATUS
RtSmmHandleProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
