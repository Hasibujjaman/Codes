Title Prog_1: Case conversion program

.MODEL SMALL
.STACK 100h

.DATA
    CR   EQU 0DH
    LF   EQU 0AH
    msg1 DB  "Enter a lower case letter: $"
    msg2 DB  0DH,0AH,"In upper case it is: "
    char DB  ?,"$"

.CODE
MAIN PROC
    ;initialize DS
         MOV AX,@DATA
         MOV DS,AX
    ;print user promt
         LEA DX,msg1
         MOV AH,9
         INT 21H
    ;intput a character and convert to upper case
         MOV AH,1
         INT 21H
         SUB AL,20H      ;subtracting 20h or 32d to convert to upper case
         MOV char,AL
    ;display on the next line
         LEA DX,msg2
         MOV AH,9
         INT 21H
    ;DOS exit
         MOV AH,4CH
         INT 21H
MAIN ENDP
    END MAIN


    
