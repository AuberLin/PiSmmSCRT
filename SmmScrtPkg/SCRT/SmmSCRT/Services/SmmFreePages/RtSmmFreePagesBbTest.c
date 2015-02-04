/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmFreePagesBbTest.c

Abstract:

  Runtime SmmFreePages Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmFreePagesBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmFreePagesFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_FREE_PAGES_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmFreePages should free memory from SmmAllocatePages() successfully."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Allocate memory fail."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmFreePagesConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_FREE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmFreePages with Memory being not allocated from AllocatePages(), the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmFreePagesFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_FREE_PAGES_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmFreePagesFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmFreePagesFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmFreePagesConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_FREE_PAGES_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmFreePagesConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmFreePagesConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

