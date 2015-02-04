/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmLocateProtocolBbTest.c

Abstract:

  Runtime SmmLocateProtocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmLocateProtocolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmLocateProtocolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmLocateProtocolInterface must succeed when locate test protocol installed to a new handle."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol already exists."
  },
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The returned protocol interface is executed successfully."
  },
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "SmmLocateProtocolInterface must NOT succeed when locate Registration for test protocol that is not installed after SmmRegisterProtocolNotify() call."
  },
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "SmmLocateProtocolInterface must succeed when locate test protocol installed after SmmRegisterProtocolNotify() call."
  },
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID,
    "SmmLocateProtocolInterface must NOT succeed when locate for test protocol that is not installed."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmLocateProtocolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_LOCATE_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmLocateProtocolInterface with NULL interface, the return status should be EFI_INVALID_PARAMETER."
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
RtSmmLocateProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_LOCATE_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmLocateProtocolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmLocateProtocolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmLocateProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_LOCATE_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmLocateProtocolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmLocateProtocolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

