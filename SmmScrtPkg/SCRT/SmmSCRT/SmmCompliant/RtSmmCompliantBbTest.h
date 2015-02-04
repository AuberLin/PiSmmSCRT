/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmCompliantBbTest.h

Abstract:

  SMM Compliant Black-Box Test.

--*/

#ifndef _RT_SMM_COMPLIANT_BB_TEST_H_
#define _RT_SMM_COMPLIANT_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_COMPLIANT_BB_TEST_GUID          \
{ 0xf4ab07a7, 0xb5f7, 0x4c2b, { 0x9b, 0x30, 0x5e, 0x8b, 0x49, 0xc5, 0x27, 0xfd } }


#define EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_001_GUID \
{ 0x7536d090, 0x8eee, 0x4bed, 0x9b, 0x13, 0x36, 0xaf, 0x13, 0x24, 0xd2, 0xab }

#define EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_002_GUID \
{ 0xb60195e2, 0x13a4, 0x48ac, 0x94, 0x52, 0x59, 0xfd, 0xf7, 0x0, 0xff, 0x6a }

#define EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_003_GUID \
{ 0x43793f6d, 0xc23, 0x4a13, 0xb8, 0x6d, 0xd2, 0x5c, 0xf6, 0x52, 0xc5, 0x24 }


//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmCompliantBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );



#endif
