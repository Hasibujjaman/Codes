;ARRAY REVERSAL USING ADDRESSING MODES 
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "ENTER INPUT: ",0AH,0DH,"$"
MSG2 DB 0DH,0AH,"Inversed: $"
MSG3 DB 0DH,0AH,"No of vowels: $"

INPUT_ARR DB "THIS IS A INPUT$"
N DW 15
N2 DW 14



.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 

    
    ;COUNT NO OF CHARACTERS IN INPUT ARRAY
    LEA BX,INPUT_ARR ; SI POINTS TO THE FIRST ELEMENT , HAS THE ADDRESS OF INPUT_ARR[0]
    MOV SI,BX
    ADD BX,N2
    MOV DI,BX ; DX POINTS TO THE LAST ELEMENT
    XOR CX,CX ; CX WILL HOLD NUMBER OF CHARACTERS IN INPUT_ARR
    MOV CX,N
    SHR CX,1 ; CX = FLOOR(N/2)
BEGIN_LOOP:
    MOV AX,[SI]
    XCHG AX,[DI]
    MOV [SI],AX
    INC SI ; POINTS TO NEXT INDEX
    DEC DI ; POINT TO PRECEDING INDEX
    LOOP BEGIN_LOOP
    
    ;INPUT_ARR IS NOW REVERSED 
    LEA DX,INPUT_ARR
    MOV AH,9
    INT 21H


    ;COUNT VOWEL
    MOV CX,N
    LEA BX,INPUT_ARR ; SI POINTS TO THE FIRST ELEMENT , HAS THE ADDRESS OF INPUT_ARR[0]
    MOV SI,BX
    ;
    ADD BX,N2
    MOV DI,BX ; DX POINTS TO THE LAST ELEMENT
    ;


TOP:
    



    
MAIN ENDP
END MAIN