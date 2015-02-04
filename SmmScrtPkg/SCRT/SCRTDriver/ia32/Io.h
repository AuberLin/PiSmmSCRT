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

#ifndef _IA32_IO_ACCESS_H
#define _IA32_IO_ACCESS_H

#include "EfiCommon.h"
#include "EfiApi.h"
#include EFI_PROTOCOL_DEFINITION (CpuIo)

#define IA32_MAX_IO_ADDRESS   0xFFFF

#define IA32API __cdecl


typedef union {
  UINT8  VOLATILE  *buf;
  UINT8  VOLATILE  *ui8;
  UINT16 VOLATILE  *ui16;
  UINT32 VOLATILE  *ui32;
  UINT64 VOLATILE  *ui64;
  UINTN  VOLATILE  ui;
} PTR;

#define   VIRT_TO_PHYS_OFFSET            (0x80000000)     //2G

UINT8
IA32API
CpuIoRead8 (
  IN  UINT16  Port
  )
;


UINT16
IA32API
CpuIoRead16 (
  IN  UINT16  Port
  )
;

UINT32
IA32API
CpuIoRead32 (
  IN  UINT16  Port
  )
;

VOID
IA32API
CpuIoWrite8 (
  IN  UINT16  Port,
  IN  UINT32  Data
  )
;

VOID
IA32API
CpuIoWrite16 (
  IN  UINT16  Port,
  IN  UINT32  Data
  )
;

VOID
IA32API
CpuIoWrite32 (
  IN  UINT16  Port,
  IN  UINT32  Data
  )
;

#endif
