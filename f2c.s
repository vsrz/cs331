	.file	"f2c.c"
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1077936128
	.align 8
.LC1:
	.long	1908874354
	.long	1071761180
	.text
.globl f2c
	.type	f2c, @function
f2c:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	flds	8(%ebp)
	fldl	.LC0
	fsubrp	%st, %st(1)
	fldl	.LC1
	fmulp	%st, %st(1)
	fstps	-4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	flds	-8(%ebp)
	leave
	ret
	.size	f2c, .-f2c
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 20060404 (Red Hat 3.4.6-8)"
