section	.text
	global		_ft_read
	extern		___error

_ft_read:
	mov 		rax, 0x2000003
	syscall
	jc			_error
	jmp			_exit

_error:
	mov			r15, rax		;move errno in negative to rdx
	call		___error		
	mov			[rax], r15		;store error in pointer errno
	mov			rax, -1			;store -1 
	ret

_exit:
	ret
