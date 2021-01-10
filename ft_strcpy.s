; char *strcpy (char *dest, const char *src);

section .text
	global ft_strcpy

ft_strcpy:
	xor	rax, rax

cpy_loop:
	mov	cl, BYTE [rsi + rax] ; moves src (rsi) at byte index (rax) into cl (8bits long scratch register) 
	mov	BYTE [rdi + rax], cl ; moves byte with index (cl) to dest (rdi) at index rax
	cmp	cl, 0
	je	exit
	inc	rax
	jmp	cpy_loop

exit:
	movsx	rax, cl ; put value of dst (rsi) into rax (the return value register) in correct signed register form
	ret
