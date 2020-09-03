
segment		.text
	global		_ft_write
	extern 		___error

_ft_write:
	mov			rax, 0x2000004
	syscall
	jc			_error
	ret

_error:
    mov         rdx, rax            ; save errno
    call        ___error            ; retrieve address to errno
    mov         [rax], rdx          ; put errno in return value of __error (pointer to errno)
    mov         rax, -1
    ret

