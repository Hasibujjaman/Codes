;PRIME NUMBER DETECTOR
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "ENTER INPUT: ",0AH,0DH,"$"
MSG2 DB 0DH,0AH,"INVALID INPUT $"
MSG3 DB 0DH,0AH,"PRIME $"
MSG4 DB 0DH,0AH,"NOT PRIME $"

NUMBER DW ?


.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 

    ;SAVE REGISTERS BEFORE PROCEDURE CALL
    ;PUSH BX
    ;PUSH CX
    ;PUSH DX
    ;DON'T SAVE AX AS IT WILL HOLD THE INPUT NUMBER OBTAINED FROM INPUT PROCEDURE AND THE PRINT PROCEDURE USES AX

    ;PROMPT
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    ;CALL FOR INPUT PROCEDURE
    CALL INPUT
    ;CALL FOR OUTPUT PROCEDURE
    CALL PRINT

    ;RESTORE REGS AFTER PROCEDURE CALL
    ;POP DX
    ;POP CX
    ;POP BX




;;;;;;;;;;;;;;;;;;;;;;;;CHECK IF COMPOSITE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    MOV CX,2 ; SET INITIAL DIVISIOR = 2 IN CX
    ;AX HAS THE DIVIDENT
L_LOOP:
    ;PUSH AX ; SAVE DIVIDENT STORED IN AX IN THE STACK
    MOV AX,NUMBER
    ;;DX MUST BE CLEARED FIRST IF THE DIVIDENT(DX:AX) IS 16 BITS AND FITTED IN AX
    XOR DX,DX
    DIV CX
    ;REMAINDER IN DX
    CMP DX,0 ; IS REMAINDER 0 ?
    JE L_NOT_PRIME
    ;POP AX ; RESTORE THE DIVISOR FOR THE NEXT CHECKING
    INC CX ; GET NEXT DIVISOR
    CMP CX,NUMBER

    JL L_LOOP

    ;TEST FOR COMPOSITE NUMBER FAILS . HENCE HERE THE NUMBER IS PRIME
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    JMP L_END

L_NOT_PRIME:
    LEA DX,MSG4
    MOV AH,9
    INT 21H
    JMP L_END


L_END_OF_MAIN_PROC:
    JMP L_END

MAIN ENDP




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;INPUT PROCEDURE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
INPUT PROC
L_BEGIN:
    XOR BX,BX ;CLEAR BX. BX WILL HOLD THE CONVERTED NUMBER AT THE END SO IT NEEDS TO BE CLEARED FIRST
    ;READ CHAR \ ASCII
    MOV AH,1
    INT 21H ;INPUT CHAR(ASCII) IS IN AL
L_REPEAT:
    ;CHECK WHETHER INPUT CHAR IS REALY IS DIGIT
    CMP AL,'0'
    JNGE L_INVALID_INPUT ; JUMP IF CHAR < '0'
    CMP AL,'9'
    JNLE L_INVALID_INPUT ; JUMP IF CHAR > '9'

    ;VALID INPUT CHARACTER . NOW CONVERT TO DIGIT
    AND AX,000FH ; AX HAS INPUT CHAR(NOT IN ASCII ANYMORE) IN BINARY NOW. I,E, CONVERTED ASCII CHAR TO DIGIT
    ;or, SUB AX,'0'
    PUSH AX ; SAVE THE DIGIT IN STACK
    ;TOTAL(BX) = TOTAL * 10 + TOTAL
    MOV AX,10D ; GET MUTIPLICANT = 10D IN AX
    MUL BX ;  (INITIALLY BX IS 0 , SO AX WILL HAVE 0*10 = 0). MULTIPLIER IS IN BX . SO, AX NOW HAS AX(10D) * BX .
    POP BX ; BX HAS THE DIGIT
    ADD BX,AX ; TOTAL(BX) = TOTAL(BX) + TATAL*10 (AX)

    ;READ ANOTHER CHAR
    MOV AH,1
    INT 21H
    CMP AL,0DH ; IS CR ?
    JNE L_REPEAT ; NO , THEN REPEAT

    ;STORE THE TOTAL(BX) WHICH IS THE INPUT STRING CONVERTED INTO BINARY REPRESENTATION IN AX
    MOV AX,BX
    MOV NUMBER,AX ; ALSO IN NUMBER

    RET
INPUT ENDP


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;PRINT PROCEDURE;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
PRINT PROC           
    ;ASSUMING AX HAS THE INPUT IN BINARY
    ;INITIALIZE COUNT
    MOV CX,0 ; WILL COUNT THE No. OF DIGITS PUSHED IN THE STACK
    MOV DX,0 ; AS INPUT IS 16 BIT DX NEED TO BE CLEARED AS IT WILL HOLD THE REMAINDER AFTER DIV OPERATION

L_START:
        ; if AX is zero
        CMP AX,0 ;IS ALL THE DIGITS IN THE NUMBER PROCESSED(I.E, PUSHED IN THE STACK) ?
        JE L_PRINT  ; YES , THEN PRINT THEM FROM THE STACK   
         
        ;initialize bx to 10
        
        MOV BX,10 ; DIVISOR , BX = 10D     
         
        ;extract the last digit
        DIV BX  ; QUOTIENT WILL BE IN AX AND REMAINDER(LAST DIGIT) IN DX               
         
        ;push the reaminder/last digit which is in dx in the stack
        PUSH DX              
         
        ;increment the count
        INC CX              
         
        ;set DX to 0 
        XOR DX,DX ; CLEAR DX FOR THE NEXT DIV OPERATION
        JMP L_START
L_PRINT:
        ;check if count is greater than zero
        CMP CX,0 ; IS STACK EMPTY?
        JE L_EXIT ; YES, THEN NOTHING TO PRINT . JUMP TO EXIT
         
        ;pop the top of stack 
        POP DX 
         
        ;convert digit to ascii/char
        ADD DX,30H ;NOW DL HAS THE ASCII OF THE DIGIT
        ;print it
        MOV AH,2
        INT 21H
         
    ;decrease the count
    DEC CX
    JMP L_PRINT
L_EXIT:
    RET
PRINT ENDP 







L_INVALID_INPUT:
    LEA DX,MSG2
    MOV AH,9
    INT 21H

L_END:

END MAIN