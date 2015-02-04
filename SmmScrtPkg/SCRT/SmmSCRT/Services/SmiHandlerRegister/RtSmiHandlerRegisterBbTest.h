/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiHandlerRegisterBbTest.h

Abstract:

  Runtime SmiHandlerRegister Protocol Test.

--*/

#ifndef _RT_SMM_SMIHANDLERREGISTER_BB_TEST_H_
#define _RT_SMM_SMIHANDLERREGISTER_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMI_HANDLER_REGISTER_FUNCTION_BB_TEST_GUID                \
{ 0xfc47a465, 0xd357, 0x460b, { 0xa0, 0x6d, 0x6f, 0x87, 0x30, 0xe1, 0x58, 0x82 } }


#define EFI_TEST_SMI_HANDLER_REGISTER_FUNCTION_TEST_ASSERTION_001_GUID \
{ 0x5cbb2af0, 0x1002, 0x4212, 0xa6, 0xfb, 0x5d, 0x8c, 0x5a, 0x31, 0xb2, 0x86 }

#define EFI_TEST_SMI_HANDLER_REGISTER_FUNCTION_TEST_ASSERTION_002_GUID \
{ 0x8f52d2a6, 0x96ac, 0x442c, 0xb7, 0x7, 0x26, 0x81, 0x20, 0xe5, 0x58, 0xb7 }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmiHandlerRegisterBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
