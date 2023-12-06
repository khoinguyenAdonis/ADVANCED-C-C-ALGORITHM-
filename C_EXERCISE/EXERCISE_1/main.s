	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Error: %s\n"
	.text
	.globl	printError
	.type	printError, @function
printError:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	printError, .-printError
	.section	.rodata
.LC1:
	.string	"Warning: %s\n"
	.text
	.globl	printWarning
	.type	printWarning, @function
printWarning:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	printWarning, .-printWarning
	.section	.rodata
.LC2:
	.string	"Info :  %s\n"
	.text
	.globl	printInfo
	.type	printInfo, @function
printInfo:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	printInfo, .-printInfo
	.section	.rodata
.LC3:
	.string	"Debug: %s\n"
	.text
	.globl	printDebug
	.type	printDebug, @function
printDebug:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	printDebug, .-printDebug
	.section	.rodata
.LC4:
	.string	"Critical: %s\n"
	.text
	.globl	printCritical
	.type	printCritical, @function
printCritical:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	printCritical, .-printCritical
	.section	.rodata
.LC5:
	.string	"Sucess: %s\n"
	.text
	.globl	printSuccess
	.type	printSuccess, @function
printSuccess:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	printSuccess, .-printSuccess
	.section	.rodata
.LC6:
	.string	"x is not equal to 10"
.LC7:
	.string	"x is less than 10"
.LC8:
	.string	"x is greater than 10"
.LC9:
	.string	"x is less than 0"
.LC10:
	.string	"x is not equal to 0"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, -4(%rbp)
	cmpl	$10, -4(%rbp)
	jne	.L8
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	printError
.L8:
	cmpl	$9, -4(%rbp)
	jg	.L9
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	printWarning
.L9:
	cmpl	$10, -4(%rbp)
	jle	.L10
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	printWarning
.L10:
	cmpl	$0, -4(%rbp)
	jns	.L11
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	printWarning
.L11:
	cmpl	$0, -4(%rbp)
	jne	.L12
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	printWarning
.L12:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 12.3.0-1ubuntu1~23.04) 12.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
