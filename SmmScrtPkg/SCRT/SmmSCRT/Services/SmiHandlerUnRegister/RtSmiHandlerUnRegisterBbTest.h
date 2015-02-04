/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiHandlerUnRegisterBbTest.h

Abstract:

  Runtime SmiHandlerUnRegister Protocol Test.

--*/

#ifndef _RT_SMM_SMIHANDLERUNREGISTER_BB_TEST_H_
#define _RT_SMM_SMIHANDLERUNREGISTER_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMI_HANDLE_UNREGISTER_CONFORMANCE_BB_TEST_GUID                \
{ 0x72c9c1c7, 0x627e, 0x4519, { 0x93, 0x1f, 0x72, 0x9, 0xa2, 0xb0, 0x11, 0xbc } }

#define SMI_HANDLE_UNREGISTER_FUNCTION_BB_TEST_GUID                \
{ 0xd2a0c3c4, 0xad25, 0x425f, { 0xa6, 0x37, 0x6e, 0x8d, 0x39, 0xab, 0x6, 0x67 } }


#define EFI_TEST_SMI_HANDLER_UNREGISTER_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x658b85d0, 0xab5a, 0x4898, 0xa2, 0xf, 0x2e, 0xb5, 0xec, 0xb, 0xef, 0x5e } 

#define EFI_TEST_SMI_HANDLER_UNREGISTER__FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xc1cd8120, 0x928b, 0x484b, 0x9d, 0xd3, 0x42, 0x17, 0xe3, 0x20, 0xf8, 0x6c }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmiHandlerUnRegisterFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );
  
EFI_STATUS
RtSmiHandlerUnRegisterConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
