/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmInstallConfigTableBbTest.c

Abstract:

  Runtime SmmInstallConfigTable Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmInstallConfigTableBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmInstallConfigTableFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_001_GUID,
    "SmmInstallConfigurationTable should install a test-GUIDed table successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_002_GUID,
    "The test-GUIDed table should really be installed."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_003_GUID,
    "The CRC32 value of SMST after test-GUIDed table installed should be correct."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_004_GUID,
    "SmmInstallConfigurationTable should update the installed test-GUIDed table successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_005_GUID,
    "The test-GUIDed table should really be updated."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_006_GUID,
    "The CRC32 value of SMST after test-GUIDed table updated should be correct."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_007_GUID,
    "SmmInstallConfigurationTable could remove the installed test-GUIDed table successfully."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_008_GUID,
    "The test-GUIDed table should really be removed."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_FUNCTIONTEST_ASSERTION_009_GUID,
    "The CRC32 value of SMST after test-GUIDed table removed should be correct."
  },

  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmInstallConfigTableConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_CONFORMANCETEST_ASSERTION_001_GUID,
    "Call SmmInstallConfigurationTable with Guid being NULL, the return status should be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_INSTALL_CONFIGURATION_TABLE_CONFORMANCETEST_ASSERTION_002_GUID,
    "Call SmmInstallConfigurationTable with Guid being non-existant, the return status should be EFI_NOT_FOUND."
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmInstallConfigTableFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_INSTALL_CONFIGURATION_TABLE_FUNC_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmInstallConfigTableFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmInstallConfigTableFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

EFI_STATUS
RtSmmInstallConfigTableConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_INSTALL_CONFIGURATION_TABLE_CONF_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmInstallConfigTableConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmInstallConfigTableConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

