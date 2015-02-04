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

  Debug.c

--*/

#include "SCRTDriver.h"

UINTN                 mHandOffPtr        =  0;
EFI_PHYSICAL_ADDRESS  mIoPortSpaceAddress = 0;


VOID
UartReadWrite (
  IN BOOLEAN                 ReadFlag,
  IN EFI_PHYSICAL_ADDRESS    Address,
  IN OUT UINT8               *Data
  )
{
  if (ReadFlag) {
    MEMORY_FENCE (); 
    *Data = *(volatile UINT8 *)(UINTN)Address;
  } else {
    *(volatile UINT8 *)(UINTN)Address = *Data;
    MEMORY_FENCE (); 
  }
}


EFI_STATUS
ConsumeHandOff (
  IN  UINTN         HandOffAddr,
  OUT CONF_INFO     *ConfigData
  )
{
   RUNTIME_HANDOFF   *HandOffPtr;
   //
   // First fix the memory address of hand off data.
   //
   FixAddress(&HandOffAddr);
   mHandOffPtr = HandOffAddr;
   HandOffPtr  = (RUNTIME_HANDOFF*)mHandOffPtr;
   *ConfigData =  HandOffPtr->ConfigureInfo;

   if (!HandOffPtr->DebuggerInfo.MmioFlag){
     //
     // If debug port is I/O mapped, fix IoBase Address.
     //
     FixAddress(&HandOffPtr->DebuggerInfo.IoBase);
     mIoPortSpaceAddress = HandOffPtr->DebuggerInfo.IoBase;
   } else {
     //
     // If debug port is MMIO, fix MmioBase Address.
     //
     FixAddress(&HandOffPtr->DebuggerInfo.MmioBase);
   }

   return EFI_SUCCESS;
}




VOID
Send2IO (
  UINT64     Address,
  CHAR8      *String
  )
{
  UINT8 Data;
  CHAR8 *Ptr;

  Ptr = String;
  //
  // Send text message to IO UART
  //
  while (*Ptr) {
    EfiIoRead (EfiCpuIoWidthUint8, Address + 0x5, 1, &Data);
    //
    // Wait until Line Status Register (LSR) Bit5 Transmitter Holding 
    // Register Empty(THRE) is high, then write.
    //
    while ((Data & 0x20) == 0) {
      EfiIoRead (EfiCpuIoWidthUint8, Address + 0x5, 1, &Data);
    }
    Data = *Ptr++;
    //
    // Write data into Transmit Buffer Register
    //
    EfiIoWrite (EfiCpuIoWidthUint8, Address, 1, &Data);
  }
}


VOID
Send2MMIO (
  UINT64     Address,
  CHAR8      *String
  )
{
  UINT8 Data;
  CHAR8 *Ptr;

  Ptr = String;
  //
  // Send text message to MMIO UART
  //
  while (*Ptr) {
    UartReadWrite(TRUE, Address + 0x5, &Data);
    //
    // Wait until Line Status Register (LSR) Bit5 Transmitter Holding 
    // Register Empty(THRE) is high, then write.
    //
    while ((Data & 0x20) == 0) {
      UartReadWrite(TRUE, Address + 0x5, &Data);
    }
    Data = *Ptr++;
    //
    // Write data into Transmit Buffer Register
    //
    UartReadWrite(FALSE, Address, &Data);
  }
}


EFI_STATUS
Send2UART (
  CHAR8                *String
  )
{
   RUNTIME_HANDOFF   *HandOffPtr;
   HandOffPtr  = (RUNTIME_HANDOFF*)mHandOffPtr;

  //
  // Only concern System Memory Space and System I/O Space
  //
  if(HandOffPtr->DebuggerInfo.MmioFlag) {
    Send2MMIO(HandOffPtr->DebuggerInfo.MmioBase, String);
  } else {
    Send2IO (HandOffPtr->DebuggerInfo.IoPort, String);
  }
  return EFI_SUCCESS;
}



EFI_STATUS
DebugWorker (
  IN CHAR8    *String 
  )
{
  EFI_STATUS    Status;

  //
  // Send text message to registered UART.
  // 
  Status = Send2UART(String);
  return Status;
}
