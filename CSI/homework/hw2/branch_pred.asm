
branch_pred:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	48 83 ec 08          	sub    $0x8,%rsp
    1004:	48 8b 05 c5 2f 00 00 	mov    0x2fc5(%rip),%rax        # 3fd0 <__gmon_start__@Base>
    100b:	48 85 c0             	test   %rax,%rax
    100e:	74 02                	je     1012 <_init+0x12>
    1010:	ff d0                	call   *%rax
    1012:	48 83 c4 08          	add    $0x8,%rsp
    1016:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <strtol@plt-0x10>:
    1020:	ff 35 ca 2f 00 00    	push   0x2fca(%rip)        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    *0x2fcc(%rip)        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <strtol@plt>:
    1030:	ff 25 ca 2f 00 00    	jmp    *0x2fca(%rip)        # 4000 <strtol@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	ff 25 9a 2f 00 00    	jmp    *0x2f9a(%rip)        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1046:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000001050 <main>:
    1050:	48 83 ec 08          	sub    $0x8,%rsp
    1054:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    1058:	ba 0a 00 00 00       	mov    $0xa,%edx
    105d:	31 f6                	xor    %esi,%esi
    105f:	e8 cc ff ff ff       	call   1030 <strtol@plt>
    1064:	48 83 c4 08          	add    $0x8,%rsp
    1068:	89 c2                	mov    %eax,%edx
    106a:	0f af d0             	imul   %eax,%edx
    106d:	8d 44 02 fe          	lea    -0x2(%rdx,%rax,1),%eax
    1071:	c3                   	ret
    1072:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    1079:	00 00 00 
    107c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001080 <_start>:
    1080:	31 ed                	xor    %ebp,%ebp
    1082:	49 89 d1             	mov    %rdx,%r9
    1085:	5e                   	pop    %rsi
    1086:	48 89 e2             	mov    %rsp,%rdx
    1089:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    108d:	50                   	push   %rax
    108e:	54                   	push   %rsp
    108f:	45 31 c0             	xor    %r8d,%r8d
    1092:	31 c9                	xor    %ecx,%ecx
    1094:	48 8d 3d b5 ff ff ff 	lea    -0x4b(%rip),%rdi        # 1050 <main>
    109b:	ff 15 1f 2f 00 00    	call   *0x2f1f(%rip)        # 3fc0 <__libc_start_main@GLIBC_2.34>
    10a1:	f4                   	hlt
    10a2:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10a9:	00 00 00 
    10ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000010b0 <deregister_tm_clones>:
    10b0:	48 8d 3d 61 2f 00 00 	lea    0x2f61(%rip),%rdi        # 4018 <__TMC_END__>
    10b7:	48 8d 05 5a 2f 00 00 	lea    0x2f5a(%rip),%rax        # 4018 <__TMC_END__>
    10be:	48 39 f8             	cmp    %rdi,%rax
    10c1:	74 15                	je     10d8 <deregister_tm_clones+0x28>
    10c3:	48 8b 05 fe 2e 00 00 	mov    0x2efe(%rip),%rax        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    10ca:	48 85 c0             	test   %rax,%rax
    10cd:	74 09                	je     10d8 <deregister_tm_clones+0x28>
    10cf:	ff e0                	jmp    *%rax
    10d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10d8:	c3                   	ret
    10d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010e0 <register_tm_clones>:
    10e0:	48 8d 3d 31 2f 00 00 	lea    0x2f31(%rip),%rdi        # 4018 <__TMC_END__>
    10e7:	48 8d 35 2a 2f 00 00 	lea    0x2f2a(%rip),%rsi        # 4018 <__TMC_END__>
    10ee:	48 29 fe             	sub    %rdi,%rsi
    10f1:	48 89 f0             	mov    %rsi,%rax
    10f4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10f8:	48 c1 f8 03          	sar    $0x3,%rax
    10fc:	48 01 c6             	add    %rax,%rsi
    10ff:	48 d1 fe             	sar    %rsi
    1102:	74 14                	je     1118 <register_tm_clones+0x38>
    1104:	48 8b 05 cd 2e 00 00 	mov    0x2ecd(%rip),%rax        # 3fd8 <_ITM_registerTMCloneTable@Base>
    110b:	48 85 c0             	test   %rax,%rax
    110e:	74 08                	je     1118 <register_tm_clones+0x38>
    1110:	ff e0                	jmp    *%rax
    1112:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1118:	c3                   	ret
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <__do_global_dtors_aux>:
    1120:	f3 0f 1e fa          	endbr64
    1124:	80 3d ed 2e 00 00 00 	cmpb   $0x0,0x2eed(%rip)        # 4018 <__TMC_END__>
    112b:	75 2b                	jne    1158 <__do_global_dtors_aux+0x38>
    112d:	55                   	push   %rbp
    112e:	48 83 3d aa 2e 00 00 	cmpq   $0x0,0x2eaa(%rip)        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1135:	00 
    1136:	48 89 e5             	mov    %rsp,%rbp
    1139:	74 0c                	je     1147 <__do_global_dtors_aux+0x27>
    113b:	48 8b 3d ce 2e 00 00 	mov    0x2ece(%rip),%rdi        # 4010 <__dso_handle>
    1142:	e8 f9 fe ff ff       	call   1040 <__cxa_finalize@plt>
    1147:	e8 64 ff ff ff       	call   10b0 <deregister_tm_clones>
    114c:	c6 05 c5 2e 00 00 01 	movb   $0x1,0x2ec5(%rip)        # 4018 <__TMC_END__>
    1153:	5d                   	pop    %rbp
    1154:	c3                   	ret
    1155:	0f 1f 00             	nopl   (%rax)
    1158:	c3                   	ret
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	endbr64
    1164:	e9 77 ff ff ff       	jmp    10e0 <register_tm_clones>

Disassembly of section .fini:

000000000000116c <_fini>:
    116c:	48 83 ec 08          	sub    $0x8,%rsp
    1170:	48 83 c4 08          	add    $0x8,%rsp
    1174:	c3                   	ret
