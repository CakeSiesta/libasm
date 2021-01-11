section .text
	global ft_strcmp

ft_strcmp:
	xor	rax, rax

cmp_loop:


	inc	rdi
	inc	rsi
	jmp	cmp_loop
	
exit:
