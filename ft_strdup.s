segment		.text
	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	call	_ft_strlen		;
	add		rax, 1			;
	push	rdi				;
	mov		rdi, rax		;
	call	_malloc			;
	pop		rdx				;
	mov		rdi, rax		;
	mov		rsi, rdx		;
	call	_ft_strcpy		;
	jmp		exit

exit:
	ret	
