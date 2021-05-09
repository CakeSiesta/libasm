; ssize_t read(int fd, void *buf, size_t count)

section .text
	extern __errno_location
	global ft_read

ft_read:
	mov	rax,0
	syscall
	cmp	rax,0
	jl	error
	ret

error:
	neg 	rax				;neg*neg=pos
	push	rax
	call	__errno_location wrt ..plt
	pop	qword [rax]
	mov	rax, -1
	ret
