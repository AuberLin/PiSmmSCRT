/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmMemAllocLibBbTest.c

Abstract:

  Runtime SmmMemAllocLib Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmMemAllocLibBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmMemAllocLibTestAssertionDescription[] = {
  {
    LIB_TEST_SMMS3MISC1_ASSERTION_002_GUID,
    "Call AllocAlignedRuntimePages"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_003_GUID,
    "Call AllocRuntimePages"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_004_GUID,
    "Call AllocRuntimePool"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_005_GUID,
    "Call AllocRuntimeZeroPool"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_006_GUID,
    "Call AllocRuntimeCopyPool"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_007_GUID,
    "Call ReallocRuntimePool"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_008_GUID,
    "Conf FreePages"
  },

  {
    LIB_TEST_SMMS3MISC1_ASSERTION_009_GUID,
    "Conf AllocAlignedRuntimePages"
  },
  
  {
    LIB_TEST_SMMCONF_ASSERTION_002_GUID,
    "Conf FreeAlignedPages"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_003_GUID,
    "Conf AllocRuntimeCopyPool"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_004_GUID,
    "Conf FreePool"
  },

  {
    LIB_TEST_SMMCONF_ASSERTION_006_GUID,
    "Conf ReallocRuntimePool"
  },


  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmMemAllocLibBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = RT_SMM_MEMALLOCLIB_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmMemAllocLibTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmMemAllocLibTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

