/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmStatusCodeBbTestRequired.c

Abstract:

  Runtime SmmStatusCode Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmStatusCodeBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmStatusCodeTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_STATUS_CODE_BBTEST_ASSERTION_001_GUID,
    "Test smm report status code with optional, The return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMM_STATUS_CODE_BBTEST_ASSERTION_002_GUID,
    "Test smm report status code without optional, The return status should be EFI_SUCCESS"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmStatusCodeBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = RSC_REQUIRED_ELEMENTS_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmStatusCodeTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmStatusCodeTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

