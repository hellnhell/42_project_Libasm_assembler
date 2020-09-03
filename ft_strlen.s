
segment .text
	global		 _ft_strlen

_ft_strlen:
	mov			rax, 0
	jmp			_count

_count:
	cmp			BYTE [rdi + rax], 0	; if rdi(s) + rax(indic) = 0
	jz			exit
	inc		 	rax
	jmp		 	_count

exit:
	ret