	.file	"template.cc"
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__I_main
	.text
	.align 2
	.p2align 4,,15
	.type	_Z17__gthread_triggerv, @function
_Z17__gthread_triggerv:
.LFB12:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	movl	$1, __gthread_active(%rip)
	leave
	ret
.LFE12:
	.size	_Z17__gthread_triggerv, .-_Z17__gthread_triggerv
.globl __gxx_personality_v0
	.section	.gnu.linkonce.t._ZSt3minImERKT_S2_S2_,"ax",@progbits
	.align 2
	.p2align 4,,15
	.weak	_ZSt3minImERKT_S2_S2_
	.type	_ZSt3minImERKT_S2_S2_, @function
_ZSt3minImERKT_S2_S2_:
.LFB1437:
	pushq	%rbp
.LCFI2:
	movq	%rsp, %rbp
.LCFI3:
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jae	.L4
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L6
.L4:
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
.L6:
	movq	-24(%rbp), %rax
	leave
	ret
.LFE1437:
	.size	_ZSt3minImERKT_S2_S2_, .-_ZSt3minImERKT_S2_S2_
	.text
	.align 2
	.p2align 4,,15
	.type	_ZSt17__verify_groupingPKcmRKSs, @function
_ZSt17__verify_groupingPKcmRKSs:
.LFB1366:
	pushq	%rbp
.LCFI4:
	movq	%rsp, %rbp
.LCFI5:
	pushq	%rbx
.LCFI6:
	subq	$72, %rsp
.LCFI7:
	movq	%rdi, -64(%rbp)
	movq	%rsi, -72(%rbp)
	movq	%rdx, -80(%rbp)
	movq	-80(%rbp), %rdi
	call	_ZNKSs4sizeEv
	subq	$1, %rax
	movq	%rax, -56(%rbp)
	movq	-72(%rbp), %rax
	subq	$1, %rax
	movq	%rax, -48(%rbp)
	leaq	-48(%rbp), %rsi
	leaq	-56(%rbp), %rdi
	call	_ZSt3minImERKT_S2_S2_
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movb	$1, -17(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L9
.L10:
	movq	-32(%rbp), %rsi
	movq	-80(%rbp), %rdi
	call	_ZNKSsixEm
	movzbl	(%rax), %edx
	movq	-16(%rbp), %rax
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	sete	%al
	movb	%al, -17(%rbp)
	subq	$1, -32(%rbp)
	addq	$1, -16(%rbp)
.L9:
	movq	-16(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jae	.L13
	cmpb	$0, -17(%rbp)
	jne	.L10
	jmp	.L13
.L14:
	movq	-32(%rbp), %rsi
	movq	-80(%rbp), %rdi
	call	_ZNKSsixEm
	movzbl	(%rax), %edx
	movq	-40(%rbp), %rax
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	sete	%al
	movb	%al, -17(%rbp)
	subq	$1, -32(%rbp)
.L13:
	cmpq	$0, -32(%rbp)
	je	.L15
	cmpb	$0, -17(%rbp)
	jne	.L14
.L15:
	movq	-40(%rbp), %rax
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jle	.L17
	movzbl	-17(%rbp), %ebx
	movq	-80(%rbp), %rdi
	movl	$0, %esi
	call	_ZNKSsixEm
	movzbl	(%rax), %edx
	movq	-40(%rbp), %rax
	addq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	setle	%al
	movzbl	%al, %eax
	andl	%ebx, %eax
	testl	%eax, %eax
	setne	%al
	movb	%al, -17(%rbp)
.L17:
	movzbl	-17(%rbp), %eax
	addq	$72, %rsp
	popq	%rbx
	leave
	ret
.LFE1366:
	.size	_ZSt17__verify_groupingPKcmRKSs, .-_ZSt17__verify_groupingPKcmRKSs
	.align 2
	.p2align 4,,15
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1443:
	pushq	%rbp
.LCFI8:
	movq	%rsp, %rbp
.LCFI9:
	subq	$16, %rsp
.LCFI10:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L24
	cmpl	$65535, -8(%rbp)
	jne	.L24
	movl	$_ZSt8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$0, %esi
	movl	$__tcf_0, %edi
	call	__cxa_atexit
.L24:
	leave
	ret
.LFE1443:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align 2
	.p2align 4,,15
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB1445:
	pushq	%rbp
.LCFI11:
	movq	%rsp, %rbp
.LCFI12:
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	ret
.LFE1445:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.align 2
	.p2align 4,,15
	.type	__tcf_0, @function
__tcf_0:
.LFB1444:
	pushq	%rbp
.LCFI13:
	movq	%rsp, %rbp
.LCFI14:
	subq	$16, %rsp
.LCFI15:
	movq	%rdi, -8(%rbp)
	movl	$_ZSt8__ioinit, %edi
	call	_ZNSt8ios_base4InitD1Ev
	leave
	ret
.LFE1444:
	.size	__tcf_0, .-__tcf_0
	.align 2
	.p2align 4,,15
.globl main
	.type	main, @function
main:
.LFB1436:
	pushq	%rbp
.LCFI16:
	movq	%rsp, %rbp
.LCFI17:
	movl	$479001600, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$0, %eax
	leave
	ret
.LFE1436:
	.size	main, .-main
	.local	_ZSt8__ioinit
	.comm	_ZSt8__ioinit,1,1
	.data
	.align 4
	.type	__gthread_active, @object
	.size	__gthread_active, 4
__gthread_active:
	.long	-1
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zPR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x6
	.byte	0x3
	.long	__gxx_personality_v0
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB12
	.long	.LFE12-.LFB12
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB12
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB1437
	.long	.LFE1437-.LFB1437
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI2-.LFB1437
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI3-.LCFI2
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB1366
	.long	.LFE1366-.LFB1366
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI4-.LFB1366
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI5-.LCFI4
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.long	.LCFI7-.LCFI5
	.byte	0x83
	.uleb128 0x3
	.align 8
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB1443
	.long	.LFE1443-.LFB1443
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI8-.LFB1443
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI9-.LCFI8
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.long	.LFB1445
	.long	.LFE1445-.LFB1445
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI11-.LFB1445
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI12-.LCFI11
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE9:
.LSFDE11:
	.long	.LEFDE11-.LASFDE11
.LASFDE11:
	.long	.LASFDE11-.Lframe1
	.long	.LFB1444
	.long	.LFE1444-.LFB1444
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI13-.LFB1444
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI14-.LCFI13
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE11:
.LSFDE13:
	.long	.LEFDE13-.LASFDE13
.LASFDE13:
	.long	.LASFDE13-.Lframe1
	.long	.LFB1436
	.long	.LFE1436-.LFB1436
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI16-.LFB1436
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI17-.LCFI16
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE13:
	.ident	"GCC: (GNU) 4.2.1 20070719  [FreeBSD]"
