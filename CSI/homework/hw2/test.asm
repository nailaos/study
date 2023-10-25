
test:     file format elf64-x86-64


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

0000000000001020 <_ZNSolsEm@plt-0x10>:
    1020:	ff 35 ca 2f 00 00    	push   0x2fca(%rip)        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    *0x2fcc(%rip)        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <_ZNSolsEm@plt>:
    1030:	ff 25 ca 2f 00 00    	jmp    *0x2fca(%rip)        # 4000 <_ZNSolsEm@GLIBCXX_3.4>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <__cxa_atexit@plt>:
    1040:	ff 25 c2 2f 00 00    	jmp    *0x2fc2(%rip)        # 4008 <__cxa_atexit@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   $0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001050 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1050:	ff 25 ba 2f 00 00    	jmp    *0x2fba(%rip)        # 4010 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    1056:	68 02 00 00 00       	push   $0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001060 <_ZNSolsEPFRSoS_E@plt>:
    1060:	ff 25 b2 2f 00 00    	jmp    *0x2fb2(%rip)        # 4018 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    1066:	68 03 00 00 00       	push   $0x3
    106b:	e9 b0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001070 <_ZNSt8ios_base4InitC1Ev@plt>:
    1070:	ff 25 aa 2f 00 00    	jmp    *0x2faa(%rip)        # 4020 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    1076:	68 04 00 00t 00       	push   $0x4
    107b:	e9 a0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001080 <_ZNSolsEi@plt>:
    1080:	ff 25 a2 2f 00 00    	jmp    *0x2fa2(%rip)        # 4028 <_ZNSolsEi@GLIBCXX_3.4>
    1086:	68 05 00 00 00       	push   $0x5
    108b:	e9 90 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

0000000000001090 <__cxa_finalize@plt>:
    1090:	ff 25 1a 2f 00 00    	jmp    *0x2f1a(%rip)        # 3fb0 <__cxa_finalize@GLIBC_2.2.5>
    1096:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000010a0 <_start>:
    10a0:	31 ed                	xor    %ebp,%ebp
    10a2:	49 89 d1             	mov    %rdx,%r9
    10a5:	5e                   	pop    %rsi
    10a6:	48 89 e2             	mov    %rsp,%rdx
    10a9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10ad:	50                   	push   %rax
    10ae:	54                   	push   %rsp
    10af:	45 31 c0             	xor    %r8d,%r8d
    10b2:	31 c9                	xor    %ecx,%ecx
    10b4:	48 8d 3d ce 00 00 00 	lea    0xce(%rip),%rdi        # 1189 <main>
    10bb:	ff 15 ff 2e 00 00    	call   *0x2eff(%rip)        # 3fc0 <__libc_start_main@GLIBC_2.34>
    10c1:	f4                   	hlt
    10c2:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10c9:	00 00 00 
    10cc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000010d0 <deregister_tm_clones>:
    10d0:	48 8d 3d 69 2f 00 00 	lea    0x2f69(%rip),%rdi        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    10d7:	48 8d 05 62 2f 00 00 	lea    0x2f62(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    10de:	48 39 f8             	cmp    %rdi,%rax
    10e1:	74 15                	je     10f8 <deregister_tm_clones+0x28>
    10e3:	48 8b 05 de 2e 00 00 	mov    0x2ede(%rip),%rax        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    10ea:	48 85 c0             	test   %rax,%rax
    10ed:	74 09                	je     10f8 <deregister_tm_clones+0x28>
    10ef:	ff e0                	jmp    *%rax
    10f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10f8:	c3                   	ret
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <register_tm_clones>:
    1100:	48 8d 3d 39 2f 00 00 	lea    0x2f39(%rip),%rdi        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    1107:	48 8d 35 32 2f 00 00 	lea    0x2f32(%rip),%rsi        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    110e:	48 29 fe             	sub    %rdi,%rsi
    1111:	48 89 f0             	mov    %rsi,%rax
    1114:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1118:	48 c1 f8 03          	sar    $0x3,%rax
    111c:	48 01 c6             	add    %rax,%rsi
    111f:	48 d1 fe             	sar    %rsi
    1122:	74 14                	je     1138 <register_tm_clones+0x38>
    1124:	48 8b 05 ad 2e 00 00 	mov    0x2ead(%rip),%rax        # 3fd8 <_ITM_registerTMCloneTable@Base>
    112b:	48 85 c0             	test   %rax,%rax
    112e:	74 08                	je     1138 <register_tm_clones+0x38>
    1130:	ff e0                	jmp    *%rax
    1132:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1138:	c3                   	ret
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <__do_global_dtors_aux>:
    1140:	f3 0f 1e fa          	endbr64
    1144:	80 3d 05 30 00 00 00 	cmpb   $0x0,0x3005(%rip)        # 4150 <completed.0>
    114b:	75 2b                	jne    1178 <__do_global_dtors_aux+0x38>
    114d:	55                   	push   %rbp
    114e:	48 83 3d 5a 2e 00 00 	cmpq   $0x0,0x2e5a(%rip)        # 3fb0 <__cxa_finalize@GLIBC_2.2.5>
    1155:	00 
    1156:	48 89 e5             	mov    %rsp,%rbp
    1159:	74 0c                	je     1167 <__do_global_dtors_aux+0x27>
    115b:	48 8b 3d d6 2e 00 00 	mov    0x2ed6(%rip),%rdi        # 4038 <__dso_handle>
    1162:	e8 29 ff ff ff       	call   1090 <__cxa_finalize@plt>
    1167:	e8 64 ff ff ff       	call   10d0 <deregister_tm_clones>
    116c:	c6 05 dd 2f 00 00 01 	movb   $0x1,0x2fdd(%rip)        # 4150 <completed.0>
    1173:	5d                   	pop    %rbp
    1174:	c3                   	ret
    1175:	0f 1f 00             	nopl   (%rax)
    1178:	c3                   	ret
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <frame_dummy>:
    1180:	f3 0f 1e fa          	endbr64
    1184:	e9 77 ff ff ff       	jmp    1100 <register_tm_clones>

0000000000001189 <main>:
    1189:	55                   	push   %rbp
    118a:	48 89 e5             	mov    %rsp,%rbp
    118d:	48 83 ec 20          	sub    $0x20,%rsp
    1191:	f2 0f 10 05 77 0e 00 	movsd  0xe77(%rip),%xmm0        # 2010 <_IO_stdin_used+0x10>
    1198:	00 
    1199:	f2 0f 11 45 f8       	movsd  %xmm0,-0x8(%rbp)
    119e:	f3 0f 10 05 72 0e 00 	movss  0xe72(%rip),%xmm0        # 2018 <_IO_stdin_used+0x18>
    11a5:	00 
    11a6:	f3 0f 11 45 f4       	movss  %xmm0,-0xc(%rbp)
    11ab:	66 0f ef c0          	pxor   %xmm0,%xmm0
    11af:	f3 0f 5a 45 f4       	cvtss2sd -0xc(%rbp),%xmm0
    11b4:	f2 0f 58 45 f8       	addsd  -0x8(%rbp),%xmm0
    11b9:	f2 0f 5c 45 f8       	subsd  -0x8(%rbp),%xmm0
    11be:	66 0f ef c9          	pxor   %xmm1,%xmm1
    11c2:	f3 0f 5a 4d f4       	cvtss2sd -0xc(%rbp),%xmm1
    11c7:	66 0f 2e c1          	ucomisd %xmm1,%xmm0
    11cb:	7a 31                	jp     11fe <main+0x75>
    11cd:	66 0f 2e c1          	ucomisd %xmm1,%xmm0
    11d1:	75 2b                	jne    11fe <main+0x75>
    11d3:	48 8d 05 2e 0e 00 00 	lea    0xe2e(%rip),%rax        # 2008 <_IO_stdin_used+0x8>
    11da:	48 89 c6             	mov    %rax,%rsi
    11dd:	48 8d 05 5c 2e 00 00 	lea    0x2e5c(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    11e4:	48 89 c7             	mov    %rax,%rdi
    11e7:	e8 64 fe ff ff       	call   1050 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    11ec:	48 8b 15 c5 2d 00 00 	mov    0x2dc5(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    11f3:	48 89 d6             	mov    %rdx,%rsi
    11f6:	48 89 c7             	mov    %rax,%rdi
    11f9:	e8 62 fe ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    11fe:	be 04 00 00 00       	mov    $0x4,%esi
    1203:	48 8d 05 36 2e 00 00 	lea    0x2e36(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    120a:	48 89 c7             	mov    %rax,%rdi
    120d:	e8 1e fe ff ff       	call   1030 <_ZNSolsEm@plt>
    1212:	48 8b 15 9f 2d 00 00 	mov    0x2d9f(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    1219:	48 89 d6             	mov    %rdx,%rsi
    121c:	48 89 c7             	mov    %rax,%rdi
    121f:	e8 3c fe ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    1224:	be 08 00 00 00       	mov    $0x8,%esi
    1229:	48 8d 05 10 2e 00 00 	lea    0x2e10(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    1230:	48 89 c7             	mov    %rax,%rdi
    1233:	e8 f8 fd ff ff       	call   1030 <_ZNSolsEm@plt>
    1238:	48 8b 15 79 2d 00 00 	mov    0x2d79(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    123f:	48 89 d6             	mov    %rdx,%rsi
    1242:	48 89 c7             	mov    %rax,%rdi
    1245:	e8 16 fe ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    124a:	c7 45 f0 00 00 00 80 	movl   $0x80000000,-0x10(%rbp)
    1251:	8b 45 f0             	mov    -0x10(%rbp),%eax
    1254:	89 c6                	mov    %eax,%esi
    1256:	48 8d 05 e3 2d 00 00 	lea    0x2de3(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    125d:	48 89 c7             	mov    %rax,%rdi
    1260:	e8 1b fe ff ff       	call   1080 <_ZNSolsEi@plt>
    1265:	48 8b 15 4c 2d 00 00 	mov    0x2d4c(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    126c:	48 89 d6             	mov    %rdx,%rsi
    126f:	48 89 c7             	mov    %rax,%rdi
    1272:	e8 e9 fd ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    1277:	f7 5d f0             	negl   -0x10(%rbp)
    127a:	8b 45 f0             	mov    -0x10(%rbp),%eax
    127d:	89 c6                	mov    %eax,%esi
    127f:	48 8d 05 ba 2d 00 00 	lea    0x2dba(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    1286:	48 89 c7             	mov    %rax,%rdi
    1289:	e8 f2 fd ff ff       	call   1080 <_ZNSolsEi@plt>
    128e:	48 8b 15 23 2d 00 00 	mov    0x2d23(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    1295:	48 89 d6             	mov    %rdx,%rsi
    1298:	48 89 c7             	mov    %rax,%rdi
    129b:	e8 c0 fd ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    12a0:	c7 45 ec ef ff ff ff 	movl   $0xffffffef,-0x14(%rbp)
    12a7:	8b 45 ec             	mov    -0x14(%rbp),%eax
    12aa:	c1 f8 04             	sar    $0x4,%eax
    12ad:	89 45 e8             	mov    %eax,-0x18(%rbp)
    12b0:	8b 45 ec             	mov    -0x14(%rbp),%eax
    12b3:	8d 50 0f             	lea    0xf(%rax),%edx
    12b6:	85 c0                	test   %eax,%eax
    12b8:	0f 48 c2             	cmovs  %edx,%eax
    12bb:	c1 f8 04             	sar    $0x4,%eax
    12be:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    12c1:	8b 45 e8             	mov    -0x18(%rbp),%eax
    12c4:	89 c6                	mov    %eax,%esi
    12c6:	48 8d 05 73 2d 00 00 	lea    0x2d73(%rip),%rax        # 4040 <_ZSt4cout@GLIBCXX_3.4>
    12cd:	48 89 c7             	mov    %rax,%rdi
    12d0:	e8 ab fd ff ff       	call   1080 <_ZNSolsEi@plt>
    12d5:	48 89 c2             	mov    %rax,%rdx
    12d8:	48 8d 05 2e 0d 00 00 	lea    0xd2e(%rip),%rax        # 200d <_IO_stdin_used+0xd>
    12df:	48 89 c6             	mov    %rax,%rsi
    12e2:	48 89 d7             	mov    %rdx,%rdi
    12e5:	e8 66 fd ff ff       	call   1050 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    12ea:	48 89 c2             	mov    %rax,%rdx
    12ed:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    12f0:	89 c6                	mov    %eax,%esi
    12f2:	48 89 d7             	mov    %rdx,%rdi
    12f5:	e8 86 fd ff ff       	call   1080 <_ZNSolsEi@plt>
    12fa:	48 8b 15 b7 2c 00 00 	mov    0x2cb7(%rip),%rdx        # 3fb8 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    1301:	48 89 d6             	mov    %rdx,%rsi
    1304:	48 89 c7             	mov    %rax,%rdi
    1307:	e8 54 fd ff ff       	call   1060 <_ZNSolsEPFRSoS_E@plt>
    130c:	b8 00 00 00 00       	mov    $0x0,%eax
    1311:	c9                   	leave
    1312:	c3                   	ret

0000000000001313 <_Z41__static_initialization_and_destruction_0ii>:
    1313:	55                   	push   %rbp
    1314:	48 89 e5             	mov    %rsp,%rbp
    1317:	48 83 ec 10          	sub    $0x10,%rsp
    131b:	89 7d fc             	mov    %edi,-0x4(%rbp)
    131e:	89 75 f8             	mov    %esi,-0x8(%rbp)
    1321:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    1325:	75 3b                	jne    1362 <_Z41__static_initialization_and_destruction_0ii+0x4f>
    1327:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    132e:	75 32                	jne    1362 <_Z41__static_initialization_and_destruction_0ii+0x4f>
    1330:	48 8d 05 1a 2e 00 00 	lea    0x2e1a(%rip),%rax        # 4151 <_ZStL8__ioinit>
    1337:	48 89 c7             	mov    %rax,%rdi
    133a:	e8 31 fd ff ff       	call   1070 <_ZNSt8ios_base4InitC1Ev@plt>
    133f:	48 8d 05 f2 2c 00 00 	lea    0x2cf2(%rip),%rax        # 4038 <__dso_handle>
    1346:	48 89 c2             	mov    %rax,%rdx
    1349:	48 8d 05 01 2e 00 00 	lea    0x2e01(%rip),%rax        # 4151 <_ZStL8__ioinit>
    1350:	48 89 c6             	mov    %rax,%rsi
    1353:	48 8b 05 86 2c 00 00 	mov    0x2c86(%rip),%rax        # 3fe0 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    135a:	48 89 c7             	mov    %rax,%rdi
    135d:	e8 de fc ff ff       	call   1040 <__cxa_atexit@plt>
    1362:	90                   	nop
    1363:	c9                   	leave
    1364:	c3                   	ret

0000000000001365 <_GLOBAL__sub_I_main>:
    1365:	55                   	push   %rbp
    1366:	48 89 e5             	mov    %rsp,%rbp
    1369:	be ff ff 00 00       	mov    $0xffff,%esi
    136e:	bf 01 00 00 00       	mov    $0x1,%edi
    1373:	e8 9b ff ff ff       	call   1313 <_Z41__static_initialization_and_destruction_0ii>
    1378:	5d                   	pop    %rbp
    1379:	c3                   	ret

Disassembly of section .fini:

000000000000137c <_fini>:
    137c:	48 83 ec 08          	sub    $0x8,%rsp
    1380:	48 83 c4 08          	add    $0x8,%rsp
    1384:	c3                   	ret
