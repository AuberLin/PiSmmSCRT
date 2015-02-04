/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmHandleProtocolBbTest.c

Abstract:

  Runtime SmmHandleProtocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmHandleProtocolBbTest.h"



SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmHandleProtocolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmHandleProtocol with invalid Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmHandleProtocol with NULL Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmHandlelProtocol with NULL protocol, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_HANDLE_PROTOCOL_CONFORMANCETEST_ASSERTION_004_GUID,
    "Call SmmHandleProtocol with NULL interface, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol still exists."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//



EFI_STATUS
RtSmmHandleProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_HANDLE_PROTOCOL_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmHandleProtocolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmHandleProtocolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

