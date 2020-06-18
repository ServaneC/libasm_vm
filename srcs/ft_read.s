		global	ft_read
		extern	__errno_location
		section	.text

ft_read:
			mov rax, 0
			syscall
			cmp rax, 0
			jl error
			jmp end

error:
		xor rdx, rdx
		neg rax
		mov rdx, rax
    	call __errno_location
		mov [rax], rdx
		mov rax, -1

end:
		ret