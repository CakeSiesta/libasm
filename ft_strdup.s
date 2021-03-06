;char *ft_strdup(const char *s)
section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	xor		rax,rax
	cmp		rdi, 0			; if empty string
	jl		error			; return 0 -> go to error function
	push	rdi			; save first arg of strdup for later
	call	ft_strlen
	add		rax, 1			; add '\0'
	mov		rdi,rax
	call	malloc wrt ..plt
	cmp		rax, 0			; if malloc fails
	jl		error
	pop		r8			; take back the saved first arg
	mov		rdi,rax			; put allocated string to first arg of strcpy
	mov		rsi,r8			; put initial char *s into allocated string
	call	ft_strcpy
	ret

error:
	mov	rax, 0
	ret
