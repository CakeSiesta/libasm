; int ft_strcmp(const char *s1, const char *s2);

section .text
	global _ft_strcmp

_ft_strcmp:
	mov	rax, -1

cmp_loop:

	inc	rax
	mov	cl, BYTE[rdi + rax]
	mov	dl, BYTE[rsi + rax]
	cmp	cl, 0 			; if str1[i] == '\0'
	je	exit
	cmp	dl, 0 			; if str2[i] == '\0'
	je	exit
	cmp	cl, dl 			; if str1[i] == str2[i]
	je	cmp_loop
	jmp	exit			; if str1[i] != str2[i]

exit:
	movsx	rax, cl
	movsx	rdx, dl
	sub	rax, rdx		; ret the diff of str1[i] and str2[i]
	ret
