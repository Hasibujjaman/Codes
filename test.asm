.MODEL SMALL
.STACK 100h
.DATA
CR EQU 0DH ;carrige reuturn
LF EQU 0AH ;line feed
msg1 DB "Enter 1st byte : $"
msg2 DB CR,LF,"Enter 2nd byte : $"
msg3 DB CR,LF,"Enter a word : $"
A DB ?
B DB ?
World1 DW ?
Quad1 DQ "XYABPQRS" ;quad words
TenByte1 DT "0123456789" ;ten bytes

result DB ?

.CODE  
Main Proc 
;initialize DS
MOV AX,@DATA
MOV DS,AX 
                                                                                      
;print user promt
LEA DX,msg1
MOV AH,9
INT 21H  

;intput the 1st byte
MOV AH,1
INT 21H
MOV A,AL ; store the std input in variable A

;print user promt
LEA DX,msg2
MOV AH,9
INT 21H 

;Input the 2nd byte
MOV AH,1
INT 21H
MOV B,AL ; store the std input in variable B

;print prompt
LEA DX,msg3
MOV AH,9
INT 21H

;Input a word
MOV AH,1
INT 21H
MOV World1,AX

;Calculations 
;MOV AH,TenByte1 ; illegal: byte, ten byte
;mov ax,Quad1 ; illegal: word , quad word
mov al,"f" ;
mov ax,"ff"
;mov ax,"fff"  ;illegal : word, three byte
;MOV BL,World1 ; illegal: Byte, quad word
MOV CX,World1 ; Word , Word

;print new line
MOV DL,LF
MOV AH,2
INT 21H
;print A
MOV DL,255
MOV AH,2
INT 21H

;DOS exit
MOV AH,4CH
INT 21H       
MAIN ENDP
    END MAIN
