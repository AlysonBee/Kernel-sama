
section .text
global load_page_directory

load_page_directory:
push ebp
mov ebp, esp
mov eax, [esp+8]
mov cr3, eax
mov esp, ebp
pop ebp
ret
