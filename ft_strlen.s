;size_t	ft_strlen(char const *str);

section .text
	global ft_strlen

ft_strlen:
	xor	rax,rax
	jmp	count

count:
	cmp	BYTE[rax + rdi], 0
	je	exit
	inc	rax
	jmp	count

exit:
	ret
