/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmUninstallProtocolBbTest.c

Abstract:

  Runtime SmmUninstallProtocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmUninstallProtocolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmUninstallProtocolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmUninstallProtocolInterface must succeed when uninstall an EFI_NATIVE_INTERFACE type protocol from a new handle."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test environment corrupted."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The test handle is still exist after one of the test protocol uninstalled from it."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The test protocol not exist on any handle."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "The test protocol could be not be located via the test handle."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID,
    "Another test protocol still exist on the test handle."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_006_GUID,
    "SmmUninstallProtocolInterface must succeed when uninstall another EFI_NATIVE_INTERFACE type protocol from the test handle."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_007_GUID,
    "Another test protocol not exist on any handle."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_008_GUID,
    "Test handle is not valid any more after all test protocols on it are uninstalled."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test environment corrupted."
  },
  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmUninstallProtocolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmUninstallProtocolInterface with NULL protocol, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmUninstallProtocolInterface with invalid Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmUninstallProtocolInterface with NULL Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_UNINSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID,
    "Call SmmUninstallProtocolInterface to uninstall non-existant protocol, the return status should be EFI_NOT_FOUND."
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
RtSmmUninstallProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_UNINSTALL_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmUninstallProtocolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmUninstallProtocolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmUninstallProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_UNINSTALL_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmUninstallProtocolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmUninstallProtocolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

