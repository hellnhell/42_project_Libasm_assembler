section	.text
	global	_ft_read

_ft_read:
	mov 	rax, 0x2000003
	syscall
	jc		error
	jmp		exit

error:
	mov		rax, -1
	ret

exit:
	ret
