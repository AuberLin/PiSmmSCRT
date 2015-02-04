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

  VirtualMemory.c

--*/

#include "SCRTApp.h"

#define VIRT_TO_PHYS_OFFSET       (0x800000000)    //32G


EFI_STATUS
DoMemoryAllocation (
  IN UINTN PhysicalFunc
  )
/*++

Routine Description:

  Allocate memory and creat the PageTable to set up physical-virtual map. 

Arguments:

  PhysicalFunc  - Physical address where RuntimeTestFunc locates.

Returns:

  EFI_SUCCESS

--*/    
{  
  //
  // Nothing to do here since 64-bit mode has been with its PageTable mechanism.
  //
  return EFI_SUCCESS;
}



VOID
ConvertRuntimeFuncPtr (
  IN OUT UINTN   *VirtualFunc
  ) 
/*++

Routine Description:

  Change RuntimeTestFunc physical address to virtual address

Arguments:

  VirtualFunc  - On input, RuntimeTestFunc physical address. 
                 On output, RuntimeTest virtual address.

Returns:

  NONE

--*/  
{
  //
  // Change RuntimeFunc virtual address to (physical address + 32G).
  //
  *VirtualFunc = *VirtualFunc + (UINTN)VIRT_TO_PHYS_OFFSET;
}


VOID
PrepareVirtualAddressMap ( 
  IN UINTN                       MemoryMapSize,
  IN UINTN                       DescriptorSize,
  IN EFI_MEMORY_DESCRIPTOR       *MemoryMap,
  IN EFI_MEMORY_DESCRIPTOR       *VirtualMemoryMap,
  IN OUT UINTN                   *VirtualMapSize
  )
/*++

Routine Description:

  Construct VirtualAddressMap from physical address to virtual address

Arguments:

  MemoryMapSize     - The size, in bytes, of the MemoryMap buffer
  DescriptorSize    - The size, in bytes, of an individual EFI_MEMORY_DESCRIPTOR
  MemoryMap         - A pointer to the current memory map
  VirtualMemoryMap  - A pointer to the modified virtual memory map
  VirtualMapSize    - A pointer to the size, in bytes, of the VirtualMemoryMap buffer

Returns:

  NONE

--*/      
{
  UINTN             Index;
  *VirtualMapSize   = 0;
  //
  // Copy entries that need runtime mapping to construct virtualMemoryMap
  //
  for (Index = 0; Index < (MemoryMapSize / DescriptorSize); Index++) {
    //
    // Virtual address = (Physical address + 32G)
    //
    if ((MemoryMap->Attribute & EFI_MEMORY_RUNTIME) == EFI_MEMORY_RUNTIME) {
      CopyMem ((VOID *) VirtualMemoryMap, (VOID *) MemoryMap, DescriptorSize);
      *VirtualMapSize += DescriptorSize;
      VirtualMemoryMap->VirtualStart  = VirtualMemoryMap->PhysicalStart + VIRT_TO_PHYS_OFFSET;
      VirtualMemoryMap  = NextMemoryDescriptor (VirtualMemoryMap, DescriptorSize);
    }
    MemoryMap = NextMemoryDescriptor (MemoryMap, DescriptorSize);
  }
}

VOID
JumpVirtualMode(
  IN UINTN VirtualFunc,
  IN UINTN HandOffAddr
  )
/*++

Routine Description:

  Enable virtual addressing mode, and jump to RuntimeTestFunc in virtual address

Arguments:

  VirtualFunc  - RuntimeTestFunc virtual address
  HandOffAddr  - Configuration Data Address

Returns:

  NONE

--*/  
{
  //
  // Enable PageTable to go to virtual mode, and jump to Virtual Function Entry Point.
  //
  LoadNewPageTable (VirtualFunc, HandOffAddr);
}

VOID
PatchPageTableForMmioRange(UINTN RangeBase)
{
  //
  // Nothing to be done for x64.
  //
  return;
}

