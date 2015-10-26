	.file	"kmp.cc"
gcc2_compiled.:
___gnu_compiled_cplusplus:
.text
	.align 4
.globl _init_shifts__FPc
_init_shifts__FPc:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	pushl %ebx
	movl $-1,_shift
	nop
	movl $0,-4(%ebp)
	movl $-1,-8(%ebp)
L328:
	cmpl $2,-4(%ebp)
	setle %al
	testb %al,%al
	jne L331
	jmp L329
	.align 4,0x90
L331:
	nop
L332:
	xorb %al,%al
	movl -8(%ebp),%edx
	notl %edx
	movl %edx,%ecx
	shrl $31,%ecx
	testb %cl,%cl
	je L335
	movl 8(%ebp),%ecx
	addl -4(%ebp),%ecx
	movl %ecx,%edx
	movl 8(%ebp),%ecx
	addl -8(%ebp),%ecx
	movl %ecx,%ebx
	movb (%edx),%dl
	cmpb %dl,(%ebx)
	setne %dl
	testb %dl,%dl
	je L335
	movb $1,%al
L335:
	testb %al,%al
	jne L334
	jmp L333
	.align 4,0x90
L334:
	movl -8(%ebp),%eax
	movl _shift(,%eax,4),%edx
	movl %edx,-8(%ebp)
	jmp L332
	.align 4,0x90
L333:
L330:
	incl -4(%ebp)
	incl -8(%ebp)
	movl -4(%ebp),%eax
	movl -8(%ebp),%edx
	movl %edx,_shift(,%eax,4)
	jmp L328
	.align 4,0x90
L329:
L327:
	movl -12(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
	.align 4
.globl _kmp__FPcT0
_kmp__FPcT0:
	pushl %ebp
	movl %esp,%ebp
	subl $12,%esp
	pushl %ebx
	movl 12(%ebp),%eax
	pushl %eax
	call _strlen
	addl $4,%esp
	movl %eax,-12(%ebp)
	movl $0,-4(%ebp)
	movl $0,-8(%ebp)
L337:
	xorb %al,%al
	movl -4(%ebp),%edx
	cmpl %edx,-12(%ebp)
	setg %dl
	testb %dl,%dl
	je L341
	cmpl $3,-8(%ebp)
	setle %dl
	testb %dl,%dl
	je L341
	movb $1,%al
L341:
	testb %al,%al
	jne L340
	jmp L338
	.align 4,0x90
L340:
	nop
L342:
	xorb %al,%al
	movl -8(%ebp),%edx
	notl %edx
	movl %edx,%ecx
	shrl $31,%ecx
	testb %cl,%cl
	je L345
	movl 12(%ebp),%ecx
	addl -4(%ebp),%ecx
	movl %ecx,%edx
	movl 8(%ebp),%ecx
	addl -8(%ebp),%ecx
	movl %ecx,%ebx
	movb (%edx),%dl
	cmpb %dl,(%ebx)
	setne %dl
	testb %dl,%dl
	je L345
	movb $1,%al
L345:
	testb %al,%al
	jne L344
	jmp L343
	.align 4,0x90
L344:
	movl -8(%ebp),%eax
	movl _shift(,%eax,4),%edx
	movl %edx,-8(%ebp)
	jmp L342
	.align 4,0x90
L343:
L339:
	incl -4(%ebp)
	incl -8(%ebp)
	jmp L337
	.align 4,0x90
L338:
	cmpl $4,-8(%ebp)
	sete %al
	testb %al,%al
	je L346
	movl -4(%ebp),%edx
	addl $-4,%edx
	movl %edx,%eax
	jmp L336
	.align 4,0x90
	jmp L336
	.align 4,0x90
	jmp L347
	.align 4,0x90
L346:
	movl $-1,%eax
	jmp L336
	.align 4,0x90
	jmp L336
	.align 4,0x90
L347:
L336:
	movl -16(%ebp),%ebx
	movl %ebp,%esp
	popl %ebp
	ret
