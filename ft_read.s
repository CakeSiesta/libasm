; ssize_t read(int fd, void *buf, size_t count)

section .text
	extern ___error
	global _ft_read

_ft_read:
	mov	rax,0
	syscall
	cmp	rax,0
	jl	error
	ret

error:
	neg 	rax				;neg*neg=pos
	push	rax
	call	___error
	pop	rax
	mov	rax, -1
	ret
