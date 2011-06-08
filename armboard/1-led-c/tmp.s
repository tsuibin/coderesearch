
led.bin:     file format binary


Disassembly of section .data:

00000000 <.data>:
   0:	e3a0da01 	mov	sp, #4096	; 0x1000
   4:	eaffffff 	b	0x8
   8:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   c:	e28db000 	add	fp, sp, #0
  10:	e3a03582 	mov	r3, #545259520	; 0x20800000
  14:	e3e02000 	mvn	r2, #0
  18:	e5c32000 	strb	r2, [r3]
  1c:	eafffffb 	b	0x10
