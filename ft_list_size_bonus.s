; ft_list_size(t_list *begin_list);
section .text
	global	ft_list_size

ft_list_size:
	xor	rax, rax

list_size_loop:
	cmp	rdi, 0		; lst == NULL ?
	je	return
	mov	rdi, [rdi + 8]	; next item in list
	inc	rax
	jmp	list_size_loop

return:
	ret
