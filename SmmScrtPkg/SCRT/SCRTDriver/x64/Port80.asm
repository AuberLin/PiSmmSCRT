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
;  Port80.asm
;
;--*/
text  SEGMENT

;
; VOID
; Port80 ( 
;  UINT8 Number
;  )
; Abstract: Print a Hex Number to I/O 80h
;
Port80 PROC NEAR PUBLIC
        mov   al, cl
	out   80h, al
	ret 
Port80 ENDP	

text  ENDS
END