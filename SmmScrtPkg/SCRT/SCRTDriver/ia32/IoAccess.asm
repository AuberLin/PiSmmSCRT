  title   CpuIoAccess.asm
;------------------------------------------------------------------------------
; Copyright (c) 2009, Intel Corporation
; All rights reserved. 
;
; This UEFI SCRT ("Software") is furnished under license and may only be used or copied
; in accordance with the terms of that license UEFI Contributor Agreement.
; No license, express or implied, by estoppel or otherwise, to any intellectual property
; rights is granted by this document. The Software is subject to change without notice,
; and should not be construed as a commitment by Intel Corporation to market, license,
; sell or support any product or technology. Unless otherwise provided for in the license
; under which this Software is provided, the Software is provided AS IS, with no warranties
; of any kind, express or implied. Except as expressly permitted by the Software license,
; neither Intel Corporation nor its suppliers assumes any responsibility or liability
; for any errors or inaccuracies that may appear herein.
;
;*   Module Name:
;*     Io.asm
;* 
;*   Abstract: 
;*     Supports IA32 CPU IO operation
;*  
;------------------------------------------------------------------------------
;
;
;------------------------------------------------------------------------------

  .686
  .MODEL FLAT,C
  .CODE


UINT8    TYPEDEF    BYTE
UINT16   TYPEDEF    WORD
UINT32   TYPEDEF    DWORD
UINT64   TYPEDEF    QWORD
UINTN    TYPEDEF    UINT32



;------------------------------------------------------------------------------
;  UINT8
;  CpuIoRead8 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead8 PROC    PUBLIC Port:UINT16
    mov    dx,  Port
    in     al,  dx
    ret
CpuIoRead8  ENDP

;------------------------------------------------------------------------------
;  UINT16
;  CpuIoRead16 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead16 PROC    PUBLIC Port:UINT16
    mov    dx,  Port
    in     ax,  dx
    ret
CpuIoRead16  ENDP

;------------------------------------------------------------------------------
;  UINT32
;  CpuIoRead32 (
;    IN  UINT16  Port
;    )
;------------------------------------------------------------------------------
CpuIoRead32 PROC    PUBLIC Port:UINT16
    mov   dx,  Port
    in    eax, dx
    ret
CpuIoRead32  ENDP



;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite8 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite8 PROC    PUBLIC Port:UINT16, Data:UINT32
    mov    eax, Data
    mov    dx,  Port
    out    dx,  al
    ret
CpuIoWrite8  ENDP


;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite16 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite16 PROC    PUBLIC Port:UINT16, Data:UINT32
    mov    eax, Data
    mov    dx,  Port
    out    dx,  ax
    ret
CpuIoWrite16  ENDP


;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite32 (
;    IN  UINT16  Port,
;    IN  UINT32  Data
;    )
;------------------------------------------------------------------------------
CpuIoWrite32 PROC    PUBLIC Port:UINT16, Data:UINT32
    mov    eax, Data
    mov    dx,  Port
    out    dx,  eax
    ret
CpuIoWrite32  ENDP


END