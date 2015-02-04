/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmIoLibBbTest.c

Abstract:

  Runtime SmmIoLib Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmIoLibBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmIoLibTestAssertionDescription[] = {
  {
    LIB_TEST_SMMMISC1_ASSERTION_002_GUID,
    "Call Io8"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_003_GUID,
    "Call Io16"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_004_GUID,
    "Call Io32"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_005_GUID,
    "Call IoBitField8"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_006_GUID,
    "Call IoBitField16"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_007_GUID,
    "Call IoBitField32"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_008_GUID,
    "Call MmIo8"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_009_GUID,
    "Call MmIo16"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_010_GUID,
    "Call MmIo32"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_011_GUID,
    "Call MmIoBitField8"
  },
  {
    LIB_TEST_SMMMISC1_ASSERTION_012_GUID,
    "Call MmIoBitField16"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_013_GUID,
    "Call MmIoBitField32"
  },
  {
    LIB_TEST_SMMMISC1_ASSERTION_014_GUID,
    "Call MmIoBuffer8"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_015_GUID,
    "Call MmIoBuffer16"
  },
  {
    LIB_TEST_SMMMISC1_ASSERTION_016_GUID,
    "Call MmIoBuffer32"
  },
  {
    LIB_TEST_SMMCONF_ASSERTION_002_GUID,
    "Conf IoBitField8"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_003_GUID,
    "Conf Io16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_004_GUID,
    "Conf IoBitField16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_005_GUID,
    "Conf Io32"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_006_GUID,
    "Conf IoBitField32"
  },

  {
    LIB_TEST_SMMMISC1_ASSERTION_007_GUID,
    "Conf IoBitField8"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_008_GUID,
    "Conf MmIo16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_009_GUID,
    "Conf MmIoBitField16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_010_GUID,
    "Conf MmIo32"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_011_GUID,
    "Conf MmIoBitField32"
  },
  {
    LIB_TEST_SMMCONF_ASSERTION_012_GUID,
    "Conf MmIoBuffer"
  },

  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmIoLibBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = RT_SMM_IOLIB_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmIoLibTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmIoLibTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

