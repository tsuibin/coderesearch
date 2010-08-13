	.file	"arrptr1.c"
	.section	.rodata
.LC0:
	.string	"hello world!"
	.zero	7
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	4(%ecx), %eax
	movl	%eax, -40(%ebp)
	movl	%gs:20, %eax
	movl	%eax, -8(%ebp)
	xorl	%eax, %eax
	movl	.LC0, %eax
	movl	%eax, -28(%ebp)
	movl	.LC0+4, %eax
	movl	%eax, -24(%ebp)
	movl	.LC0+8, %eax
	movl	%eax, -20(%ebp)
	movzbl	.LC0+12, %eax
	movb	%al, -16(%ebp)
	movl	$0, -15(%ebp)
	movw	$0, -11(%ebp)
	movb	$0, -9(%ebp)
	movb	$1, -29(%ebp)
	movzbl	-27(%ebp), %eax
	movb	%al, -29(%ebp)
	movl	$0, %eax
	movl	-8(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L3
	call	__stack_chk_fail
.L3:
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.2.4 (Ubuntu 4.2.4-1ubuntu4)"
	.section	.note.GNU-stack,"",@progbits
