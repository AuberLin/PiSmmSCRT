/*++
 Copyright (c) 2012, Intel Corporation
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

  SCRTApp.c

--*/

#include "SCRTApp.h"
#include "ParseConf.h"

#include "SmmCommunication.h"
#include "SmmControl2.h"

EFI_GUID  gRuntimeFuncAddressGuid = RUNTIME_FUNC_ADDRESS_GUID;

EFI_GUID gEfiSmmCommunicationProtocolGuid = EFI_SMM_COMMUNICATION_PROTOCOL_GUID;
EFI_GUID gEfiSmmControl2ProtocolGuid = EFI_SMM_CONTROL2_PROTOCOL_GUID;

// {CA25A45D-491E-4735-A6E4-34A2C8E0AB36}
#define SMM_COMMUNICATE_PROTOCOL_ADDRESS_GUID \
{ 0xca25a45d, 0x491e, 0x4735, { 0xa6, 0xe4, 0x34, 0xa2, 0xc8, 0xe0, 0xab, 0x36 } }

EFI_GUID  gSmmCommunicateProtocolAddressGuid = SMM_COMMUNICATE_PROTOCOL_ADDRESS_GUID;

CHAR16  *gSmmCommunicationProtocolVarName             = L"SmmCommuProtoAddressVar";
CHAR16  *gSmmCommunicationBufferVarName             = L"SmmCommuBufAddressVar";
CHAR16  *gSmmControl2ProtocolVarName             = L"SmmControl2ProtoAddressVar";
CHAR16  *gSmmCommunicationAcpiTableAddressVarName             = L"SmmCommuAcpiTableAddressVar";

VOID
PrintUsage ( 
  VOID
  )
/*++

Routine Description:

  Print usage information for this utility.
  
Arguments:

  NONE

Returns:

  NONE
  
--*/  
{
  Print(L"SCRTApp Usage:\n");
  Print(L"  -f  FileName  FileName is test case configuration file\n");
  Print(L"  -g  FileName  FileName is test case result/log file\n");
  Print(L"Example:\n");
  Print(L"SCRTApp -f SCRT.conf\n");
  Print(L"SCRTApp -g SCRT.log\n");
}

/**
  Get SMM communication ACPI table address.

  @return SMM communication ACPI table address.
**/
EFI_PHYSICAL_ADDRESS
GetSmmCommunicationAcpiTableAddress (
  VOID
  )
{
  EFI_ACPI_4_0_ROOT_SYSTEM_DESCRIPTION_POINTER  *Rsdp;
  EFI_ACPI_DESCRIPTION_HEADER                   *Rsdt;
  EFI_ACPI_DESCRIPTION_HEADER                   *Xsdt;
  UINTN                                         Index;
  UINT32                                        *TableAddress;
  UINT64                                        *XTableAddress;
  UINTN                                         TableCount;
  EFI_SMM_COMMUNICATION_ACPI_TABLE              *SmmAcpi;

  Rsdp = NULL;
  for (Index = 0; Index < ST->NumberOfTableEntries; Index++) {
    if ((CompareGuid (&(ST->ConfigurationTable[Index].VendorGuid), &gEfiAcpi20TableGuid) == 0) ||
        (CompareGuid (&(ST->ConfigurationTable[Index].VendorGuid), &gEfiAcpiTableGuid) == 0)) {
      //
      // A match was found.
      //
      Rsdp = (EFI_ACPI_4_0_ROOT_SYSTEM_DESCRIPTION_POINTER *) ST->ConfigurationTable[Index].VendorTable;
      break;
    }
  }

  if (Rsdp == NULL) {
    return 0;
  }

  Rsdt = (EFI_ACPI_DESCRIPTION_HEADER *) (UINTN) Rsdp->RsdtAddress;
  TableCount = (Rsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) / sizeof(UINT32);
  TableAddress = (UINT32 *)(Rsdt + 1);
  for (Index = 0; Index < TableCount; Index++) {
    SmmAcpi = (EFI_SMM_COMMUNICATION_ACPI_TABLE *)(UINTN)TableAddress[Index];
    if ((SmmAcpi->UefiAcpiDataTable.Header.Signature == EFI_ACPI_4_0_UEFI_ACPI_DATA_TABLE_SIGNATURE) &&
        (SmmAcpi->UefiAcpiDataTable.Header.Length == sizeof (EFI_SMM_COMMUNICATION_ACPI_TABLE)) &&
        (CompareGuid (&(SmmAcpi->UefiAcpiDataTable.Identifier), &gEfiSmmCommunicationProtocolGuid)  == 0)) {
      return (EFI_PHYSICAL_ADDRESS)(UINTN)SmmAcpi;
    }
  }

  if (Rsdp->Revision >= 2) {
    Xsdt = (EFI_ACPI_DESCRIPTION_HEADER *) (UINTN) Rsdp->XsdtAddress;
    TableCount = (Rsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) / sizeof(UINT64);
    XTableAddress = (UINT64 *)(Xsdt + 1);
    for (Index = 0; Index < TableCount; Index++) {
      SmmAcpi = (EFI_SMM_COMMUNICATION_ACPI_TABLE *)(UINTN)XTableAddress[Index];
      if ((SmmAcpi->UefiAcpiDataTable.Header.Signature == EFI_ACPI_4_0_UEFI_ACPI_DATA_TABLE_SIGNATURE) &&
          (SmmAcpi->UefiAcpiDataTable.Header.Length == sizeof (EFI_SMM_COMMUNICATION_ACPI_TABLE)) &&
          (CompareGuid (&(SmmAcpi->UefiAcpiDataTable.Identifier), &gEfiSmmCommunicationProtocolGuid) == 0)) {
        return (EFI_PHYSICAL_ADDRESS)(UINTN)SmmAcpi;
      }
    }
  }

  return 0;
}



EFI_STATUS
InitializeSCRT (
  IN EFI_HANDLE           ImageHandle,
  IN EFI_SYSTEM_TABLE     *SystemTable
  )
/*++

Routine Description:

  Go to virtual mode to test the UEFI Runtime Services.

Arguments:

  ImageHandle  - Handle for the image of this driver
  SystemTable  - Pointer to the EFI System Table

Returns:

  EFI_STATUS

--*/
{
  UINTN                   MemoryMapSize;
  UINTN                   VirtualMapSize;
  UINTN                   MapKey;
  UINTN                   DescriptorSize;
  UINTN                   VirtualFunc;
  UINTN                   VirtualFuncBak;
  UINT32                  DescriptorVersion;
  VOID                    *FileBuffer;
  UINTN                   FileSize;
  UINT32                  ArgIndex;
  CHAR16                  InfFileName[200];
  BOOLEAN                 ConfigFlag;
  BOOLEAN                 GenLogFlag;
  EFI_STATUS              Status;
  MEMORY_FILE             InfMemoryFile;
  EFI_FILE_INFO           *FileInfo;
  CONF_INFO               ConfInfo;
  EFI_FILE_HANDLE         FileHandle;
  EFI_MEMORY_DESCRIPTOR   *MemoryMap;
  EFI_MEMORY_DESCRIPTOR   *TempVirtualMemoryMap;
  EFI_MEMORY_DESCRIPTOR   *VirtualMemoryMap;
  UINTN                   HandOffAddr;
  UINTN                   Index;
  SCRT_STUB_TABLE         *StubTable;
  BOOLEAN                 SctTableFound;

  EFI_SMM_COMMUNICATION_PROTOCOL   *SmmComm;
  VOID*  CommunicationBuffer;
  EFI_SMM_CONTROL2_PROTOCOL  *SmmControl2;
  EFI_PHYSICAL_ADDRESS  SmmCommAcpiTable;
  
  VirtualFunc           = 0;
  VirtualMapSize        = 0;
  MemoryMapSize         = 0;
  MemoryMap             = NULL;
  FileHandle            = NULL;
  FileInfo              = NULL;
  FileBuffer            = NULL;
  ConfigFlag            = FALSE;
  GenLogFlag            = FALSE;
  SctTableFound         = FALSE;
  HandOffAddr            = 0;

  ConfInfo.InfoData = 0;

  EFI_SHELL_APP_INIT (ImageHandle, SystemTable);
  
  Status = LibFilterNullArgs ();
  if (EFI_ERROR (Status)) {
    return Status;
  }

  //
  // Initialize Configuration File Name
  //
  UnicodeStrCpy (InfFileName, L"");

  //
  // Parse the arguments
  //
  ArgIndex = (UINT32)SI->Argc;

  if ((ArgIndex != 3) || ((UnicodeStrCmp(SI->Argv[1], L"-f")) && (UnicodeStrCmp(SI->Argv[1], L"-g")))) {
    Print(L"SCRTApp: invalid option\n");
    PrintUsage ();
    return EFI_INVALID_PARAMETER;
  } else {
    UnicodeStrCpy (InfFileName, SI->Argv[2]);
    if (UnicodeStrCmp(SI->Argv[1], L"-g") == 0)
      GenLogFlag = TRUE;
    else
      ConfigFlag = TRUE;
  }


  if (GenLogFlag) {
    SCRTLogProcess(InfFileName);
  } else {   

    //
    // Open the Configuration file
    //  
    Status = LibOpenFileByName (
               InfFileName,
               &FileHandle,
               EFI_FILE_MODE_READ,
               0
               );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to open the configuration file\n");     
      return Status;
    }
  
    //
    // If the file is directory, abort
    //
    FileInfo = LibGetFileInfo (FileHandle);
    if (FileInfo == NULL) {
      Print(L"Fail to open the configuration file\n");     
      return EFI_ABORTED;  
    } else if (FileInfo->Attribute & EFI_FILE_DIRECTORY) {
      Print(L"Fail to open the configuration file\n");     
      return EFI_ABORTED;
    }

    //
    // Malloc memory for read file.
    //
    FileBuffer = AllocatePool (CONF_FILE_SIZE);
    if (FileBuffer == NULL) {
      return EFI_OUT_OF_RESOURCES;
    }
  
    FileSize   = CONF_FILE_SIZE;
    Status     = LibReadFile (FileHandle, &FileSize, FileBuffer);
    if (!EFI_ERROR (Status) && (FileSize == 0)) {
      return EFI_NOT_FOUND; 
    }
  
    //
    // Initialize info file structures
    //
    InfMemoryFile.FileImage           = FileBuffer;
    InfMemoryFile.CurrentFilePointer  = FileBuffer;
    InfMemoryFile.Eof                 = (VOID*)((UINTN)FileBuffer + FileSize);
  
    //
    // Parse the FV inf file for header information
    //
    ParseConf (&InfMemoryFile, &ConfInfo);

    for (Index = 0; Index < ST->NumberOfTableEntries; Index++) {
      if (EfiCompareGuid (&gRuntimeFuncAddressGuid, &(ST->ConfigurationTable[Index].VendorGuid))) {
        StubTable = ST->ConfigurationTable[Index].VendorTable;
        if (StubTable->Signature != SCRT_STUB_TABLE_SIGNATURE) {
          Print(L"Find Corrupted SCRT Table!\n");
          EFI_DEADLOOP();
        } else {
          SctTableFound =TRUE;
          VirtualFunc = (UINTN)StubTable->FuncAddr;
          Print(L"Find RuntimeFunc @ 0x%x registered in SCRT Table\n",VirtualFunc);        
        }
      }
    }

    if (!SctTableFound) {
      Print(L"Fail to find SCRT Table!\n");
      EFI_DEADLOOP();
    }
  
    //1. Locate DoCommunicate Protocol and save its entrypoint into variable
    Status = BS->LocateProtocol (
                   &gEfiSmmCommunicationProtocolGuid,
                   NULL,
                   &SmmComm
                   );
    if (EFI_ERROR (Status)) {
      Print(L"Unable to find SMM communicate protocol!\n");
      return Status;
    }

	Status = RT->SetVariable (
                    gSmmCommunicationProtocolVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS,                       
                    8,                  
                    &SmmComm                    
                    );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to save address of SMM communicate protocol!\n");
      return Status;
    }

    //2. Allocate Max Communicate Buffer as EfiRuntimeServicesData type, and save its address into variable.
	Status = BS->AllocatePool (
                   EfiRuntimeServicesData,
                   MAX_COMMUNICATION_BUFFER_SIZE,
                   &CommunicationBuffer
                   );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to allocate SMM communicate buffer!\n");
      return Status;
    }

    Status = RT->SetVariable (
                    gSmmCommunicationBufferVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS,                       
                    8,                  
                    &CommunicationBuffer                    
                    );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to save address of SMM communicate buffer!\n");
      return Status;
    }
    //
    // Prepare for the test of ACPI table based SMM communication between Non-firmware agents and SMM
    //
        
    //1. Locate SmmControl2 Protocol and save its interface address into variable
    Status = BS->LocateProtocol (
                   &gEfiSmmControl2ProtocolGuid,
                   NULL,
                   &SmmControl2
                   );
    if (EFI_ERROR (Status)) {
      Print(L"Unable to find SMM control2 protocol!\n");
      goto SkipAcpiTableTest;
    }

	Status = RT->SetVariable (
                    gSmmControl2ProtocolVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS,                       
                    8,                  
                    &SmmControl2                    
                    );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to save address of SMM control2 protocol!\n");
      return Status;
    }
      //
      // extra steps for ACPI table based SMM communication test, look for related ACPI table first.
      //
    SmmCommAcpiTable = GetSmmCommunicationAcpiTableAddress();
        if (SmmCommAcpiTable == 0) {
          Print(L"SMM communicate ACPI Table NOT Found!\n");
          goto SkipAcpiTableTest;
        } else {
          Print(L"Find SMM communication ACPI Table @ 0x%x \n", SmmCommAcpiTable);        
        }
   
    //2. save ACPI table address into variable.
    Status = RT->SetVariable (
                    gSmmCommunicationAcpiTableAddressVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS,                       
                    sizeof(SmmCommAcpiTable),                  
                    &SmmCommAcpiTable
                    );
    if (EFI_ERROR (Status)) {
      Print(L"Fail to save address of SMM communicate ACPI table!\n");
      return Status;
    }
  
  SkipAcpiTableTest:      
    //
    // Change RuntimeTestFunc physical address to virtual address in advance. Each Arch, IA32, X64 
    // and IPF has its own strategy.
    //
    VirtualFuncBak = VirtualFunc;
    ConvertRuntimeFuncPtr(&VirtualFunc);
  
    //
    // Allocate memory prior to GetMemoryMap. IA32/X64 needs memory for pagetables, and IPF needs for IVA.
    //
    Status = DoMemoryAllocation(VirtualFuncBak);
    Print(L"Try to allocate specific memory for SCRT. Status - %r\n", Status);
    //
    // Prepare runtime hand-off information.
    //
    RuntimeHandOff(&ConfInfo, &HandOffAddr);
    GetUARTAddressFromConf(&InfMemoryFile, (RUNTIME_HANDOFF *) HandOffAddr);
    //
    // Don't use FileBuffer any more, Free it. FileBuffer is used by InfMemoryFile.
    //
    FreePool (FileBuffer);
    //
    // Patch page table for MMIO UART range to match the FixAddress operation in SCRT driver.
    //
    if (((RUNTIME_HANDOFF *)HandOffAddr)->DebuggerInfo.MmioFlag)
    {
      PatchPageTableForMmioRange(((RUNTIME_HANDOFF *)HandOffAddr)->DebuggerInfo.MmioBase);
    }
  
    //
    // First call GetMemoryMap() to query the current System MemoryMap Size.
    //
    BS->GetMemoryMap (
          &MemoryMapSize,
          MemoryMap,
          &MapKey,
          (VOID *) &DescriptorSize,
          (VOID *) &DescriptorVersion
          );
    //
    // The memory size needs add a constant, because there are two AllocatePool()
    // before the second GetMemoryMap(), the action of allocate pool will increase
    // the MemoryMapSize. The constant of 1024 is enough.
    //
    MemoryMapSize += 1024;
  
    Status = BS->AllocatePool (
                  EfiRuntimeServicesData,
                  MemoryMapSize,
                  &MemoryMap
                  );
    if (EFI_ERROR (Status)) {
      return Status;
    }
  
    Status = BS->AllocatePool (
                  EfiRuntimeServicesData,
                  MemoryMapSize,
                  &VirtualMemoryMap
                  );
    if (EFI_ERROR (Status)) {
      return Status;
    }

    Status = BS->GetMemoryMap (
                  &MemoryMapSize,
                  MemoryMap,
                  &MapKey,
                  (VOID *) &DescriptorSize,
                  (VOID *) &DescriptorVersion
                  );
    if (EFI_ERROR (Status)) {
      return Status;
    }
  
    TempVirtualMemoryMap = VirtualMemoryMap;
    ZeroMem ((VOID *) VirtualMemoryMap, MemoryMapSize);
  
    //
    // Change Runtime Usage MemoryMap entry from physical address to virtual address.
    // Each Arch, IA32, X64 and IPF has its own strategy. 
    //
    PrepareVirtualAddressMap (MemoryMapSize,DescriptorSize,MemoryMap,TempVirtualMemoryMap, &VirtualMapSize);
  
    //
    // Call ExitBootServices to terminate all boot services.
    //
    Status = BS->ExitBootServices (ImageHandle, MapKey);
  
    if (EFI_ERROR (Status)) {
      return Status;
    }

    //
    // Call VirtualAddressMap to change the address of the runtime components of the firmware 
    // to the new virtual address.
    //
    Status = RT->SetVirtualAddressMap (
                  VirtualMapSize,
                  DescriptorSize,
                  DescriptorVersion,
                  VirtualMemoryMap
                  );
  
    if (EFI_ERROR (Status)) {
      return Status;
    }
  
    //
    // Enable Virtual addressing mode to invoke Runtime Test Function.
    //
    JumpVirtualMode(VirtualFunc, HandOffAddr);
  
    //
    // Should never be here
    //

  }

  return EFI_SUCCESS;
}
