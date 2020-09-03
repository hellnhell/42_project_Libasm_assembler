
segment		.text
	global		_ft_strcmp

_ft_strcmp:		;(s1, s2)
	mov			rax, 0
	jmp 		_compare

_compare:
	mov			al, BYTE [rdi]
	mov			bl, BYTE [rsi]
	cmp			al, 0
	je			_exit
	cmp			bl, 0
	je 			_exit
	cmp			bl, al
	jne			_exit
	inc 		rdi
	inc			rsi
	call		_compare

_exit:
	movzx		rax, al
	movzx		rbx, bl
	sub			rax, rbx
	ret