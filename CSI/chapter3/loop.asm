
loop1-1.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <zinrc>:
   0:	b8 00 00 00 00       	mov    $0x0,%eax
   5:	eb 11                	jmp    18 <zinrc+0x18>
   7:	48 63 d0             	movslq %eax,%rdx
   a:	48 8d 0c 97          	lea    (%rdi,%rdx,4),%rcx
   e:	8b 31                	mov    (%rcx),%esi
  10:	8d 56 01             	lea    0x1(%rsi),%edx
  13:	89 11                	mov    %edx,(%rcx)
  15:	83 c0 01             	add    $0x1,%eax
  18:	83 f8 04             	cmp    $0x4,%eax
  1b:	7e ea                	jle    7 <zinrc+0x7>
  1d:	c3                   	ret

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 44 65 62          	sub    %al,0x62(%rbp,%riz,2)
   a:	69 61 6e 20 31 32 2e 	imul   $0x2e323120,0x6e(%rcx),%esp
  11:	32 2e                	xor    (%rsi),%ch
  13:	30 2d 31 34 29 20    	xor    %ch,0x20293431(%rip)        # 2029344a <zinrc+0x2029344a>
  19:	31 32                	xor    %esi,(%rdx)
  1b:	2e 32 2e             	cs xor (%rsi),%ch
  1e:	30 00                	xor    %al,(%rax)

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
			20: R_X86_64_PC32	.text
  22:	00 00                	add    %al,(%rax)
  24:	1e                   	(bad)
	...
