/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmFreePoolBbTest.c

Abstract:

  Runtime SmmFreePool Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmFreePoolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmFreePoolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_FREE_POOL_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmFreePool should free memory from SmmAllocatePool() successfully."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Allocate memory fail."
  },
  {
    EFI_TEST_SMM_FREE_POOL_FUNCTIONTEST_ASSERTION_002_GUID,
    "SmmFreePool should free memory from SmmAllocatePage() successfully."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmFreePoolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_FREE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmFreePool with Memory being not allocated from AllocatePool() or AllocatePage(), the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_FREE_POOL_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmFreePool with Memory being NULL, the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmFreePoolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_FREE_POOL_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmFreePoolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmFreePoolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmFreePoolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_FREE_POOL_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmFreePoolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmFreePoolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

