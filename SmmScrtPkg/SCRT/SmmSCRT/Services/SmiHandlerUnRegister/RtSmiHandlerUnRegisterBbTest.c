/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiHandlerUnRegisterBbTest.c

Abstract:

  Runtime SmiHandlerUnRegister Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmiHandlerUnRegisterBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmiHandlerUnRegisterFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMI_HANDLER_UNREGISTER__FUNCTIONTEST_ASSERTION_001_GUID,
    "SmiHandlerUnRegister should unregister a SmiHandler successfully."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmiHandlerUnRegisterConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMI_HANDLER_UNREGISTER_CONFORMANCETEST_ASSERTION_001_GUID,
    "If unregister an invalid handler, the returen status should be EFI_INVALID_PARAMETER"
  },

  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmiHandlerUnRegisterFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMI_HANDLE_UNREGISTER_FUNCTION_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmiHandlerUnRegisterFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmiHandlerUnRegisterFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmiHandlerUnRegisterConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMI_HANDLE_UNREGISTER_CONFORMANCE_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmiHandlerUnRegisterConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmiHandlerUnRegisterConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

