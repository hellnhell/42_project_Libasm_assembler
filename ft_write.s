
segment		.text
	global		_ft_write
	extern 		___error

_ft_write:
	mov			rax, 0x2000004
	syscall
	jc			_error
	ret

_error:
    mov         rdx, rax            ; guardas errno
    call        ___error            ; 
    mov         [rax], rdx          ; Pones errno como valor de ret de ___error(pointer a errno)
    mov         rax, -1
    ret

