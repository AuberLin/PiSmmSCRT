/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmAllocatePoolBbTest.c

Abstract:

  Runtime SmmAllocatePool Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmAllocatePoolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmAllocatePoolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmAllocatePool should allocate one byte from pool successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_002_GUID,
    "The allocated pool should be 8-byte aligned."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Free allocated pool fail."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmAllocatePool should allocate one byte from pool successfully."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_FUNCTIONTEST_ASSERTION_002_GUID,
    "The allocated pool should be 8-byte aligned."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Free allocated pool fail."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmAllocatePoolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Call SmmAllocatePool with INVALID MemoryType, the return status was EFI_OUT_OF_RESOURCES."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_ALLOCATE_POOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmAllocatePool with MemoryType being non-RuntimeCode/Data, the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmAllocatePoolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_ALLOCATE_POOL_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmAllocatePoolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmAllocatePoolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmAllocatePoolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_ALLOCATE_POOL_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmAllocatePoolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmAllocatePoolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

