/*++

Copyright (c) 2010 - 2013, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmRegProtocolBbTest.c

Abstract:

  Runtime SmmRegProtocolNotify Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmRegProtocolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmRegProtocolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmRegProtocolInterface must succeed when register a callback function for test protocol."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol already exists."
  },
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The notify function is called successfully."
  },
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The new handle could be located via installed test protocol by register notify."
  },
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "If callback function is NULL while Registration exists, it should return EFI_SUCCESS."
  },
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID,
    "If callback function is NULL while Registration exists, callback function should be unregistered."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmRegProtocolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmRegProtocolInterface with NULL GUID, the return status should be EFI_INVALID_PARAMETER."
  },
  //{
  //  EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID,
  //  "Call SmmRegProtocolInterface with NULL callback function, the return status should be EFI_INVALID_PARAMETER."
  //},
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmRegProtocolInterface with NULL Registration, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmRegProtocolInterface with NULL Registration, the return status should be EFI_INVALID_PARAMETER."
  },

  // Add following GUID for conformance test case to check EFI_NOT_FOUND
  {
    EFI_TEST_SMM_REG_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID,
    "Call SmmRegProtocolInterface with NULL call back function and not found registration, the return status should be EFI_NOT_FOUND."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmRegProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_REG_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmRegProtocolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmRegProtocolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmRegProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_REG_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmRegProtocolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmRegProtocolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

