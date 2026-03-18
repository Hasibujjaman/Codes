; Roll: 2003001

;Q1.  Consider following Code Snippet:

; function main () 

; start

;        suppose A is an integer

;        suppose  B is an integer

;        A equal 2

;        B equal 3 add A sub 5

;        print(B)

; end

; Design Lexical Analysis, Syntax Analysis, Intermediate Code Generation and Code Generation part of compiler based on the code snippet.






;start -1
.686
.model flat, c
include C:\masm32\include\msvcrt.inc
includelib C:\masm32\lib\msvcrt.lib

.stack 100h
printf PROTO arg1:Ptr Byte, printlist:VARARG

.data
output_integer_msg_format byte "%d", 0Ah, 0
number sdword ?

.code

main proc
	push ebp
	mov ebp, esp
	sub ebp, 100
	mov ebx, ebp
	add ebx, 4

;ld_int 2
	mov eax, 2
	mov dword ptr [ebx], eax
	add ebx, 4


;store 0
	mov dword ptr [ebp-0], eax

;ld_int 3
	mov eax, 3
	mov dword ptr [ebx], eax
	add ebx, 4


;ld_var 0
	mov eax, [ebp-0]
	mov dword ptr [ebx], eax
	add ebx, 4


;add -1
	sub ebx, 4
	mov eax, [ebx]
	sub ebx, 4
	mov edx, [ebx]
	add eax, edx
	mov dword ptr [ebx], eax
	add ebx, 4


;ld_int 5
	mov eax, 5
	mov dword ptr [ebx], eax
	add ebx, 4


;sub -1
	sub ebx, 4
	mov eax, [ebx]
	sub ebx, 4
	mov edx, [ebx]
	sub edx, eax
	mov eax, edx
	mov dword ptr [ebx], eax
	add ebx, 4


;store 1
	mov dword ptr [ebp-4], eax

;print 1
	push eax
	push ebx
	push ecx
	push edx
	push ebp
	mov eax, [ebp-4]
	INVOKE printf, ADDR output_integer_msg_format, eax
	pop ebp
	pop edx
	pop ecx
	pop ebx
	pop eax

;halt -1
	add ebp, 100
	mov esp, ebp
	pop ebp
	ret
main endp
end