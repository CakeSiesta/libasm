; char *strcpy (char *dest, const char *src);

section .text
	global ft_strcpy

ft_strcpy:
	xor	rax, rax

cpy_loop:
	mov	dl, BYTE [rsi + rax] ; moves src (rsi) at byte index (rax) into dl (scratch register) 
	mov	BYTE [rdi + rax], dl ; moves byte with index (dl) to rdi (dest) at index rax
	cmp	dl, 0
	je	exit
	inc	rax
	jmp	cpy_loop

exit:
	mov	rax, rdi ; put value of dst (rsi) into rax (the return value register)
	ret
