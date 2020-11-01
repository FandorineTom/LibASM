	global	_ft_strcpy

_ft_strcpy:
	mov	rax, -1

_loop:
	inc	rax
	mov	cl, byte [rsi + rax]
	mov	byte [rdi + rax], cl
	cmp	byte[rsi + rax], 0
	jnz	_loop
	mov	rax, rdi
	ret
