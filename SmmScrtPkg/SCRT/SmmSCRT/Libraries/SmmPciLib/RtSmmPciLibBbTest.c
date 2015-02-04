/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmPciLibBbTest.c

Abstract:

  Runtime SmmPciLib Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmPciLibBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmPciLibTestAssertionDescription[] = {
  {
    LIB_TEST_SMMS3MISC1_ASSERTION_002_GUID,
    "Call PCI_LIB_ADDRESS"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_003_GUID,
    "Call Pci8"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_004_GUID,
    "Call PciBitField8"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_005_GUID,
    "Call Pci16"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_006_GUID,
    "Call PciBitField16"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_007_GUID,
    "Call Pci32"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_008_GUID,
    "Call PciBitField32"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_009_GUID,
    "Call PciBuffer"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_002_GUID,
    "Conf Pci8"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_003_GUID,
    "Conf PciBitField8"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_004_GUID,
    "Conf Pci16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_005_GUID,
    "Conf PciBitField16"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_006_GUID,
    "Conf Pci32"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_007_GUID,
    "Conf PciBitField32"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_008_GUID,
    "Conf PciReadBuffer"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_009_GUID,
    "Conf PciWriteBuffer"
  },
  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmPciLibBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = RT_SMM_PCILIB_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmPciLibTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmPciLibTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

