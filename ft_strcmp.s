; int ft_strcmp(const char *s1, const char *s2);

section .text
	global ft_strcmp

ft_strcmp:
	xor	rcx, rcx
	xor	rdx, rdx

cmp_loop:
	inc	rax
	mov	dl, BYTE[rdi + rcx]	; smaller register of rdx
	cmp	dl, BYTE[rsi + rcx]	; compare if both strings are the same
	jne	check_overflow


	cmp	dl, 0 			; check if end of both strings
	jz	check_overflow
	inc	rcx
	jmp	cmp_loop

check_overflow:
	sub	dl, BYTE[rsi + rcx]
	movzx	rax,dl
	jnc	return			; if overflow flag inactive
	neg	al
	neg	eax
	ret

return:
	ret
