.386
.MODEL FLAT, C
.STACK 4096

.DATA



printArrayFromAssembly PROTO C


.CODE 
_insertionSortAsm PROC C
	push esp
	mov ebp, esp
	
	push DWORD PTR[ebp] 
	call printArrayFromAssembly
	pop ebp
	ret

_insertionSortAsm ENDP
END
