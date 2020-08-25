
segment		.text
	global	_ft_strcmp

_ft_strcmp:		;(s1, s2)
	mov		rax, 0
	jmp 	compare

compare:
	mov		al, BYTE [rdi]
	mov		bl, BYTE [rsi]
	cmp		al, 0
	je		exit
	cmp		bl, 0
	je 		exit
	cmp		bl, al
	jne		exit
	inc 	rdi
	inc		rsi
	call	compare

exit:
	movzx	rax, al
	movzx	rbx, bl
	sub		rax, rbx
	ret