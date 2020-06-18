section	.text
		global	ft_strdup
		extern	ft_strlen
		extern	malloc
		extern	ft_strcpy
		extern __errno_location

ft_strdup:
		call ft_strlen
		push rdi
		mov rdi, rax
		inc rdi
		call malloc
		jc error
		pop rsi
		mov rdi, rax
		call ft_strcpy
		jmp end

error:
		xor rdx, rdx
		neg rax
		mov rdx, rax
    	call __errno_location
		mov [rax], rdx
		mov rax, 0

end:
		ret