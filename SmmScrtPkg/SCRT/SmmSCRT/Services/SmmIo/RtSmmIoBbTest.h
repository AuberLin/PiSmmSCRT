/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmIoBbTest.h

Abstract:

  Runtime SmmHandleProtocol Service Test.

--*/

#ifndef _RT_SMM_IOSERVICE_BB_TEST_H_
#define _RT_SMM_IOSERVICE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_IO_CONF_BB_TEST_GUID                \
{ 0x45bdcfb2, 0xfc3c, 0x4e3c, { 0x9f, 0xec, 0xbb, 0xe0, 0x7d, 0x81, 0xb3, 0x6b } }


#define EFI_TEST_SMM_IO_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0xf2794450, 0x243a, 0x417b, { 0xb5, 0xa0, 0xe9, 0x2e, 0x54, 0x73, 0x65, 0x11 } }

//
// Prototype of conformance tests
//


  
EFI_STATUS
RtSmmIoConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
