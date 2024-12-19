Title Prog_1: Substraction of two digits

.MODEL SMALL
.STACK 100h

.DATA
    CR     EQU 0DH
    LF     EQU 0AH
    msg1   DB  "Enter 1st digit: $"
    msg2   DB  0DH,0AH,"Enter 2nd digit: $"
    msg3   DB  0DH,0AH,"The substraction of $"
    msg4   DB  " and $"
    msg5   DB  " is: $"
    A      Db  ?
    B      Db  ?
    result Db  ?

.CODE
Main Proc
    ;initialize DS
         MOV AX,@DATA
         MOV DS,AX
                                                                                      
    ;print user promt
         LEA DX,msg1
         MOV AH,9
         INT 21H

    ;intput the 1st digit
         MOV AH,1
         INT 21H
         MOV A,al

    ;print user promt
         LEA DX,msg2
         MOV AH,9
         INT 21H

    ;Input 2nd digit
         MOV AH,1
         INT 21H
         MOV B,al
    ;result calculation
     
         MOV cl,A
         SUB cl,B

         ADD cl,30H
         MOV result,cl


    ;display result on the next line
         LEA DX,msg3
         MOV AH,9
         INT 21H

         Mov dl,A
         mov ah,2
         int 21h

         lea dx,msg4
         mov ah,9
         int 21h

         mov dl,B
         mov ah,2
         int 21h

         lea dx,msg5
         mov ah,9
         int 21h

         MOV DL,result
         MOV AH,2
         INT 21H

    ;DOS exit
         MOV AH,4CH
         INT 21H
MAIN ENDP
    END MAIN


    
