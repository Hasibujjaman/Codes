.MODEL SMALL
.STACK 100H
.DATA
A DB ?
B DB ?
C DB ?
MSGA DB "Enter A: $"
MSGB DB 0DH,0AH,"Ente B: $"
MSGC DB 0DH,0AH,"Enter C: $"   
MSGR DB 0DH,0AH,"The greatest between A,B and C is: $"

.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
         
    ;prompt 1   
    LEA DX,MSGA
    MOV AH,9
    INT 21H
    ;input 1
    MOV AH,1
    INT 21H
    MOV A,AL
         
    ;prompt 2
    LEA DX,MSGB
    MOV AH,9
    INT 21H
    
    ;input2
    MOV AH,1
    INT 21H
    MOV B,AL
         
    ;prompt 3 
    LEA DX,MSGC
    MOV AH,9
    INT 21H
    
    ;input 3
    MOV AH,1
    INT 21H
    MOV C,AL
    
        
    ;compare A , B
    MOV AL,A
    MOV BL,B
    CMP AL,BL
    JGE A_greater
    
    ;HERE B is greater than A
    MOV CL,C
    CMP BL,CL
    JGE B_GREATEST
    
    ;HERE C IS GREATEST
    LEA DX,MSGR
    MOV AH,9
    INT 21H
  
    MOV DL,C
    MOV AH,2
    INT 21H 
    
    JMP DONE
    
    
    ;HERE B IS GREATEST
    B_GREATEST:
    LEA DX,MSGR
    MOV AH,9
    INT 21H
  
    MOV DL,B
    MOV AH,2
    INT 21H 
    
    JMP DONE
    
    ;Here A is greater than B
    A_greater:
    MOV CL,C
    CMP AL,CL
    JGE A_GREATEST
    
    ;HERE C IS GREATEST
    LEA DX,MSGR
    MOV AH,9
    INT 21H
  
    MOV DL,C
    MOV AH,2
    INT 21H 
    
    JMP DONE
     
    ;HERE A IS GREATEST
    A_GREATEST:
    LEA DX,MSGR
    MOV AH,9
    INT 21H
  
    MOV DL,A
    MOV AH,2
    INT 21H
    
    DONE: 
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
