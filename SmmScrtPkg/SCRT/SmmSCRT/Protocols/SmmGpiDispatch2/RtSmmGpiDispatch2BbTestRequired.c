/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmGpiDispatch2BbTestRequired.c

Abstract:

  Runtime SmmGpiDispatch2 Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmGpiDispatch2BbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmGpiDispatch2TestAssertionDescription[] = {
  {
    EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_001_GUID,
    "Call Register() The return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_002_GUID,
    "Call Register() with invalid GPI, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_003_GUID,
    "Call UnRegister() The return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMMGPIDISPATCH2BBTEST_REQUIRED_ASSERTION_004_GUID,
    "Call UnRegister() with invalid handle, the return status should be EFI_INVALID_PARAMETER"
  },

  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmGpiDispatch2BbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_GPIDISPATCH2_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmGpiDispatch2TestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmGpiDispatch2TestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

