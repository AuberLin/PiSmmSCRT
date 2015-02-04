/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmLocateHandleBbTest.h

Abstract:

  Runtime SmmLocateHandle Service Test.

--*/

#ifndef _RT_SMM_LOCATEHANDLE_BB_TEST_H_
#define _RT_SMM_LOCATEHANDLE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define SMM_LOCATE_HANDLE_CONF_BB_TEST_GUID                \
{ 0xc5725c65, 0xd6b, 0x4cbc, { 0xaa, 0x80, 0xad, 0xf0, 0xe4, 0xde, 0x33, 0x67 } }


#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x4a6f426, 0x691, 0x4e48, { 0xac, 0xb4, 0xdb, 0xc6, 0x6f, 0xea, 0x4a, 0x74 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x35aa8a6, 0x32dc, 0x449c, { 0xae, 0xb, 0x72, 0x1e, 0x8c, 0xe9, 0xc4, 0x55 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0x7e7165d0, 0xacf3, 0x40e2, { 0xb8, 0x5, 0x16, 0x76, 0xff, 0xdb, 0xbf, 0xbd } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0x62f89f03, 0xc073, 0x4d5c, { 0xb3, 0x85, 0xf0, 0x96, 0x15, 0xde, 0x55, 0xac } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_005_GUID \
{ 0xde826b56, 0xb0a4, 0x4f78, { 0xb7, 0x30, 0x3d, 0x9d, 0xe7, 0xd1, 0x35, 0x23 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_006_GUID \
{ 0x34c97b5d, 0x6525, 0x4bd6, { 0x91, 0xf0, 0x29, 0x7f, 0xc1, 0x24, 0x3e, 0x93 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_007_GUID \
{ 0xdf5fc633, 0x5c82, 0x4d52, { 0xb6, 0x3d, 0x8f, 0x5d, 0x69, 0x7e, 0x95, 0xa2 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_008_GUID \
{ 0x114e8c95, 0x6f85, 0x4d12, { 0x86, 0x2b, 0x80, 0x4, 0xdf, 0x12, 0x26, 0x75 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_009_GUID \
{ 0x125d2851, 0xddf, 0x417e, { 0x9f, 0xd7, 0x36, 0x64, 0xd1, 0xe2, 0xf8, 0x85 } }

#define EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_010_GUID \
{ 0xf769898c, 0xaf46, 0x495c, { 0x88, 0x7a, 0xcc, 0xde, 0xcf, 0x40, 0x9e, 0xfc } }

//
// Prototype of conformance tests
//


  
EFI_STATUS
RtSmmLocateHandleConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );  



#endif
