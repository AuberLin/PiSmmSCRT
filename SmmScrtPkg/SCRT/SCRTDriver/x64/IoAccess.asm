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
;*    Io.asm
;*  
;*   Abstract:
;*    Supports x64 CPU IO operation
;*
;------------------------------------------------------------------------------
;
;   
; 
; Abstract:
; 
;   
;------------------------------------------------------------------------------

.CODE

;------------------------------------------------------------------------------
;  UINT8
;  CpuIoRead8 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
CpuIoRead8 PROC        PUBLIC
    xor   eax, eax
    mov    dx, cx
    in     al, dx
    ret
CpuIoRead8  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite8 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
CpuIoWrite8 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, al
    ret
CpuIoWrite8  ENDP

;------------------------------------------------------------------------------
;  UINT16
;  CpuIoRead16 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
CpuIoRead16 PROC        PUBLIC
    xor   eax, eax
    mov    dx, cx
    in     ax, dx
    ret
CpuIoRead16  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite16 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
CpuIoWrite16 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, ax
    ret
CpuIoWrite16  ENDP

;------------------------------------------------------------------------------
;  UINT32
;  CpuIoRead32 (
;    UINT16  Port   // rcx
;    )
;------------------------------------------------------------------------------
CpuIoRead32 PROC        PUBLIC
    mov    dx, cx
    in    eax, dx
    ret
CpuIoRead32  ENDP

;------------------------------------------------------------------------------
;  VOID
;  CpuIoWrite32 (
;    UINT16  Port,    // rcx
;    UINT32  Data     // rdx
;    )
;------------------------------------------------------------------------------
CpuIoWrite32 PROC        PUBLIC
    mov   eax, edx
    mov    dx, cx
    out    dx, eax
    ret
CpuIoWrite32  ENDP

END
