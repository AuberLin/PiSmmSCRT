/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmTestLib.h

Abstract:

  SMM common test library.

--*/

#ifndef _SMM_TEST_LIB_H_
#define _SMM_TEST_LIB_H_

//
// Includes
//
#include "Efi.h"
#include "Smst.h"


//
// Generic Failure GUID is designed for the test environment issues or
// the walking-on issues. It will be recorded in the log files, but will not be
// summarized in the test report by the EFI SCT Suite.
//
#define SMM_TEST_GENERIC_FAILURE_GUID         \
{ 0xaa4e5c43, 0x290d, 0x42b4, { 0x81, 0xc9, 0x8f, 0x31, 0xe3, 0x8b, 0xbf, 0x55 } }

extern EFI_GUID gSmmTestGenericFailureGuid;

#define SMM_TEST_NULL_GUID                     \
  { 0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

extern EFI_GUID gSmmTestNullGuid;

//
// Structure definitions
//

//
// These test field structures are created based on Black-Box test protocol
// and White-Box test protocol. Using below structures and interfaces to
// generate the test information will be a little easier than using the test
// protocols directly.
//

//
// Black-box test result
//
typedef struct {
  EFI_GUID           AssertionId;
  UINT32              Result;
  UINT32              LineNumber;
  UINT64              Handle;
} SMM_BB_TEST_RESULT;

//
// Black-box test description
//
typedef struct {
  EFI_GUID           AssertionId;
  CHAR8*            Description;
} SMM_BB_TEST_ASSERTION_DESCRIPTION;


//
// Functions declaration
//

EFI_STATUS
EFIAPI
InvokeTestSmiHandler (
  IN  EFI_RUNTIME_SERVICES  *vRT,
  IN  EFI_GUID                  *TestHandlerGuid,
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray  
  );

EFI_STATUS
EFIAPI
CheckSmmTestResult (
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray
  );

EFI_STATUS
EFIAPI
InvokeTestSmiHandlerViaAcpiTable (
  IN  EFI_RUNTIME_SERVICES  *vRT,
  IN  EFI_GUID                  *TestHandlerGuid,
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray  
  );

EFI_STATUS
EFIAPI
RecordSmmTestAssertion (
  IN  EFI_HANDLE             Handle OPTIONAL,
  IN  EFI_GUID                  *AssertionGuid,
  IN  UINT32  Result,
  IN  UINT32     AtLine,
  IN  SMM_BB_TEST_RESULT* ResultArray,
  IN  UINTN        ArraySize
  );

VOID
SmmTestCopyMem (
  IN VOID                           *Dest,
  IN VOID                           *Src,
  IN UINTN                          len
  );

VOID
SmmTestSetMem (
  IN VOID                           *Buffer,
  IN UINTN                          len,
  IN UINT8                         Value
  );

INTN
SmmTestCompareGuid(
  IN EFI_GUID                       *Guid1,
  IN EFI_GUID                       *Guid2
  );

BOOLEAN
SmmGrowBuffer(
  IN EFI_SMM_SYSTEM_TABLE *Smst,
  IN OUT EFI_STATUS   *Status,
  IN OUT VOID         **Buffer,
  IN UINTN            BufferSize
  );

EFI_STATUS
SmmLibLocateHandle (
  IN EFI_SMM_SYSTEM_TABLE         *Smst,
  IN EFI_LOCATE_SEARCH_TYPE       SearchType,
  IN EFI_GUID                     *Protocol OPTIONAL,
  IN VOID                         *SearchKey OPTIONAL,
  IN OUT UINTN                    *NoHandles,
  OUT EFI_HANDLE                  **Buffer
  );

#endif
