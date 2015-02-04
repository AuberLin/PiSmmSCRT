/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmRSCHandlerBbTestRequired.c

Abstract:

  Runtime SmmRSCHandler Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmRSCHandlerBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmRSCHandlerTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_001_GUID,
    "Call Register() to register a callback, the return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_002_GUID,
    "Call Register() twice, the return status should be EFI_ALREADY_STARTED"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_003_GUID,
    "Call Register() with NULL callback, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_004_GUID,
    "Call ReportStatusCode() the registered callback should be invoked"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_005_GUID,
    "Call UnRegister() to Unregister a callback, the return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_006_GUID,
    "Call ReportStatusCode(), the Unregisted callback should not be invoked"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_007_GUID,
    "Call UnRegister() to Unregister a callback twice, the return status should be EFI_NOT_FOUND"
  },
  {
    EFI_TEST_SMM_RSC_HANDLER_BBTEST_ASSERTION_008_GUID,
    "Call UnRegister() to Unregister a callback with NULL call back, the return status should be EFI_INVALID_PARAMETER"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmRSCHandlerBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = REQUIRED_ELEMENTS_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmRSCHandlerTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmRSCHandlerTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

