;/*++
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
;--*/
;/*++
;
;Module Name:
;
;  GoVirtual.asm
;
;--*/
text SEGMENT

HIGHBASE  EQU  0800000000h

; VOID
; LoadNewPageTable (
;   VOID                  *FuncPointer
;   UINTN                 ConfigInfo
; )

LoadNewPageTable  PROC Near Public
  ;
  ; set the entries for virtual address above 4GB
  ;
  mov   rax, cr3
  mov   rax, [rax]
  and   ax,  0f000h
  mov   r8 , rax
  
  ;
  ; Create mapping entry for 32G-64G
  ; 0-32G & 32G-64G have identical phycial address mapping
  ;
  push  rcx
  push  rdx
  mov   rcx,  0    
again:  
  mov   rbx, [rax + rcx]
  and   bx,  0ffdfh                 ; clear access flag
  mov   [rax + rcx + 100h], rbx
  add   rcx,  08h                   ; point to next entry
  cmp   rcx,  100h                  ; get 32GB (1GB per entry)
  jne   again

  ;
  ; Change ConfigInfo to rcx to pass it to callee
  ;
  pop   rcx  
  pop   rdx

  ;
  ; jmp to the virtual address above 4GB 
  ;
  mov   rax, new_address
  mov   rbx, HIGHBASE
  add   rax, rbx
  jmp   rax

new_address:
  mov   rbx, HIGHBASE
  add   rsp, rbx

  ;
  ; It is safe time to destroy 0-32G virtual mapping
  ;
  mov   r9,  0
  mov   r10, 0
Kill:  
  mov   [r8 + r9], r10
  add   r9,  08h                   ; point to next entry
  cmp   r9,  100h                  ; get 32GB (1GB per entry)
  jne   Kill


  push  rdx
  ret

  ;jmp   qword ptr [rcx]

LoadNewPageTable ENDP

text ENDS
END
