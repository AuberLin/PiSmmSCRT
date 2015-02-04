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

  ParseConf.h

--*/


#include "EfiShellLib.h"


#define CONF_FILE_NAME                    L"SCRT.conf"
#define CONF_FILE_SIZE                    (1024*1024)
#define CONFIGURE_INFO_SIGNATURE          0x5AA5

//
// Configuration file strings
//
#define VARIABLE_SECTION_STRING            "[variable]"
#define TIME_SECTION_STRING                "[time]"
#define CAPSULE_SECTION_STRING             "[capsule]"
#define MONOTONICCOUNT_SECTION_STRING      "[monotonicCount]"
#define RESET_SECTION_STRING               "[reset]"
#define UART_SECTION_STRING  "[UART]"

#define UART_MMIO_BASE_ADDRESS_STRING  "MmioBaseAddress"
#define UART_IOPORT_BASE_ADDRESS_STRING  "IoPortBaseAddress"
#define GET_VARIABLE_STRING                "GetVariable"
#define SET_VARIABLE_STRING                "SetVariable"
#define GET_NEXT_VARIABLE_NAME_STRING      "GetNextVariableName"
#define QUERY_VARIABLE_INFO_STRING         "QueryVariableInfo"
#define GET_TIME_STRING                    "GetTime"
#define SET_TIME_STRING                    "SetTime"
#define GET_WAKEUP_TIME_STRING             "GetWakeupTime"
#define SET_WAKEUP_TIME_STRING             "SetWakeupTime"
#define UPDATE_CAPSULE_STRING              "UpdateCapsule"
#define QUERY_CAPSULE_CAPABILITIES_STRING  "QueryCapsuleCapabilities"
#define GET_NEXT_HIGH_MONOTONIC_STRING     "GetNextHighMonotonicCount"
#define COLD_RESET_STRING                  "ColdReset"
#define WARM_RESET_STRING                  "WarmReset"
#define SHUT_DOWN_STRING                   "ShutDown"
#define TRUE_STRING                        "TRUE"
#define FALSE_STRING                       "FALSE"
#define _MAX_PATH                          260

#define ASCIISTR_TO_INT(Buffer)                                \
  (((Buffer[0] == '0') && ((Buffer[1] == 'x') || (Buffer[1] == 'X'))) ? Ascii_xtoi(Buffer) : Ascii_Atoi(Buffer))

typedef struct {
  UINT8 *FileImage;
  CHAR8 *Eof;
  CHAR8 *CurrentFilePointer;
} MEMORY_FILE;


//
// Configuration File Info
//
typedef union _CONF_INFO
{
  struct {
  UINT32 SetVariable        : 1;
  UINT32 GetVariable        : 1;
  UINT32 GetNextVariable    : 1;
  UINT32 QueryVariable      : 1;
  UINT32 GetTime            : 1;
  UINT32 SetTime            : 1;
  UINT32 SetWakeupTime      : 1;
  UINT32 GetWakeupTime      : 1;
  UINT32 QueryCapsule       : 1;
  UINT32 UpdateCapsule      : 1;
  UINT32 GetNextCount       : 1;
  UINT32 ColdReset          : 1;
  UINT32 WarmReset          : 1;
  UINT32 ShutDown           : 1;
  UINT32 Reserved           : 2;
  UINT32 Signature          : 16;
  } BitMap;
  UINT32  InfoData;
} CONF_INFO;


typedef struct _DEBUGGER_INFO {
  BOOLEAN               MmioFlag;
  UINTN                 IoPort;
  UINTN                 IoBase;
  UINTN                 MmioBase;
} DEBUGGER_INFO;



typedef struct  _RUNTIME_HANDOFF{
  CONF_INFO         ConfigureInfo;
  DEBUGGER_INFO     DebuggerInfo;
}RUNTIME_HANDOFF; 


VOID
ParseConf (
  IN MEMORY_FILE  *InfFile,
  IN CONF_INFO    *FileInfo
  )
/*++

Routine Description:

  This function parses a configuration file and copies info into a CONF_INFO structure.

Arguments:

  InfFile    -     Memory file image.
  FileInfo   -     Information read from INF file.
  
Returns:

  NONE
  
--*/
;

VOID
GetUARTAddressFromConf (
  IN MEMORY_FILE  *InfFile,
  IN RUNTIME_HANDOFF *HandOffInfo
  )
/*++

Routine Description:

  This function parses a configuration file and get UART info into a DEBUGGER_INFO structure in HandOffInfo.

Arguments:

  InfFile    -     Memory file image.
  HandOffInfo   -     .
  
Returns:

  NONE
  
--*/
;

VOID
EFIAPI
UnicodeStrCpy (
  IN   CHAR16       *Destination,
  IN   CHAR16       *Source
  )
/*++

Routine Description:
  
  Copies one Null-terminated unicode string to another Null-terminated unicode
  string and returns the new unicode string.
  
Arguments: 
  
  Destination - Pointer to a Null-terminated unicode string.
  Source      - Pointer to a Null-terminated unicode string.
  
Returns:

  NONE

--*/   
;


INTN
EFIAPI
UnicodeStrCmp (
  IN  CHAR16     *FirstString,
  IN  CHAR16     *SecondString
  )
/*++

Routine Description:
  
  Compares two Null-terminated Unicode strings, and returns the difference
  between the first mismatched Unicode characters.  
  
Arguments: 
  
  FirstString  - Pointer to a Null-terminated Unicode string.
  SecondString - Pointer to a Null-terminated Unicode string.
  
Returns:

  0      FirstString is identical to SecondString..
  !=0    FirstString is not identical to SecondString.

--*/    
;


EFI_STATUS
RuntimeHandOff (
  IN CONF_INFO               *ConfInfo,
  OUT UINTN                  *HandOffAddr
  );  
