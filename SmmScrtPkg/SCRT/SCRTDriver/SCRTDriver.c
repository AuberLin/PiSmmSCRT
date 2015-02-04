/*++
 Copyright (c) 2009, Intel Corporation
 All rights reserved. 

 This UEFI SCRT ("Software") is furnished under license and may only be used or copied
 in accordance with the terms of that license UEFI Contributor Agreement.
 No license, express or implied, by estoppel or otherwise, to any intellectual property
 rights is granted by this document. The Software is subject to change without notice,
 and should not be construed as a commitment by Intel Corporation to market, license,
 sell or support any product or technology. Unless otherwise provided for in the license
 under which this Software is provided, the Software is provided AS IS, with no warranties
 of any kind, express or implied. Except as expressly permitted by the Software license,
 neither Intel Corporation nor its suppliers assumes any responsibility or liability
 for any errors or inaccuracies that may appear herein.
--*/
/*++

Module Name:

  SCRTDriver.c

--*/

#include "SCRTDriver.h"

CHAR16  *gVarName             = L"UEFIRuntimeVariable";
CHAR16  *gTestRecordName      = L"TestRecord";
EFI_RUNTIME_SERVICES            *VRT;
static EFI_BOOT_SERVICES        *mBS;
static EFI_RUNTIME_SERVICES     *mRT;
static EFI_EVENT                mEfiVirtualNotifyEvent;

EFI_GUID  gRuntimeFuncAddressGuid = RUNTIME_FUNC_ADDRESS_GUID;

//Test results statistics
UINTN NumOfPass = 0;
UINTN NumOfFail = 0;

VOID
EFIAPI
SCRTDriverVirtualNotifyEvent (
  IN EFI_EVENT        Event,
  IN VOID             *Context
  )
{
  EFI_EVENT_NOTIFY  ChildNotify;

  if (Context != NULL) {
    ChildNotify = (EFI_EVENT_NOTIFY) (UINTN) Context;
    ChildNotify (Event, NULL);
  }
}


EFI_STATUS
SCRTRuntimeDriverInit(
  IN EFI_SYSTEM_TABLE        *SystemTable,
  IN EFI_EVENT_NOTIFY        GoVirtualChildEvent
)
{
  EFI_STATUS  Status;
  mBS  = SystemTable->BootServices;
  mRT  = SystemTable->RuntimeServices;
  VRT  = mRT;
  
  Status = mBS->CreateEvent (
                  EFI_EVENT_SIGNAL_VIRTUAL_ADDRESS_CHANGE,
                  EFI_TPL_NOTIFY,
                  SCRTDriverVirtualNotifyEvent,
                  (VOID *)(UINTN)GoVirtualChildEvent,
                  &mEfiVirtualNotifyEvent
                  );
  return Status;
}

EFI_RUNTIMESERVICE
VOID
SCRTDriverClassAddressChangeEvent (
  IN EFI_EVENT        Event,
  IN VOID             *Context
  )
/*++

Routine Description:

  The event handler to change physical address to virtual address

Arguments:

  Event   - The event that be siganlled when virtual address changed
  Context - The pointer of the procedure instance

Returns:

  None

--*/  
{
  //
  // Register a virtual notification event to convert the global pointer variables.
  //
  mRT->ConvertPointer (0, (VOID **)&VRT);
}


EFI_DRIVER_ENTRY_POINT (InitializeSCRTDriver)

EFI_STATUS
InitializeSCRTDriver (
  IN EFI_HANDLE              ImageHandle,
  IN EFI_SYSTEM_TABLE        *SystemTable
  )
/*++

Routine Description:

  This function does initialization for SCRTDriver

Arguments:

  ImageHandle   - The firmware allocated handle for the EFI image.
  SystemTable   - A pointer to the EFI System Table.

Returns:
  
  Status code
  
--*/  
{
  UINTN                Size;
  UINTN                FuncAddr;
  EFI_STATUS           Status;
  SCRT_STUB_TABLE      *StubTable;
  
  //
  // Intialize Runtime Driver Lib and Register a virtual notification event.
  //
  SCRTRuntimeDriverInit (SystemTable,SCRTDriverClassAddressChangeEvent);

  FuncAddr = (UINTN) RuntimeTestFunc;

  Size = sizeof(SCRT_STUB_TABLE);
  Status  = mBS->AllocatePool (EfiRuntimeServicesData, Size, (VOID **) &StubTable);
  if (EFI_ERROR(Status)){
    return Status;
  }
  StubTable->Signature = SCRT_STUB_TABLE_SIGNATURE;
  StubTable->FuncAddr  = FuncAddr;
  
  Status = mBS->InstallConfigurationTable (&gRuntimeFuncAddressGuid, (VOID*)StubTable);
  if (EFI_ERROR(Status)){
    return Status;
  }
  return EFI_SUCCESS;
}


VOID
EFIAPI
RuntimeTestFunc (
  UINTN    HandOffAddr
  )
/*++

Routine Description:

  Perform runtime service test in a virtual addressing mode.
  
Arguments:

  NONE

Returns:

  NONE
  
--*/   
{
  CONF_INFO  ConfigData;
  EFI_STATUS  Status;
  //
  // Parse runtime hand off data
  //
  ConsumeHandOff(HandOffAddr, &ConfigData);
  Printf("BitMap = 0x%x\n", ConfigData.InfoData);
  if (ConfigData.BitMap.Signature != CONFIGURE_INFO_SIGNATURE) {
    Printf ("Find Configuration Data Corrupte, Hang!!\n");
    EFI_DEADLOOP();
  } 
  //
  // Dump Runtime Table
  //
  //DumpRuntimeTable();
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT Begin ~~~~~~~~~~~~~~~~~\n\n\n");
  Status = RtSmmCompliantBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT Compliant Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmCpuBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT Cpu Protocol Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmGpiDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT GpiDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmIoTrapDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT IoTrapDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmPciRootBridgeIoFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT PciRootBridgeIo Protocol Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmPciRootBridgeIoConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT PciRootBridgeIo Protocol Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmPeriTimerDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT PeriTimerDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmPowerButtonDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT PowerButtonDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmStdbyButtDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT StdbyButtDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmSwDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SwDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmSxDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SxDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmRSCHandlerBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT StatusCode Handler Protocol Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmS3SaveStateFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT S3SaveStateFunc Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmS3SaveStateConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT S3SaveStateConf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmStatusCodeBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT ReportStatusCode Protocol Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);



  Status = RtSmiHandlerRegisterBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmiHandlerRegister Service Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmiHandlerUnRegisterFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmiHandlerUnRegister Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmiHandlerUnRegisterConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmiHandlerUnRegister Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmiManageFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmiManage Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmiManageConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmiManage Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmAllocatePagesFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmAllocatePages Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmAllocatePagesConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmAllocatePages Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmAllocatePoolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmAllocatePool Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmAllocatePoolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmAllocatePool Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmFreePagesFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmFreePages Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmFreePagesConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmFreePages Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmFreePoolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmFreePool Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmFreePoolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmFreePool Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  
  Status = RtSmmHandleProtocolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmHandleProtocol Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmInstallConfigTableFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmInstallConfigTable Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmInstallConfigTableConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmInstallConfigTable Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmInstallProtocolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmInstallProtocol Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmInstallProtocolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmInstallProtocol Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmIoConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmIo Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmLocateHandleConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmLocateHandle Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmLocateProtocolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmLocateProtocol Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmLocateProtocolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmLocateProtocol Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmRegProtocolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmRegisterProtocolNotify Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmRegProtocolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmRegisterProtocolNotify Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmStartupThisApFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmStartupThisAp Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmStartupThisApConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmStartupThisAp Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmUninstallProtocolFuncBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmUninstallProtocol Service Func Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmUninstallProtocolConfBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT SmmUninstallProtocol Service Conf Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);


  Status = RtSmmMemAllocLibBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT MemAlloc Lib Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  // May need different test address on different platforms.
  Status = RtSmmPciLibBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT Pci Lib Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmIoLibBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT IO Lib Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

  Status = RtSmmPeriodicSmiLibBbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT PeriodicSmi Lib Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);
  
  InitVariableRecord(&ConfigData);
  Printf ("==================Variable Services Test Start==================\n\n");
  EfiVariableTestVirtual(&ConfigData);
  Printf ("===================Variable Services Test End===================\n\n\n");

  Printf ("*******************Test Summary*********************\n");
  Printf ("*******************PASS - %d\n", NumOfPass);
  Printf ("*******************FAIL  - %d\n", NumOfFail);
  Printf ("***************************************************\n");

  Status = RtSmmUsbDispatch2BbTest(VRT);
  Printf ("~~~~~~~~~~~~~~~ SMM SCRT UsbDispatch2 Status - %r ~~~~~~~~~~~~~~~~~\n\n\n", Status);

/*
  Printf ("====================Time Services Test Start====================\n\n");
  EfiTimeTestVirtual(&ConfigData);
  Printf ("=====================Time Services Test End=====================\n\n\n");

  Printf ("==================Capsule Services Test Start===================\n\n");
  EfiCapsuleTestVirtual(&ConfigData);
  Printf ("===================Capsule Services Test End====================\n\n\n");

  Printf ("====================Misc Services Test Start====================\n\n");
  EfiMiscTestVirtual(&ConfigData);
  Printf ("=====================Misc Services Test End=====================\n\n\n");
*/
  Printf ("===================Reset Services Test Start=================\n\n");
  EfiResetTestVirtual(&ConfigData);

}
