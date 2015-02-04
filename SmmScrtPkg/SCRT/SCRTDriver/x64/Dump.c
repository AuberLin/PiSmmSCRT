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

  Dump.c

--*/

#include "SCRTDriver.h"

VOID
DumpRuntimeTable()
{
  Printf("\n================Dump Runtime Table===============\n");
  Printf("Header Signature = 0x%x\n", VRT->Hdr.Signature);

  Printf("\n================GetTime Service==============\n");
  Printf("GetTime @ 0x%x\n", VRT->GetTime);

  Printf("\n================SetTime Service==============\n");
  Printf("SetTime @ 0x%x\n", VRT->SetTime);

  Printf("\n================GetWakeupTime Service==============\n");
  Printf("GetWakeupTime @ 0x%x\n", VRT->GetWakeupTime);

  Printf("\n================SetWakeupTime Service==============\n");
  Printf("SetWakeupTime @ 0x%x\n", VRT->SetWakeupTime);

  Printf("\n================GetVariable Service==============\n");
  Printf("GetVariable @ 0x%x\n", VRT->GetVariable);

  Printf("\n================GetNextVariableName Service==============\n");
  Printf("GetNextVariableName @ 0x%x\n", VRT->GetNextVariableName);

  Printf("\n================SetVariable Service==============\n");
  Printf("SetVariable @ 0x%x\n", VRT->SetVariable);

  Printf("\n================GetNextHighMonotonicCount Service==============\n");
  Printf("GetNextHighMonotonicCount @ 0x%x\n", VRT->GetNextHighMonotonicCount);

  Printf("\n================ResetSystem Service==============\n");
  Printf("ResetSystem @ 0x%x\n", VRT->ResetSystem);
#if 0
  Printf("\n================UpdateCapsule Service==============\n");
  Printf("UpdateCapsule @ 0x%x\n", VRT->UpdateCapsule);

  Printf("\n================QueryCapsuleCapabilities Service==============\n");
  Printf("QueryCapsuleCapabilities @ 0x%x\n", VRT->QueryCapsuleCapabilities);

  Printf("\n================QueryVariableInfo Service==============\n");
  Printf("QueryVariableInfo @ 0x%x\n", VRT->QueryVariableInfo);
#endif
}
