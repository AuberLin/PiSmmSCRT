/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmServicesTableLibBbTest.h

Abstract:

  Runtime SmmServicesTableLib Protocol Test.

--*/

#ifndef _RT_SMM_ServicesTableLIB_BB_TEST_H_
#define _RT_SMM_ServicesTableLIB_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define RT_SMM_SERVICESTABLELIB_BB_TEST_GUID          \
{ 0x1c061caf, 0xc10b, 0x48b0, { 0xa6, 0x26, 0x56, 0xe1, 0x65, 0xee, 0x7e, 0x20 } }


#define LIB_TEST_SMMSERVICESTABLE_ASSERTION_001_GUID \
{ 0x7536d090, 0x8eee, 0x4bed, 0x9b, 0x13, 0x36, 0xaf, 0x13, 0x24, 0xd2, 0xab }

//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmServicesTableLibBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
