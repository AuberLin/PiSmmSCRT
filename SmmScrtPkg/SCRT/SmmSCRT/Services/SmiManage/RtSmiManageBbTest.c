/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiManageBbTest.c

Abstract:

  Runtime SmiManage Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmiManageBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmiManageFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_001_GUID,
    "One of SMI handler return EFI_SUCCESS, SmiManage should return EFI_SUCCESS. HandlerType is not NULL and only one SMI handler should be invoked."
  },
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_002_GUID,
    "One of SMI handler return EFI_WARN_INTERRUPT_SOURCE_QUIESCED, SmiManager should return EFI_SUCCESS. HandlerType is not NULL, and two SMI handler should be invoked."
  },
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_003_GUID,
    "All SMI handler return EFI_WARN_INTERRUPT_SOURCE_PENDING, SmiManager should return EFI_WARN_INTERRUPT_SOURCE_PENDING and two SMI handlers should be invoked"
  },
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_004_GUID,
    " One of SMI handler return EFI_INTERRUPT_PENDING and HandlerType is not NULL, SmiManager should return EFI_INTERRUPT_PENDING and only one SMI handler will be invoked."
  },
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_005_GUID,
    "One of SMI handler return EFI_SUCCESS, SmiManage should return EFI_SUCCESS. HandlerType is not NULL, and two root SMI handler should be invoked.."
  },  
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_006_GUID,
    "One of SMI handler return EFI_WARN_INTERRUPT_SOURCE_QUIESCED, SmiManager should return EFI_SUCCES. HandlerType is  NULL, and two SMI handler should be invoked."
  },
  {
    EFI_TEST_SMI_MANAGE_FUNCTIONTEST_ASSERTION_007_GUID,
    "One of SMI handler return EFI_INTERRUPT_ PENDING and handle type is  NULL,  two root SMI handler should be invoked."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmiManageConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMI_MANAGE_CONFORMANCETEST_ASSERTION_001_GUID,
    "HandelrType refers to a invalid Guid, Should return EFI_NOT_FOUND"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmiManageFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMI_MANAGE_FUNCTION_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmiManageFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmiManageFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmiManageConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMI_MANAGE_CONFORMANCE_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmiManageConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmiManageConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

