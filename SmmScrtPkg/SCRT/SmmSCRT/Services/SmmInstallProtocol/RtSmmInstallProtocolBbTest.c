/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmInstallProtocolBbTest.c

Abstract:

  Runtime SmmInstallProtocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmInstallProtocolBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmInstallProtocolFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmInstallProtocolInterface must succeed when install an EFI_NATIVE_INTERFACE type protocol to a new handle."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol already exists."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The new handle is created successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The new handle could be located via installed test protocol."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "The test protocol could be located via the new handle."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID,
    "The test protocol interface could be executed successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_006_GUID,
    "SmmInstallProtocolInterface must succeed when install an EFI_NATIVE_INTERFACE type protocol to an existed test handle."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_007_GUID,
    "NO new handle is created after installing test protocol onto an existed test handle."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The new handle could be located via installed test protocol."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "The test protocol could be located via the new handle."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_005_GUID,
    "The test protocol interface could be executed successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_008_GUID,
    "SmmInstallProtocolInterface must succeed when install an EFI_NATIVE_INTERFACE type protocol with NULL interface to a new handle."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The new handle is created successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The new handle could be located via installed test protocol."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_FUNCTIONTEST_ASSERTION_004_GUID,
    "The test protocol could be located via the new handle."
  },
  {
    SMM_TEST_GENERIC_FAILURE_GUID,
    "Test protocol already exists."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmInstallProtocolConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmInstallProtocolInterface with invalid interface type, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmInstallProtocolInterface with invalid Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_003_GUID,
    "Call SmmInstallProtocolInterface with NULL Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_004_GUID,
    "Call SmmInstallProtocolInterface to install a test protocol multiple times to the same Handle, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_INSTALL_PROTOCOL_INTERFACE_CONFORMANCETEST_ASSERTION_005_GUID,
    "Call SmmInstallProtocolInterface with NULL Protocol, the return status should be EFI_INVALID_PARAMETER."
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
RtSmmInstallProtocolFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_INSTALL_PROTOCOL_INTERFACE_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmInstallProtocolFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmInstallProtocolFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmInstallProtocolConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_INSTALL_PROTOCOL_INTERFACE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmInstallProtocolConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmInstallProtocolConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

