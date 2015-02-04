/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmCpuBbTestRequired.c

Abstract:

  Runtime SmmCpu Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmCpuBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmCpuTestAssertionDescription[] = {
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_001_GUID,
    "Call ReadSaveState() The return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_002_GUID,
    "Call ReadSaveState() with wrong register, the return status should be EFI_NOT_FOUND"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_003_GUID,
    "Call ReadSaveState() with wrong CPU index, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_004_GUID,
    "Call ReadSaveState() with invalid register width, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_005_GUID,
    "Call WriteSaveState() The return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_006_GUID,
    "Call WriteSaveState() with wrong register, the return status should be EFI_NOT_FOUND"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_007_GUID,
    "Call WriteSaveState() with wrong CPU index, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_008_GUID,
    "Call WriteSaveState() with invalid register width, the return status should be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_009_GUID,
    "Call ReadSaveState() with EFI_SMM_SAVE_STATE_REGISTER_PROCESSOR_ID register of a specified CPU in SMM, the return status should be EFI_SUCCESS"
  },
  {
    EFI_TEST_SMMCPUBBTEST_REQUIRED_ASSERTION_010_GUID,
    "Call ReadSaveState() with EFI_SMM_SAVE_STATE_REGISTER_PROCESSOR_ID with invalid width, the return status should be EFI_INVALID_PARAMETER"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmCpuBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_CPU_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmCpuTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmCpuTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

