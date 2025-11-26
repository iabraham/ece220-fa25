.ORIG x3000
MAIN
  LD R5, RSTACK
  LD R6, RSTACK
  LD R0, ROOT
  STR R0, R6, #0 ; push argument onto stack
  JSR TRAVERSE_INORDER
  ADD R6, R6, #2 ; caller teardown (pop return value & argument)
  HALT

ROOT .FILL x6000
RSTACK .FILL x7000

TRAVERSE_INORDER
; Bookkeeping
ADD R6, R6, #-1     ; Allocate space for return value
ADD R6, R6, #-1     ; Push return address to stack 
STR R7, R6, #0      ;
ADD R6, R6, #-1     ; Store CFP
STR R5, R6, #0      ;
ADD R5, R6, #-1     ; Set up new frame pointer

; Implement function logic

LDR R0, R5, #4      ; if node is null, skip to end
BRz DONE

; Traverse left
LDR R1, R0, #1      ;Load node->left
ADD R6, R6, #-1     ;Push node->left on stack
STR R1, R6, #0 
JSR TRAVERSE_INORDER
ADD R6, R6, #2      ; Tear down rest of stack 

; Output character
LDR R0, R5, #4
LDR R0, R0, #0
OUT

; Traverse right
LDR R0, R5, #4
LDR R1, R0, #2
ADD R6, R6, #-1     ;Push node->right on stack
STR R1, R6, #0 
JSR TRAVERSE_INORDER
ADD R6, R6, #2      ; Tear down rest of stack

DONE
;Restore frame pointer
LDR R5, R6, #0
ADD R6, R6, #1
;Restore return address
LDR R7, R6, #0
ADD R6, R6, #1
RET 

.END

.ORIG x6000
.FILL 50        ;x6000 - 2
.FILL x6003     ;x6001
.FILL x600C     ;x6002
.FILL 67        ;x6003 - C
.FILL x6006     ;x6004
.FILL x6009     ;x6005
.FILL 69        ;x6006 - E
.FILL 0         ;x6007 
.FILL 0         ;x6008 
.FILL 69        ;x6009 - E 
.FILL 0         ;x600A 
.FILL 0         ;x600B 
.FILL 50        ;x600C - 2 
.FILL 0         ;x600D 
.FILL x600F     ;x600E
.FILL 48        ;x600F - 0 
.FILL 0 
.FILL 0
.END