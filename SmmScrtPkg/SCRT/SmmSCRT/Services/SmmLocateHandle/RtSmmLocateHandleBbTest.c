/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmLocateHandleBbTest.c

Abstract:

  Runtime SmmLocateHandle Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmLocateHandleBbTest.h"



SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmLocateHandleConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmLocateHandle with invalid SearchType, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmLocateHandle with NULL GUID and SearchType being ByProtocol, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmLocateHandle with NULL SearchKey and SearchType being ByRegisterNotify, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_004_GUID,
    "Call SmmLocateHandle with never installed protocol, the return status should be EFI_NOT_FOUND."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_005_GUID,
    "Call SmmLocateHandle with zero BufferSize, the return status should be EFI_BUFFER_TOO_SMALL."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_006_GUID,
    "The zero BufferSize should be updated to correct buffer size."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_007_GUID,
    "Call SmmLocateHandle with BufferSize being correct size minus one, the return status should be EFI_BUFFER_TOO_SMALL."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_008_GUID,
    "The small BufferSize should be updated to correct buffer size."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_009_GUID,
    "Call SmmLocateHandle with NULL BufferSize, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_LOCATE_HANDLE_CONFORMANCETEST_ASSERTION_010_GUID,
    "Call SmmLocateHandle with NULL Buffer, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol still exists."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//



EFI_STATUS
RtSmmLocateHandleConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_LOCATE_HANDLE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmLocateHandleConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmLocateHandleConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

