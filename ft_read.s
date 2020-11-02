	global	_ft_read
	extern	___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		_err
	ret

_err:
	push	rax
	call	___error
	pop		rbx
	mov		[rax], rbx
	mov		rax, -1
	ret