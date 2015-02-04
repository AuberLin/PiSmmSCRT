/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmIoBbTest.c

Abstract:

  Runtime SmmIo Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmIoBbTest.h"



SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmIoConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_IO_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmIo with invalid IoWidth, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Call SmmIo with INVALID IoWidth, but the test address is not supported."
  },
  {
    EFI_TEST_SMM_IO_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmIo with invalid IoWidth, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_IO_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmIo with invalid IoWidth, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_IO_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmIo with invalid IoWidth, the return status should be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//



EFI_STATUS
RtSmmIoConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_IO_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmIoConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmIoConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

