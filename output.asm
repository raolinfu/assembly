
section .data
	LF 				equ 10
	NULL			equ 0
	TRUE 			equ 1
	FALSE 			equ 0
	EXIT_SUCCESS 	equ 0
	STDIN 			equ 0
	STDOUT 			equ 1
	STDERR 			equ 2

	SYS_read 		equ 0
	SYS_write 		equ 1
	SYS_open 		equ 2
	SYS_close 		equ 3
	SYS_exit 		equ 60

	message1		db	"Hello World", LF, NULL
	message2		db	"Hello Rao", NULL

section 	.text
global	_start
_start:
	mov	rdi, message1
	call	printString
exampleDone:
	mov 	rax, SYS_exit
	mov 	rdi, EXIT_SUCCESS
	syscall

; function
global 	printString
printString:
	push 	rbx
; call os to output string
	mov 	rax, SYS_write
	mov 	rsi, rdi
	mov 	rdi, STDOUT
	syscall
prtDone:
	pop 	rbx
	ret

