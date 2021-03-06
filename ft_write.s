; ssize_t	ft_write(int fd, const void *buf, size_t count);

section .text
	extern __errno_location
	global ft_write

ft_write:
	mov	rax, 1				; syscall of write
	syscall					; calls write
	cmp	rax, 0
	jl	error
	ret

error:
	neg	rax				;neg*neg = pos
	push	rax
	call	__errno_location wrt ..plt
	pop	qword [rax]
	mov	rax, -1
	ret
