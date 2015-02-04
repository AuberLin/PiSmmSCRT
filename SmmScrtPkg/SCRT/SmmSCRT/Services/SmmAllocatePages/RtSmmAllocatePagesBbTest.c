/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmAllocatePagesBbTest.c

Abstract:

  Runtime SmmAllocatePages Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmAllocatePagesBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmAllocatePagesFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmAllocatePages should allocate with type AllocateAnyPages successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_002_GUID,
    "The allocated Memory should be page-aligned."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_003_GUID,
    "SmmAllocatePages should allocate with type AllocateMaxAddress successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_004_GUID,
    "SmmAllocatePages should allocate with type AllocateAddress successfully."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Free allocated page fail."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmAllocatePages should allocate with type AllocateAnyPages successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_002_GUID,
    "The allocated Memory should be page-aligned."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_003_GUID,
    "SmmAllocatePages should allocate with type AllocateMaxAddress successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_004_GUID,
    "SmmAllocatePages should allocate with type AllocateAddress successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_FUNCTIONTEST_ASSERTION_005_GUID,
    "Call SmmAllocatePages with Address being already allocated one, the return status should be EFI_NOT_FOUND."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmAllocatePagesConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Call SmmAllocatePages with INVALID MemoryType, the return status was EFI_OUT_OF_RESOURCES."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePages with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmAllocatePages with MemoryType being invalid allocate type, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmAllocatePages with MemoryType being invalid allocate type, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_PAGES_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmAllocatePages with MemoryType being invalid allocate type, the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmAllocatePagesFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_ALLOCATE_PAGES_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmAllocatePagesFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmAllocatePagesFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmAllocatePagesConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_ALLOCATE_PAGES_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmAllocatePagesConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmAllocatePagesConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

