.ORIG x3000

LD R6, STACK_TOP        ; STACK_TOP points to x4000 at the beginning

; User Program
LEA R1, STRSTART         ; Load starting address of string

; Loop to push string onto stack 
PUSHLOOP: 
    LDR R0, R1, #0 	; Load char into register R0
    BRz PUSHDONE   	; Did we reach null?
    JSR PUSH     	; PUSH
    ADD R1, R1, #1 	; increment pointer
    BR PUSHLOOP		; repeat

; Finished pushing elements, now set up popping loop
PUSHDONE:
    LEA R1, STRSTART    ; Reload address of string
    LDR R2, R1, #0      ; Initialize counter R2 to first char

;Loop to pop items from stack     
POPLOOP:
    BRz PALINDROME	; Finished processing w/o branching -> palindrome
    JSR POP    	        ; POP from stack 
    NOT R0, R0   	; Code to check if popped item matches
    ADD R0, R0, #1 	; the R2 pointer to the current char
    ADD R0, R0, R2      ; because if no match then 
    BRnp NOTPALIN       ; not palindrome
    ADD R1, R1, #1	; increment R1 memory location
    LDR R2, R1, #0	; load new char into R2
    BR POPLOOP

; If not palindrome display so and HALT
NOTPALIN: 
    LEA R0, NPALIN
    PUTS
    HALT
    
; If palindrome disply so and HALT 
PALINDROME:
    LEA R0, PALIN
    PUTS
    HALT
    

; PUSH subroutine
; IN: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_END
; R6: STACK_TOP
; Author: ywchen

PUSH
;
; save registers that will be modified in PUSH subroutine
;
        ST R3, PUSH_SaveR3 ; save R3
        ST R6, PUSH_SaveR6 ; save R6
        AND R5, R5, #0 ; clear R5, indicates success
        LD R3, STACK_END
        LD R6, STACK_TOP
;
; check for overflow (when stack is full)
; STACK_TOP < STACK_END (STACK_TOP = STACK_END - 1)
        ADD R3, R3, #-1
        NOT R3, R3
        ADD R3, R3, #1
        ADD R3, R3, R6
        BRz OVERFLOW ; stack is full
;
; store value in the stack
;
        STR R0, R6, #0 ; push onto the stack
        ADD R6, R6, #-1 ; move top of the stack
        ST R6, STACK_TOP ; store top of stack pointer
        BRnzp DONE_PUSH
;
; indicate the overflow condition on return
;
OVERFLOW ADD R5, R5, #1
;
; restore modified registers and return
;
DONE_PUSH
        LD R3, PUSH_SaveR3
        LD R6, PUSH_SaveR6
        RET


; POP Subroutine
; OUT: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_START
; R6: STACK_TOP
; Author: ywchen

POP
;
; save registers that will be modified in POP subroutine
;
        ST R3, POP_SaveR3 ; save R3
        ST R6, POP_SaveR6 ; save R6
        AND R5, R5, #0 ; clear R5, indicates success
        LD R3, STACK_START
        LD R6, STACK_TOP
;
; check for underflow (when stack is empty)
; STACK_TOP = STACK_START
        NOT R3, R3
        ADD R3, R3, #1
        ADD R3, R3, R6
        BRz UNDERFLOW ; stack is empty, nothing to pop
;
; remove value from the stack
;
        ADD R6, R6, #1 ; move top of the stack
        LDR R0, R6, #0 ; read value from the stack
        ST R6, STACK_TOP ; store top of stack pointer
        BRnzp DONE_POP
;
; indicate the underflow condition on return
;
UNDERFLOW ADD R5, R5, #1
;
; restore modified registers and return
;
DONE_POP:
        LD R3, POP_SaveR3
        LD R6, POP_SaveR6
        RET



; Variables & miscellany 

PUSH_SaveR3 .BLKW #1
PUSH_SaveR6 .BLKW #1
POP_SaveR3 .BLKW #1
POP_SaveR6 .BLKW #1

STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000

STRSTART .STRINGZ "racedcar"
PALIN .STRINGZ "Palindrome!"
NPALIN .STRINGZ "Not palindrome!" 
.END
