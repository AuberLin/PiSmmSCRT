/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmiHandlerRegisterBbTest.c

Abstract:

  Runtime SmiHandlerRegister Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmiHandlerRegisterBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmiHandlerRegisterTestAssertionDescription[] = {
  {
    EFI_TEST_SMI_HANDLER_REGISTER_FUNCTION_TEST_ASSERTION_001_GUID,
    "SmiHandlerRegister should register a handler successfully."
  },
  {
    EFI_TEST_SMI_HANDLER_REGISTER_FUNCTION_TEST_ASSERTION_002_GUID,
    "SmiHandlerRegister should register a root handler successfully."
  },

  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmiHandlerRegisterBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMI_HANDLER_REGISTER_FUNCTION_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmiHandlerRegisterTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmiHandlerRegisterTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

