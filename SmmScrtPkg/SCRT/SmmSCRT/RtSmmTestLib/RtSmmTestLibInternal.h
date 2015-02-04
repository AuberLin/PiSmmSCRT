/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmTestLibInternal.h

Abstract:

  Internal functions of SMM common test library.

--*/

#ifndef _SMM_TEST_LIB_INTERNAL_H_
#define _SMM_TEST_LIB_INTERNAL_H_

UINTN
PhysicalToVirtual (
  IN UINTN      PhysicalAddress
  );
  
UINTN
VirtualToPhysical (
  IN UINTN      VirtualAddress
  );  
   
#endif
