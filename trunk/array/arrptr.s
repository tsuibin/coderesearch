	.file	"arrptr.c"
	.section	.rodata
.LC0:
	.string	"hello world!"
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
	subl	$16, %esp
	movl	$.LC0, -12(%ebp)
	movb	$1, -5(%ebp)
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movb	%al, -5(%ebp)
	movl	$0, %eax
	addl	$16, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.2.4 (Ubuntu 4.2.4-1ubuntu4)"
	.section	.note.GNU-stack,"",@progbits
