
segment .text
	global _ft_strlen

_ft_strlen:
		mov	rax, 0  			;ret value (move 0 into rax register)
		jmp	count

count:
		cmp		BYTE [rdi + rax], 0	; if rdi(s) + rax(indic) = 0
		jz		exit				; end, if not increase de ret value
		inc 	rax
		jmp 	count

exit:
		ret