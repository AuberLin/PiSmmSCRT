/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmPciRootBridgeIoBbTestRequired.c

Abstract:

  Runtime SmmPciRootBridgeIo Protocol Test.

--*/

//
// Includes
//

#include "RtSmmTestLib\RtSmmTestLib.h"
#include "RtSmmPciRootBridgeIoBbTest.h"

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmPciRootBridgeIoFuncTestAssertionDescription[] = {
  {
    EFI_TEST_SMMPCIROOTBRIDGEIOBBTESTSTRESS_ASSERTION_030_GUID,
    "EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.GetAttributes - Get Supported attribute status must be EFI_SUCCESS",
  },
  {
    EFI_TEST_SMMPCIROOTBRIDGEIOBBTESTSTRESS_ASSERTION_031_GUID,
    "EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - Set Supported attribute status must be EFI_SUCCESS",
  },
  {
    EFI_TEST_SMMPCIROOTBRIDGEIOBBTESTSTRESS_ASSERTION_032_GUID,
    "EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - Set Supported attribute the attributes should be really set.",
  },
  {
    EFI_TEST_SMMPCIROOTBRIDGEIOBBTESTSTRESS_ASSERTION_033_GUID,
    "EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - Set UnSupported attribute status must be EFI_UNSUPPORTED",
  },
  {
    EFI_TEST_SMMPCIROOTBRIDGEIOBBTESTSTRESS_ASSERTION_034_GUID,
    "EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - Set UnSupported attribute the attributes should remain unchanged",
  },
  SMM_TEST_NULL_GUID
};

SMM_BB_TEST_ASSERTION_DESCRIPTION gSmmPciRootBridgeIoConfTestAssertionDescription[] = {
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_001_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollMem() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_002_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollMem() - With Width as EfiPciWidthFifoUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_003_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollMem() - With Width as EfiPciWidthFillUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_004_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollMem() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_005_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollMem() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_006_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollIo() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_007_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollIo() - With Width as EfiPciWidthFifoUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_008_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollIo() - With Width as EfiPciWidthFillUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_009_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollIo() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_010_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.PollIo() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_011_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Read() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_012_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Read() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_013_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Read() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_014_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Write() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_015_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Write() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_016_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Mem.Write() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_017_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Read() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_018_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Read() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_019_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Read() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_020_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Write() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_021_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Write() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_022_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Io.Write() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_023_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Read() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_024_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Read() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_025_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Read() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_026_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Write() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_027_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Write() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_028_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Pci.Write() - With Result as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_029_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.CopyMem() - With Width as EfiPciWidthMaximum the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_030_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.CopyMem() - With Width as -1 the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_031_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.CopyMem() - With Width as EfiPciWidthFifoUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_032_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.CopyMem() - With Width as EfiPciWidthFillUintX the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_033_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih invalid Operation the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_034_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih invalid Operation the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_035_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih HostAddress as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_036_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih NumberOfBytes as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_037_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih DeviceAddress as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_038_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.Map - Map wih Mapping as NULL the return Status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_039_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.AllocateBuffer - with Invalid memory type -1 the status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_040_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.AllocateBuffer - with Invalid memory type status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_041_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.AllocateBuffer - with HostAddress as NULL the status must be EFI_INVALID_PARAMETER"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_042_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.AllocateBuffer - with invalid Attributes the status must be EFI_UNSUPPORTED"
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_043_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.GetAttributes - with both Supprts and Atttributes as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_044_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - with unsupported attributes the return status must be EFI_UNSUPPORTED."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_045_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - with unsupported attributes the return status must be EFI_UNSUPPORTED."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_046_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - with more than one attributes that need a resource the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_047_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_WRITE_COMBINE with ResourceBase as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_048_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_WRITE_COMBINE with ResourceLength as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_049_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_CACHED with ResourceBase as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_050_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_CACHED with ResourceLength as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_051_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_DISABLE with ResourceBase as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  {
    EFI_TEST_SMM_PCI_ROOT_BRIDGE_IO_BBTEST_CONF_ASSERTION_052_GUID,
    "EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL.SetAttributes - MEMORY_DISABLE with ResourceLength as NULL the return status must be EFI_INVALID_PARAMETER."
  },
  SMM_TEST_NULL_GUID
};

 
//
// External functions implementation
//

EFI_STATUS
RtSmmPciRootBridgeIoFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_PCI_ROOT_BRIDGE_IO_STRESS_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmPciRootBridgeIoFuncTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmPciRootBridgeIoFuncTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}


EFI_STATUS
RtSmmPciRootBridgeIoConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  )
/*++

Routine Description:

  Check the required elements

--*/
{
  EFI_STATUS  Status;
  EFI_GUID  TestGuid = SMM_PCI_ROOT_BRIDGE_IO_CONFORMANCE_BB_TEST_GUID;

  //
  // invoke test SMI handler which contains test code for SMM services and protocols.
  //
  Status = InvokeTestSmiHandler (vRT, &TestGuid, gSmmPciRootBridgeIoConfTestAssertionDescription);
  //
  // Collect test result and generate test report
  //
  if (Status == EFI_SUCCESS) {
    CheckSmmTestResult (gSmmPciRootBridgeIoConfTestAssertionDescription);
  }
  
  //
  // Done
  //
  return Status;
}