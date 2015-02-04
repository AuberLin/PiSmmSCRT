/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmStartupThisApBbTest.c

Abstract:

  Runtime SmmStartupThisAp Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmStartupThisApBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmStartupThisApFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_STARTUP_THIS_AP_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmStartupThisAp should assign code procedure to one AP successfully."
  },
  {
    EFI_TEST_SMM_STARTUP_THIS_AP_FUNCTIONTEST_ASSERTION_002_GUID,
    "The assigned AP procedure should execute successfully."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmStartupThisApConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_STARTUP_THIS_AP_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmStartupThisAp with CpuIndex being out of range, the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmStartupThisApFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_STARTUP_THIS_AP_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmStartupThisApFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmStartupThisApFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmStartupThisApConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_STARTUP_THIS_AP_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmStartupThisApConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmStartupThisApConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

