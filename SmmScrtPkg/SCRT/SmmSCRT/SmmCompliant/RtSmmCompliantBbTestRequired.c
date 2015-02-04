/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmCompliantBbTestRequired.c

Abstract:

  Check the required elements in SMST.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmCompliantBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmTestAssertionDescription[] = {
  {
    EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_001_GUID,
    "Signature in the SMST header should be S,M,S,T"
  },
  {
    EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_002_GUID,
    "Revision in the SMST header should be equal or larger than (1<<16) | (0x00)"
  },
  {
    EFI_TEST_SMMCOMPLIANTBBTESTREQUIRED_ASSERTION_003_GUID,
    "SmmReadyToLock protocol must exist"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmCompliantBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_COMPLIANT_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmTestAssertionDescription);
  }
  
  //
  // invoke test SMI handler again with ACPI table.
  //
  Status = InvokeTestSmiHandlerViaAcpiTable (vRT, &TestGuid, gSmmTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

