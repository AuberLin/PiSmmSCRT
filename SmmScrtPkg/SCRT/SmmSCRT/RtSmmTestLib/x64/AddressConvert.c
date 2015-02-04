/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  AddressConvert.c

Abstract:

  Internal functions for virtual-physical address convert.

--*/

#include "Efi.h"

#define VIRT_TO_PHYS_OFFSET       (0x800000000)    //32G


UINTN
PhysicalToVirtual (
  IN UINTN      PhysicalAddress
  ) 
/*++

Routine Description:

  Change physical address to virtual address

Arguments:

  PhysicalAddress  - physical address to be converted. 
                 

Returns:

  Virtual address

--*/
{
  UINTN  VirtualAddress;
  
  VirtualAddress = PhysicalAddress + (UINTN)VIRT_TO_PHYS_OFFSET;
  return VirtualAddress;
}

UINTN
VirtualToPhysical (
  IN UINTN      VirtualAddress
  ) 
/*++

Routine Description:

  Change virtual address to physical address

Arguments:

  VirtualAddress  - virtual address to be converted. 
                 

Returns:

  Physical address

--*/
{
  UINTN  PhysicalAddress;
  
  PhysicalAddress = VirtualAddress - (UINTN)VIRT_TO_PHYS_OFFSET;
  
  return PhysicalAddress;
}


