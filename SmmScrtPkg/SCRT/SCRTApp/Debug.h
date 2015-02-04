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

  Debug.h

--*/
#ifndef _DEBUG_ACCESS_H
#define _DEBUG_ACCESS_H

#include "EfiCommon.h"
#include "EfiApi.h"
#include EFI_GUID_DEFINITION (Acpi)
#include "Acpi2_0.h"
#include "Acpi3_0.h"
#include EFI_PROTOCOL_DEFINITION (CpuIo)


//
// HCDP/PCDP Table Definition
//
#define HCDP_TABLE_GUID        \
    {0xF951938D, 0x620B, 0x42EF, 0x82, 0x79, 0xA8, 0x4B, 0x79, 0x61, 0x78, 0x98}
//
// HCDP/PCDP Table Signature Definition
//
#define HCDP_TABLE_SIGNATURE EFI_SIGNATURE_32 ('H', 'C', 'D', 'P')

//
// UART PCDP Device Type 
//
#define UART_BIDIRECTIONAL_CONSOLE                0
#define UART_DEBUG_PORT                           1

#pragma pack(1)

typedef struct {
  EFI_ACPI_DESCRIPTION_HEADER          Header;
  UINT32                               NumberEntry;
} PCDP_TABLE_HEADER;

//
// UART Device Descriptor
//
typedef  struct {
  UINT8                                       EntryType;
  UINT8                                       DataBits;
  UINT8                                       Parity;
  UINT8                                       StopBits;
  UINT8                                       PciSegNum;
  UINT8                                       PciBusNum;
  UINT8                                       PciDeviceNum;
  UINT8                                       PciFuncNum;
  UINT8                                       BaudRate[8];
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE      BaseAddress;
  UINT16                                      DeviceId;
  UINT16                                      VendorId;
  UINT32                                      Interrupt;
  UINT32                                      PseudoClockRate;
  UINT8                                       PCIClassCode;
  UINT8                                       PCIDeviceFlag;
  UINT8                                       EfiConOutDevIndex;
  UINT32                                      Reserved;
} UART_DEVICE_DESCRIPTOR;

//
// Other new standard device descriptor(Other than UART Device Descriptor)
// Here is a template struct. 
//
typedef struct {
    UINT8                                       EntryType;
    UINT8                                       PrimaryConsoleFlag;
    UINT16                                      Length;
    UINT16                                      EfiConOutDevIndex;
} PCDP_DEVICE_DESCRIPTOR;

typedef  union {
  UART_DEVICE_DESCRIPTOR                        *UARTDeviceDes;
  PCDP_DEVICE_DESCRIPTOR                        *PCDPDeviceDes;
  UINT8                                         *Raw;
} DEVICE_DESCRIPTOR_ENTRY;


//
// SPCR Table Signature Definition
//
#define SPCR_TABLE_SIGNATURE EFI_SIGNATURE_32 ('S', 'P', 'C', 'R')

//
// SPCR Table Definition
//
typedef struct {
  EFI_ACPI_DESCRIPTION_HEADER                   Header; 
  UINT8                                         InterfaceType;
  UINT8                                         Reserved1[3];
  EFI_ACPI_3_0_GENERIC_ADDRESS_STRUCTURE        BaseAddress;
  UINT8                                         InterruptType;
  UINT8                                         Irq;
  UINT32                                        GlobalSysInter;
  UINT8                                         BaudRate;
  UINT8                                         Parity;
  UINT8                                         StopBits;
  UINT8                                         FlowControl;
  UINT8                                         TerminalType;
  UINT8                                         Reserved2;
  UINT16                                        PciDeviceId;
  UINT16                                        PciVendorId;
  UINT8                                         PciBusNum;
  UINT8                                         PciDevNum;
  UINT8                                         PciFuncNum;
  UINT32                                        PciFlag;
  UINT8                                         PciSeg;
  UINT32                                        Reserved;
} SPCR_ACPI_TABLE;

#pragma pack()


EFI_STATUS
EfiIoRead (
  IN     EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                     Address,
  IN     UINTN                      Count,
  IN OUT VOID                       *Buffer
  )
 ;

EFI_STATUS
EfiIoWrite (
  IN     EFI_CPU_IO_PROTOCOL_WIDTH  Width,
  IN     UINT64                     Address,
  IN     UINTN                      Count,
  IN OUT VOID                       *Buffer
  )
  ;

#endif
