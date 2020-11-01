	global	_ft_strcmp

_ft_strcmp:
	mov	rdx, -1

_loop:
	inc	rdx
	mov cl, byte [rdi + rdx]
	sub cl, byte [rsi + rdx]
	cmp	cl, 0
	jne	_end
	cmp	byte [rdi + rdx], 0
	je	_end
	jmp	_loop

_end:
	movsx	rax, cl
	ret