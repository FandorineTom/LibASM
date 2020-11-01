	global	_ft_write
	extern	___error

_ft_write:
	mov		rax, 0x2000004
	syscall
	jb		_err
	ret

_err:
	push	rax
	call	___error
	pop		rbx
	mov		[rax], rbx
	mov		rax, -1
	ret
