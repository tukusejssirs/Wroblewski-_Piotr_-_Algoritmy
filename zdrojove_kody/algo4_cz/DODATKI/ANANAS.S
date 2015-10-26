	.file	"ananas.cc"
gcc2_compiled.:
___gnu_compiled_cplusplus:
.text
	.align 4
.globl _kmp_ananas__FPc
_kmp_ananas__FPc:
	pushl %ebp
	movl %esp,%ebp
	subl $4,%esp
	movl $-1,-4(%ebp)
L328:
	incl -4(%ebp)
L329:
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $97,(%edx)
	setne %al
	testb %al,%al
	je L330
	jmp L328
	.align 4,0x90
L330:
	incl -4(%ebp)
L331:
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $110,(%edx)
	setne %al
	testb %al,%al
	je L332
	jmp L329
	.align 4,0x90
L332:
	incl -4(%ebp)
L333:
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $97,(%edx)
	setne %al
	testb %al,%al
	je L334
	jmp L329
	.align 4,0x90
L334:
	incl -4(%ebp)
L335:
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $110,(%edx)
	setne %al
	testb %al,%al
	je L336
	jmp L331
	.align 4,0x90
L336:
	incl -4(%ebp)
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $97,(%edx)
	setne %al
	testb %al,%al
	je L337
	jmp L333
	.align 4,0x90
L337:
	incl -4(%ebp)
	movl 8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,%edx
	cmpb $115,(%edx)
	setne %al
	testb %al,%al
	je L338
	jmp L335
	.align 4,0x90
L338:
	incl -4(%ebp)
	movl -4(%ebp),%edx
	addl $-6,%edx
	movl %edx,%eax
	jmp L327
	.align 4,0x90
	jmp L327
	.align 4,0x90
	jmp L339
	.align 4,0x90
	jmp L327
	.align 4,0x90
L339:
L327:
	movl %ebp,%esp
	popl %ebp
	ret
