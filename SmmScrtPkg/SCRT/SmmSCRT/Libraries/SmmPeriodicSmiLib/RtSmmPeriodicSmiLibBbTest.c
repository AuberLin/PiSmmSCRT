/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmPeriodicSmiLibBbTest.c

Abstract:

  Runtime SmmPeriodicSmiLib Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmPeriodicSmiLibBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmPeriodicSmiLibTestAssertionDescription[] = {
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_001_GUID,
    "Call PeriodicSmiSupportedTickPeriod() to get supported SMI ticks"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_002_GUID,
    "The list of supported tick rates that must be sorted largest to smallest terminated by a 0"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_003_GUID,
    "Call PeriodicSmiExecutionTime() outside of periodic SMI handler should return 0"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_004_GUID,
    "Call PeriodicSmiExit() outside of periodic SMI handler should just return"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_005_GUID,
    "Call PeriodicSmiYield() outside of periodic SMI handler should return 0"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_006_GUID,
    "Call PeriodicSmiDisable() outside of periodic SMI handler should return FALSE"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_007_GUID,
    "Call PeriodicSmiEnable() with NULL DispatchFunction should return EFI_INVALID_PARAMETER"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_008_GUID,
    "Call PeriodicSmiEnable() with unsupported tick rate should return EFI_UNSUPPORTED"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_009_GUID,
    "Call PeriodicSmiEnable() with invalid Cpu index should return EFI_INVALID_PARAMETER"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_010_GUID,
    "Call PeriodicSmiEnable() with very large stack should return EFI_OUT_OF_RESOURCES"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_011_GUID,
    "Call PeriodicSmiEnable() at rate below 10 seconds should return EFI_SUCCESS"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_012_GUID,
    "PeriodicSmi10s() direct return"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_013_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiExit()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_014_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiYield()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_015_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiYield() before PeriodicSmiExit()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_016_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiExit() after PeriodicSmiYield()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_017_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiExecutionTime()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_018_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiYield() before PeriodicSmiExecutionTime()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_019_GUID,
    "PeriodicSmi10s() invoke PeriodicSmiExecutionTime() after PeriodicSmiYield()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_020_GUID,
    "Calling PeriodicSmiEnable() with PeriodicSmi1s() direct return and disabled by calling PeriodicSmiDisable()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_021_GUID,
    "Calling PeriodicSmiEnable() with PeriodicSmi1s() and calling PeriodicSmiExit()"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_022_GUID,
    "TBD"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_023_GUID,
    "TBD"
  },
  {
    LIB_TEST_SMMPERIODICSMI_ASSERTION_024_GUID,
    "Calling PeriodicSmiEnable() with PeriodicSmi10msCpuSpecific() on each logic CPU"
  },

  SMM_TEST_NULL_GUID
};
 
//
// External functions implementation
//

EFI_STATUS
RtSmmPeriodicSmiLibBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = RT_SMM_PERIODICSMILIB_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmPeriodicSmiLibTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmPeriodicSmiLibTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}

