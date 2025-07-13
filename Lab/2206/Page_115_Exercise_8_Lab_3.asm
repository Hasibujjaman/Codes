Title Experiment_no 4: Prog_1
.MODEL SMALL
.STACK 100H
.DATA
    CR   EQU 0DH
    LF   EQU 0AH                                        
    A    DB  ?
    B    DB  ?
    C    DB  '?'
    MSG1 DB  "Enter the 1st capital letter: $"
    MSG2 DB  CR,LF, "Enter the 2nd capital letter: $"

.CODE
MAIN PROC
    ;initalize DS
    MOV AX,@DATA
    MOV DS,AX
    
    ;user prompt 1
    LEA DX,MSG1     ; load effective address of MSG1 in DX / DX now has offset of MSG1
    MOV AH,9    ; to request function number 9 
    INT 21H     ; invoke DOS routine
    ;input 1
    MOV AH,1
    INT 21H
    MOV A,AL    ;store input 1 to A
    ADD A,32    ;store capital letter as small letter
    
    ;user prompt 2
    LEA DX,MSG2
    MOV AH,9
    INT 21H                
    ;input 2
    MOV AH,1
    INT 21H
    MOV B,AL                
    ADD B,32                
    
    ;Compare A and B
    MOV AL,A
    MOV BL,B
    CMP AL,BL
    JGE A_GREATER_BELOW
    
    ;Here B is greater
    ;print carriage return & new line
    MOV DL,CR
    MOV AH,2
    INT 21H
    MOV DL,LF
    MOV AH,2
    INT 21H                
    ;print "?"
    MOV AL,C
    MOV DL,AL
    MOV AH,2
    INT 21H                 
    ;print letter 1
    MOV AL,A
    MOV DL,AL
    MOV AH,2
    INT 21H                   
    ;print letter 2
    MOV AL,B
    MOV DL,AL
    MOV AH,2
    INT 21H                   

    JMP DONE 
    
    A_GREATER_BELOW:
    ;print
    ;print Carriage Return
    MOV AL,CR
    MOV DL,AL
    MOV AH,2
    INT 21H
    ;print Line feed
    MOV AL,LF
    MOV DL,AL
    MOV AH,2
    INT 21H                 
    ;print "?"
    MOV AL,C
    MOV DL,AL
    MOV AH,2
    INT 21H          
    ;print letter 1
    MOV AL,B
    MOV DL,AL
    MOV AH,2
    INT 21H                   
    ;print letter 2
    MOV AL,A
    MOV DL,AL
    MOV AH,2
    INT 21H
    
    
    DONE:              
    ;DOS exit
    MOV AH,4CH
    INT 21H

MAIN ENDP
END MAIN