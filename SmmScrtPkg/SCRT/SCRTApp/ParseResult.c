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

  ParseResult.c

--*/

#include "SCRTApp.h"
#include "ParseConf.h"

#pragma pack(1)

typedef union _VAR_INFO
{
  struct {
    UINT16 SetVariable        : 1;
    UINT16 GetVariable        : 1;
    UINT16 GetNextVariable    : 1;
    UINT16 QueryVariable      : 1;
    UINT16 GetTime            : 1;
    UINT16 SetTime            : 1;
    UINT16 SetWakeupTime      : 1;
    UINT16 GetWakeupTime      : 1;
    UINT16 QueryCapsule       : 1;
    UINT16 UpdateCapsule      : 1;
    UINT16 GetNextCount       : 1;
    UINT16 ColdReset          : 1;
    UINT16 WarmReset          : 1;
    UINT16 ShutDown           : 1;
    UINT16 Reserved           : 2;
  } BitMap;
  UINT16   TestData;
} VAR_INFO;

typedef struct _TEST_RECORD
{
  VAR_INFO Request;
  VAR_INFO  Result;
} TEST_RECORD;

#pragma pack()

CHAR16  *gTestRecordName      = L"TestRecord";
#define  TEST_RECORD_GUID    \
{ 0x6205d3e7, 0x9bde, 0x4e81, {0x8a, 0xb8, 0xf4, 0x5f, 0xa7, 0xed, 0x46, 0x6}}


EFI_STATUS
GetVariableRecord (
  TEST_RECORD      *TestRecord
  )
{
  UINTN         DataSize;
  UINT32        VariableAttr;
  EFI_STATUS    Status;
  EFI_GUID      VariableTestGuid = TEST_RECORD_GUID;

  VariableAttr = (EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS);

  DataSize     = sizeof(TEST_RECORD);
  //
  // get the record variable.
  //
  Status = RT->GetVariable (
                  gTestRecordName,     
                  &VariableTestGuid,   
                  NULL,                
                  &DataSize,           
                  TestRecord           
                  );
  return Status;
}

EFI_STATUS
SCRTLogProcess(
  CHAR16  *InfFileName
  
)
{

  TEST_RECORD             TestRecord;
  VAR_INFO                Request;
  VAR_INFO                Result;
  BOOLEAN                 FirstFail;
  EFI_FILE_INFO           *FileInfo;
  EFI_FILE_HANDLE         FileHandle;  
  EFI_STATUS              Status;
  UINTN                   BufferSize;
  CHAR8                   Buffer[100];
  EFI_GUID                VariableTestGuid = TEST_RECORD_GUID;
  

  FirstFail   = FALSE;
  Status = GetVariableRecord(&TestRecord);
  if (EFI_ERROR (Status)) {
    Print(L"Cannot find test record variable\n");
    return Status;
  }
  
  //
  // Create the Log file
  //  
  Status = LibOpenFileByName (
             InfFileName,
             &FileHandle,
             EFI_FILE_MODE_CREATE | EFI_FILE_MODE_READ | EFI_FILE_MODE_WRITE,
             0
             );
  if (EFI_ERROR (Status)) {
    Print(L"Fail to create the Log file\n");     
    return Status;
  }

  //
  // If the file is directory, abort
  //
  FileInfo = LibGetFileInfo (FileHandle);
  if (FileInfo == NULL) {
    Print(L"Fail to open the Log file\n");     
    return EFI_ABORTED;  
  } else if (FileInfo->Attribute & EFI_FILE_DIRECTORY) {
    Print(L"It is not a file.\n");     
    return EFI_ABORTED;
  }

  Print (L"Success to get test record variable\n");
  Print (L"Begin to parse the record...\n");
  Request.TestData   = TestRecord.Request.TestData;
  Result.TestData    = TestRecord.Result.TestData;

  Print (L"\n********************Variable Test Group*******************\n\n");
  ZeroMem(Buffer, 100);
  BufferSize  = 100;
  ASPrint(Buffer, BufferSize, "\n********************Variable Test Group*******************\n\n");
  BufferSize = EfiAsciiStrSize(Buffer);  
  LibWriteFile (FileHandle, &BufferSize, Buffer);

  if (Request.BitMap.SetVariable){
    Print (L"%5s %-20s Requested\n", L" ", L"SetVariable");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"SetVariable");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);
    if (Result.BitMap.SetVariable) {
      Print (L"%5s %-20s Pass\n", L" ", L"SetVariable");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"SetVariable");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    } else {
      FirstFail = TRUE;
      Print (L"%5s %-20s Fail\n", L" ", L"SetVariable");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"SetVariable");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    } 
  }

  if (Request.BitMap.GetVariable){
    Print (L"%5s %-20s Requested\n", L" ", L"GetVariable");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"GetVariable");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.GetVariable) {
        Print (L"%5s %-20s Pass\n", L" ", L"GetVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"GetVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"GetVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"GetVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"GetVariable");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"GetVariable");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }


  if (Request.BitMap.GetNextVariable){
    Print (L"%5s %-20s Requested\n", L" ", L"GetNextVariable");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"GetNextVariable");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);		
    if (!FirstFail) {
      if (Result.BitMap.GetNextVariable) {
        Print (L"%5s %-20s Pass\n", L" ", L"GetNextVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"GetNextVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"GetNextVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"GetNextVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"GetNextVariable");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"GetNextVariable");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    } 
  }

  if (Request.BitMap.QueryVariable){
    Print (L"%5s %-20s Requested\n", L" ", L"QueryVariable");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"QueryVariable");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);		
    if (!FirstFail) {
      if (Result.BitMap.QueryVariable) {
        Print (L"%5s %-20s Pass\n", L" ", L"QueryVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"QueryVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"QueryVariable");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"QueryVariable");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      }
    } else{
      Print (L"%5s %-20s Not Test\n", L" ", L"QueryVariable");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"QueryVariable");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  Print (L"\n*********************Time Test Group**********************\n\n");
  ZeroMem(Buffer, 100);
  BufferSize  = 100;
  ASPrint(Buffer, BufferSize, "\n*********************Time Test Group**********************\n\n");
  BufferSize = EfiAsciiStrSize(Buffer);  
  LibWriteFile (FileHandle, &BufferSize, Buffer);
  
  if (Request.BitMap.GetTime){
    Print (L"%5s %-20s Requested\n", L" ", L"GetTime");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"GetTime");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {    
      if (Result.BitMap.GetTime) {
        Print (L"%5s %-20s Pass\n", L" ", L"GetTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"GetTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"GetTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"GetTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"GetTime");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"GetTime");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.SetTime){
    Print (L"%5s %-20s Requested\n", L" ", L"SetTime");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"SetTime");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {     
      if (Result.BitMap.SetTime) {
        Print (L"%5s %-20s Pass\n", L" ", L"SetTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"SetTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"SetTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"SetTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"SetTime");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"SetTime");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.SetWakeupTime){
    Print (L"%5s %-20s Requested\n", L" ", L"SetWakeupTime");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"SetWakeupTime");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {    
      if (Result.BitMap.SetWakeupTime) {
        Print (L"%5s %-20s Pass\n", L" ", L"SetWakeupTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"SetWakeupTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"SetWakeupTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"SetWakeupTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"SetWakeupTime");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"SetWakeupTime");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.GetWakeupTime){
    Print (L"%5s %-20s Requested\n", L" ", L"GetWakeupTime");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"GetWakeupTime");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.GetWakeupTime) {
        Print (L"%5s %-20s Pass\n", L" ", L"GetWakeupTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"GetWakeupTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"GetWakeupTime");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"GetWakeupTime");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"GetWakeupTime");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"GetWakeupTime");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }


  Print (L"\n********************Capsule Test Group********************\n\n");
  ZeroMem(Buffer, 100);
  BufferSize  = 100;
  ASPrint(Buffer, BufferSize, "\n********************Capsule Test Group********************\n\n");
  BufferSize = EfiAsciiStrSize(Buffer);  
  LibWriteFile (FileHandle, &BufferSize, Buffer);

  if (Request.BitMap.QueryCapsule){
    Print (L"%5s %-20s Requested\n", L" ", L"QueryCapsule");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"QueryCapsule");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.QueryCapsule) {
        Print (L"%5s %-20s Pass\n", L" ", L"QueryCapsule");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"QueryCapsule");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail   =TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"QueryCapsule");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"QueryCapsule");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"QueryCapsule");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"QueryCapsule");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.UpdateCapsule){
    Print (L"%5s %-20s Requested\n", L" ", L"UpdateCapsule");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"UpdateCapsule");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.UpdateCapsule) {
        Print (L"%5s %-20s Pass\n", L" ", L"UpdateCapsule");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"UpdateCapsule");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"UpdateCapsule");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"UpdateCapsule");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"UpdateCapsule");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"UpdateCapsule");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }


  Print (L"\n*********************Misc Test Group**********************\n\n");
  ZeroMem(Buffer, 100);
  BufferSize  = 100;
  ASPrint(Buffer, BufferSize, "\n*********************Misc Test Group**********************\n\n");
  BufferSize = EfiAsciiStrSize(Buffer);  
  LibWriteFile (FileHandle, &BufferSize, Buffer);

  if (Request.BitMap.GetNextCount){
    Print (L"%5s %-20s Requested\n", L" ", L"GetNextCount");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"GetNextCount");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.GetNextCount) {
        Print (L"%5s %-20s Pass\n", L" ", L"GetNextCount");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"GetNextCount");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"GetNextCount");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"GetNextCount");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"GetNextCount");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"GetNextCount");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  Print (L"\n*********************Reset Test Group*********************\n\n");
  ZeroMem(Buffer, 100);
  BufferSize  = 100;
  ASPrint(Buffer, BufferSize, "\n*********************Reset Test Group*********************\n\n");
  BufferSize = EfiAsciiStrSize(Buffer);  
  LibWriteFile (FileHandle, &BufferSize, Buffer);

  if (Request.BitMap.ColdReset){
    Print (L"%5s %-20s Requested\n", L" ", L"ColdReset");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"ColdReset");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.ColdReset) {
        Print (L"%5s %-20s Pass\n", L" ", L"ColdReset");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"ColdReset");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"ColdReset");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"ColdReset");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"ColdReset");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"ColdReset");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.WarmReset){
    Print (L"%5s %-20s Requested\n", L" ", L"WarmReset");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"WarmReset");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.WarmReset) {
        Print (L"%5s %-20s Pass\n", L" ", L"WarmReset");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"WarmReset");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;
        Print (L"%5s %-20s Fail\n", L" ", L"WarmReset");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"WarmReset");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"WarmReset"); 
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"WarmReset");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  }

  if (Request.BitMap.ShutDown){
    Print (L"%5s %-20s Requested\n", L" ", L"ShutDown");
    ZeroMem(Buffer, 100);
    BufferSize = 100;
    ASPrint(Buffer, BufferSize, "%5s %-20s Requested\n", L" ", L"ShutDown");
    BufferSize = EfiAsciiStrSize(Buffer);
    LibWriteFile (FileHandle, &BufferSize, Buffer);	
    if (!FirstFail) {
      if (Result.BitMap.ShutDown) {
        Print (L"%5s %-20s Pass\n", L" ", L"ShutDown");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Pass\n", L" ", L"ShutDown");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } else {
        FirstFail  = TRUE;      
        Print (L"%5s %-20s Fail\n", L" ", L"ShutDown");
        ZeroMem(Buffer, 100);
        BufferSize = 100;
        ASPrint(Buffer, BufferSize, "%5s %-20s Fail\n", L" ", L"ShutDown");
        BufferSize = EfiAsciiStrSize(Buffer);
        LibWriteFile (FileHandle, &BufferSize, Buffer);
      } 
    } else {
      Print (L"%5s %-20s Not Test\n", L" ", L"ShutDown");
      ZeroMem(Buffer, 100);
      BufferSize = 100;
      ASPrint(Buffer, BufferSize, "%5s %-20s Not Test\n", L" ", L"ShutDown");
      BufferSize = EfiAsciiStrSize(Buffer);
      LibWriteFile (FileHandle, &BufferSize, Buffer);
    }
  } 

  Status = LibFlushFile(FileHandle);
  Status = LibCloseFile (FileHandle);

  Status = RT->SetVariable (
                 gTestRecordName,             // VariableName
                 &VariableTestGuid,           // VendorGuid
                 EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS,                        // Attributes
                 0,                           // DataSize
                 &TestRecord                  // Data
                 );

  return EFI_SUCCESS;
}

