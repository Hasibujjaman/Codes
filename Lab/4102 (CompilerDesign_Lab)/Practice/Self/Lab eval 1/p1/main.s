	.arch armv8.4-a+fp16+sb+ssbs
	.build_version macos,  14, 0
	.text
	.cstring
	.align	3
lC0:
	.ascii "Sum: %d\12\0"
	.text
	.align	2
	.globl _main
_main:
LFB20:
	sub	sp, sp, #48
LCFI0:
	stp	x29, x30, [sp, 16]
LCFI1:
	add	x29, sp, 16
LCFI2:
	mov	w0, 10
	str	w0, [x29, 28]
	mov	w0, 20
	str	w0, [x29, 24]
	ldr	w1, [x29, 28]
	ldr	w0, [x29, 24]
	add	w0, w1, w0
	str	w0, [sp]
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;
	bl	_printf
	mov	w0, 0
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 48
LCFI3:
	ret
LFE20:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB20-.
	.set L$set$2,LFE20-LFB20
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB20
	.long L$set$3
	.byte	0xe
	.uleb128 0x30
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x20
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0xdd
	.byte	0xde
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 14.2.0_1) 14.2.0"
	.subsections_via_symbols
