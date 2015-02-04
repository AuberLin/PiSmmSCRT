/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmS3SaveStateBbTest.c

Abstract:

  Runtime SmmS3SaveState Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmS3SaveStateBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmS3SaveStateFuncTestAssertionDescription[] = {
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_001_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label at the begining of the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_002_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label - label2 at the end of the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_003_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to find Label1 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_004_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to find Label2 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_005_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label3 after Label1, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_006_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to find label3 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_007_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - Label1 should be before label3 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_008_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label4 before Label2, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_009_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to find label4 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_010_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - Label2 should be after label4 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_011_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label at the begining of the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_012_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - to creat a label - label2 at the end of the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_013_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - Label1 should be before label2 in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_014_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - compare two same positions (Label1 and Label1)in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_015_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - compare two same positions (Label2 and Label2)in the boot script table, should return EFI_SUCCESS",
  },
  {
    EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_016_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - Label2 should be after label1 in the boot script table, should return EFI_SUCCESS",
  },
  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmS3SaveStateConfTestAssertionDescription[] = {
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_001_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Write() - with a invalid OpCode(0xFF), should return EFI_INVALID_PARAMETER",
  },
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_002_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Write() - with a invalid OpCode(from 0x11 to 0x 79), should return EFI_INVALID_PARAMETER",
  },
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_003_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Insert() - with a invalid OpCode(0xFF), should return EFI_INVALID_PARAMETER",
  },
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_004_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Insert() - with a invalid OpCode(from 0x11 to 0x 79), should return EFI_INVALID_PARAMETER",
  },
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_005_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Label() - a not exist Lable and CreateifNotFound was FALSE, should return EFI_NOT_FOUND",
  },
  {
    EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_006_GUID,
    "EFI_S3_SAVE_STATE_PROTOCOL.Compare() - with two invalid positions, should return EFI_NOT_FOUND",
  },
  SMM_TEST_NULL_GUID
};

 
//
// External functions implementation
//

EFI_STATUS
RtSmmS3SaveStateFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = S3SAVESTATE_PROTOCOL_FUNCTION_AUTO_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmS3SaveStateFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmS3SaveStateFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}


EFI_STATUS
RtSmmS3SaveStateConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = S3SAVESTATE_PROTOCOL_CONFORMANCE_AUTO_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmS3SaveStateConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmS3SaveStateConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}