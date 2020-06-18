			global ft_strlen

			section	.text

ft_strlen:
				mov rax, -1

count:			
				inc rax
				cmp byte[rdi + rax], 0
				jne count 
end:
				ret