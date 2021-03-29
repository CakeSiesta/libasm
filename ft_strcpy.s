; char *strcpy (char *dest, const char *src);

section .text
	global ft_strcpy

ft_strcpy:
	xor	rcx, rcx
	xor	rdx, rdx
	cmp	rsi, 0
	jz	exit
	jmp	cpy_loop

cpy_loop:
	mov	cl, BYTE[rcx + rsi]
	mov	BYTE[rcx + rdi], cl
	cmp	cl, 0
	jz	exit
	inc	rcx
	jmp	cpy_loop

exit:
	mov rax, rdi
	ret
