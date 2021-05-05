; char *strcpy (char *dest, const char *src);

section .text
	global _ft_strcpy

_ft_strcpy:
	xor	rcx, rcx
	xor	rdx, rdx
	cmp	rsi, 0
	jz	exit
	jmp	cpy_loop

cpy_loop:
	mov	dl, BYTE[rcx + rsi]
	mov	BYTE[rcx + rdi], dl
	cmp	dl, 0
	jz	exit
	inc	rcx
	jmp	cpy_loop

exit:
	mov rax, rdi
	ret
