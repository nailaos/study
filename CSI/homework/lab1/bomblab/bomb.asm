
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	48 83 ec 08          	sub    $0x8,%rsp
    1004:	48 8b 05 c5 3f 00 00 	mov    0x3fc5(%rip),%rax        # 4fd0 <__gmon_start__@Base>
    100b:	48 85 c0             	test   %rax,%rax
    100e:	74 02                	je     1012 <_init+0x12>
    1010:	ff d0                	call   *%rax
    1012:	48 83 c4 08          	add    $0x8,%rsp
    1016:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <getenv@plt-0x10>:
    1020:	ff 35 ca 3f 00 00    	push   0x3fca(%rip)        # 4ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 3f 00 00    	jmp    *0x3fcc(%rip)        # 4ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <getenv@plt>:
    1030:	ff 25 ca 3f 00 00    	jmp    *0x3fca(%rip)        # 5000 <getenv@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <__errno_location@plt>:
    1040:	ff 25 c2 3f 00 00    	jmp    *0x3fc2(%rip)        # 5008 <__errno_location@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   $0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001050 <strcpy@plt>:
    1050:	ff 25 ba 3f 00 00    	jmp    *0x3fba(%rip)        # 5010 <strcpy@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	push   $0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001060 <puts@plt>:
    1060:	ff 25 b2 3f 00 00    	jmp    *0x3fb2(%rip)        # 5018 <puts@GLIBC_2.2.5>
    1066:	68 03 00 00 00       	push   $0x3
    106b:	e9 b0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001070 <write@plt>:
    1070:	ff 25 aa 3f 00 00    	jmp    *0x3faa(%rip)        # 5020 <write@GLIBC_2.2.5>
    1076:	68 04 00 00 00       	push   $0x4
    107b:	e9 a0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001080 <strlen@plt>:
    1080:	ff 25 a2 3f 00 00    	jmp    *0x3fa2(%rip)        # 5028 <strlen@GLIBC_2.2.5>
    1086:	68 05 00 00 00       	push   $0x5
    108b:	e9 90 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001090 <printf@plt>:
    1090:	ff 25 9a 3f 00 00    	jmp    *0x3f9a(%rip)        # 5030 <printf@GLIBC_2.2.5>
    1096:	68 06 00 00 00       	push   $0x6
    109b:	e9 80 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010a0 <alarm@plt>:
    10a0:	ff 25 92 3f 00 00    	jmp    *0x3f92(%rip)        # 5038 <alarm@GLIBC_2.2.5>
    10a6:	68 07 00 00 00       	push   $0x7
    10ab:	e9 70 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010b0 <close@plt>:
    10b0:	ff 25 8a 3f 00 00    	jmp    *0x3f8a(%rip)        # 5040 <close@GLIBC_2.2.5>
    10b6:	68 08 00 00 00       	push   $0x8
    10bb:	e9 60 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010c0 <read@plt>:
    10c0:	ff 25 82 3f 00 00    	jmp    *0x3f82(%rip)        # 5048 <read@GLIBC_2.2.5>
    10c6:	68 09 00 00 00       	push   $0x9
    10cb:	e9 50 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010d0 <fgets@plt>:
    10d0:	ff 25 7a 3f 00 00    	jmp    *0x3f7a(%rip)        # 5050 <fgets@GLIBC_2.2.5>
    10d6:	68 0a 00 00 00       	push   $0xa
    10db:	e9 40 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010e0 <strcmp@plt>:
    10e0:	ff 25 72 3f 00 00    	jmp    *0x3f72(%rip)        # 5058 <strcmp@GLIBC_2.2.5>
    10e6:	68 0b 00 00 00       	push   $0xb
    10eb:	e9 30 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010f0 <signal@plt>:
    10f0:	ff 25 6a 3f 00 00    	jmp    *0x3f6a(%rip)        # 5060 <signal@GLIBC_2.2.5>
    10f6:	68 0c 00 00 00       	push   $0xc
    10fb:	e9 20 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001100 <gethostbyname@plt>:
    1100:	ff 25 62 3f 00 00    	jmp    *0x3f62(%rip)        # 5068 <gethostbyname@GLIBC_2.2.5>
    1106:	68 0d 00 00 00       	push   $0xd
    110b:	e9 10 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001110 <fprintf@plt>:
    1110:	ff 25 5a 3f 00 00    	jmp    *0x3f5a(%rip)        # 5070 <fprintf@GLIBC_2.2.5>
    1116:	68 0e 00 00 00       	push   $0xe
    111b:	e9 00 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001120 <strtol@plt>:
    1120:	ff 25 52 3f 00 00    	jmp    *0x3f52(%rip)        # 5078 <strtol@GLIBC_2.2.5>
    1126:	68 0f 00 00 00       	push   $0xf
    112b:	e9 f0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001130 <fflush@plt>:
    1130:	ff 25 4a 3f 00 00    	jmp    *0x3f4a(%rip)        # 5080 <fflush@GLIBC_2.2.5>
    1136:	68 10 00 00 00       	push   $0x10
    113b:	e9 e0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001140 <__isoc99_sscanf@plt>:
    1140:	ff 25 42 3f 00 00    	jmp    *0x3f42(%rip)        # 5088 <__isoc99_sscanf@GLIBC_2.7>
    1146:	68 11 00 00 00       	push   $0x11
    114b:	e9 d0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001150 <memmove@plt>:
    1150:	ff 25 3a 3f 00 00    	jmp    *0x3f3a(%rip)        # 5090 <memmove@GLIBC_2.2.5>
    1156:	68 12 00 00 00       	push   $0x12
    115b:	e9 c0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001160 <fopen@plt>:
    1160:	ff 25 32 3f 00 00    	jmp    *0x3f32(%rip)        # 5098 <fopen@GLIBC_2.2.5>
    1166:	68 13 00 00 00       	push   $0x13
    116b:	e9 b0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001170 <sprintf@plt>:
    1170:	ff 25 2a 3f 00 00    	jmp    *0x3f2a(%rip)        # 50a0 <sprintf@GLIBC_2.2.5>
    1176:	68 14 00 00 00       	push   $0x14
    117b:	e9 a0 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001180 <exit@plt>:
    1180:	ff 25 22 3f 00 00    	jmp    *0x3f22(%rip)        # 50a8 <exit@GLIBC_2.2.5>
    1186:	68 15 00 00 00       	push   $0x15
    118b:	e9 90 fe ff ff       	jmp    1020 <_init+0x20>

0000000000001190 <connect@plt>:
    1190:	ff 25 1a 3f 00 00    	jmp    *0x3f1a(%rip)        # 50b0 <connect@GLIBC_2.2.5>
    1196:	68 16 00 00 00       	push   $0x16
    119b:	e9 80 fe ff ff       	jmp    1020 <_init+0x20>

00000000000011a0 <sleep@plt>:
    11a0:	ff 25 12 3f 00 00    	jmp    *0x3f12(%rip)        # 50b8 <sleep@GLIBC_2.2.5>
    11a6:	68 17 00 00 00       	push   $0x17
    11ab:	e9 70 fe ff ff       	jmp    1020 <_init+0x20>

00000000000011b0 <__ctype_b_loc@plt>:
    11b0:	ff 25 0a 3f 00 00    	jmp    *0x3f0a(%rip)        # 50c0 <__ctype_b_loc@GLIBC_2.3>
    11b6:	68 18 00 00 00       	push   $0x18
    11bb:	e9 60 fe ff ff       	jmp    1020 <_init+0x20>

00000000000011c0 <socket@plt>:
    11c0:	ff 25 02 3f 00 00    	jmp    *0x3f02(%rip)        # 50c8 <socket@GLIBC_2.2.5>
    11c6:	68 19 00 00 00       	push   $0x19
    11cb:	e9 50 fe ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

00000000000011d0 <__cxa_finalize@plt>:
    11d0:	ff 25 0a 3e 00 00    	jmp    *0x3e0a(%rip)        # 4fe0 <__cxa_finalize@GLIBC_2.2.5>
    11d6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000000011e0 <_start>:
    11e0:	31 ed                	xor    %ebp,%ebp
    11e2:	49 89 d1             	mov    %rdx,%r9
    11e5:	5e                   	pop    %rsi
    11e6:	48 89 e2             	mov    %rsp,%rdx
    11e9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    11ed:	50                   	push   %rax
    11ee:	54                   	push   %rsp
    11ef:	45 31 c0             	xor    %r8d,%r8d
    11f2:	31 c9                	xor    %ecx,%ecx
    11f4:	48 8d 3d ce 00 00 00 	lea    0xce(%rip),%rdi        # 12c9 <main>
    11fb:	ff 15 bf 3d 00 00    	call   *0x3dbf(%rip)        # 4fc0 <__libc_start_main@GLIBC_2.34>
    1201:	f4                   	hlt
    1202:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    1209:	00 00 00 
    120c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001210 <deregister_tm_clones>:
    1210:	48 8d 3d 29 45 00 00 	lea    0x4529(%rip),%rdi        # 5740 <stdout@GLIBC_2.2.5>
    1217:	48 8d 05 22 45 00 00 	lea    0x4522(%rip),%rax        # 5740 <stdout@GLIBC_2.2.5>
    121e:	48 39 f8             	cmp    %rdi,%rax
    1221:	74 15                	je     1238 <deregister_tm_clones+0x28>
    1223:	48 8b 05 9e 3d 00 00 	mov    0x3d9e(%rip),%rax        # 4fc8 <_ITM_deregisterTMCloneTable@Base>
    122a:	48 85 c0             	test   %rax,%rax
    122d:	74 09                	je     1238 <deregister_tm_clones+0x28>
    122f:	ff e0                	jmp    *%rax
    1231:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1238:	c3                   	ret
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001240 <register_tm_clones>:
    1240:	48 8d 3d f9 44 00 00 	lea    0x44f9(%rip),%rdi        # 5740 <stdout@GLIBC_2.2.5>
    1247:	48 8d 35 f2 44 00 00 	lea    0x44f2(%rip),%rsi        # 5740 <stdout@GLIBC_2.2.5>
    124e:	48 29 fe             	sub    %rdi,%rsi
    1251:	48 89 f0             	mov    %rsi,%rax
    1254:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1258:	48 c1 f8 03          	sar    $0x3,%rax
    125c:	48 01 c6             	add    %rax,%rsi
    125f:	48 d1 fe             	sar    %rsi
    1262:	74 14                	je     1278 <register_tm_clones+0x38>
    1264:	48 8b 05 6d 3d 00 00 	mov    0x3d6d(%rip),%rax        # 4fd8 <_ITM_registerTMCloneTable@Base>
    126b:	48 85 c0             	test   %rax,%rax
    126e:	74 08                	je     1278 <register_tm_clones+0x38>
    1270:	ff e0                	jmp    *%rax
    1272:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1278:	c3                   	ret
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001280 <__do_global_dtors_aux>:
    1280:	f3 0f 1e fa          	endbr64
    1284:	80 3d dd 44 00 00 00 	cmpb   $0x0,0x44dd(%rip)        # 5768 <completed.0>
    128b:	75 2b                	jne    12b8 <__do_global_dtors_aux+0x38>
    128d:	55                   	push   %rbp
    128e:	48 83 3d 4a 3d 00 00 	cmpq   $0x0,0x3d4a(%rip)        # 4fe0 <__cxa_finalize@GLIBC_2.2.5>
    1295:	00 
    1296:	48 89 e5             	mov    %rsp,%rbp
    1299:	74 0c                	je     12a7 <__do_global_dtors_aux+0x27>
    129b:	48 8b 3d 46 3e 00 00 	mov    0x3e46(%rip),%rdi        # 50e8 <__dso_handle>
    12a2:	e8 29 ff ff ff       	call   11d0 <__cxa_finalize@plt>
    12a7:	e8 64 ff ff ff       	call   1210 <deregister_tm_clones>
    12ac:	c6 05 b5 44 00 00 01 	movb   $0x1,0x44b5(%rip)        # 5768 <completed.0>
    12b3:	5d                   	pop    %rbp
    12b4:	c3                   	ret
    12b5:	0f 1f 00             	nopl   (%rax)
    12b8:	c3                   	ret
    12b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012c0 <frame_dummy>:
    12c0:	f3 0f 1e fa          	endbr64
    12c4:	e9 77 ff ff ff       	jmp    1240 <register_tm_clones>

00000000000012c9 <main>:
    12c9:	53                   	push   %rbx
    12ca:	83 ff 01             	cmp    $0x1,%edi
    12cd:	0f 84 f8 00 00 00    	je     13cb <main+0x102>
    12d3:	48 89 f3             	mov    %rsi,%rbx
    12d6:	83 ff 02             	cmp    $0x2,%edi
    12d9:	0f 85 1c 01 00 00    	jne    13fb <main+0x132>
    12df:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
    12e3:	48 8d 35 1a 1d 00 00 	lea    0x1d1a(%rip),%rsi        # 3004 <_IO_stdin_used+0x4>
    12ea:	e8 71 fe ff ff       	call   1160 <fopen@plt>
    12ef:	48 89 05 7a 44 00 00 	mov    %rax,0x447a(%rip)        # 5770 <infile>
    12f6:	48 85 c0             	test   %rax,%rax
    12f9:	0f 84 df 00 00 00    	je     13de <main+0x115>
    12ff:	e8 f1 05 00 00       	call   18f5 <initialize_bomb>
    1304:	48 8d 3d 7d 1d 00 00 	lea    0x1d7d(%rip),%rdi        # 3088 <_IO_stdin_used+0x88>
    130b:	e8 50 fd ff ff       	call   1060 <puts@plt>
    1310:	48 8d 3d b1 1d 00 00 	lea    0x1db1(%rip),%rdi        # 30c8 <_IO_stdin_used+0xc8>
    1317:	e8 44 fd ff ff       	call   1060 <puts@plt>
    131c:	e8 df 06 00 00       	call   1a00 <read_line>
    1321:	48 89 c7             	mov    %rax,%rdi
    1324:	e8 f0 00 00 00       	call   1419 <phase_1>
    1329:	e8 06 08 00 00       	call   1b34 <phase_defused>
    132e:	48 8d 3d c3 1d 00 00 	lea    0x1dc3(%rip),%rdi        # 30f8 <_IO_stdin_used+0xf8>
    1335:	e8 26 fd ff ff       	call   1060 <puts@plt>
    133a:	e8 c1 06 00 00       	call   1a00 <read_line>
    133f:	48 89 c7             	mov    %rax,%rdi
    1342:	e8 f2 00 00 00       	call   1439 <phase_2>
    1347:	e8 e8 07 00 00       	call   1b34 <phase_defused>
    134c:	48 8d 3d ea 1c 00 00 	lea    0x1cea(%rip),%rdi        # 303d <_IO_stdin_used+0x3d>
    1353:	e8 08 fd ff ff       	call   1060 <puts@plt>
    1358:	e8 a3 06 00 00       	call   1a00 <read_line>
    135d:	48 89 c7             	mov    %rax,%rdi
    1360:	e8 1d 01 00 00       	call   1482 <phase_3>
    1365:	e8 ca 07 00 00       	call   1b34 <phase_defused>
    136a:	48 8d 3d ea 1c 00 00 	lea    0x1cea(%rip),%rdi        # 305b <_IO_stdin_used+0x5b>
    1371:	e8 ea fc ff ff       	call   1060 <puts@plt>
    1376:	e8 85 06 00 00       	call   1a00 <read_line>
    137b:	48 89 c7             	mov    %rax,%rdi
    137e:	e8 02 02 00 00       	call   1585 <phase_4>
    1383:	e8 ac 07 00 00       	call   1b34 <phase_defused>
    1388:	48 8d 3d 99 1d 00 00 	lea    0x1d99(%rip),%rdi        # 3128 <_IO_stdin_used+0x128>
    138f:	e8 cc fc ff ff       	call   1060 <puts@plt>
    1394:	e8 67 06 00 00       	call   1a00 <read_line>
    1399:	48 89 c7             	mov    %rax,%rdi
    139c:	e8 3d 02 00 00       	call   15de <phase_5>
    13a1:	e8 8e 07 00 00       	call   1b34 <phase_defused>
    13a6:	48 8d 3d bd 1c 00 00 	lea    0x1cbd(%rip),%rdi        # 306a <_IO_stdin_used+0x6a>
    13ad:	e8 ae fc ff ff       	call   1060 <puts@plt>
    13b2:	e8 49 06 00 00       	call   1a00 <read_line>
    13b7:	48 89 c7             	mov    %rax,%rdi
    13ba:	e8 97 02 00 00       	call   1656 <phase_6>
    13bf:	e8 70 07 00 00       	call   1b34 <phase_defused>
    13c4:	b8 00 00 00 00       	mov    $0x0,%eax
    13c9:	5b                   	pop    %rbx
    13ca:	c3                   	ret
    13cb:	48 8b 05 7e 43 00 00 	mov    0x437e(%rip),%rax        # 5750 <stdin@GLIBC_2.2.5>
    13d2:	48 89 05 97 43 00 00 	mov    %rax,0x4397(%rip)        # 5770 <infile>
    13d9:	e9 21 ff ff ff       	jmp    12ff <main+0x36>
    13de:	48 8b 53 08          	mov    0x8(%rbx),%rdx
    13e2:	48 8b 33             	mov    (%rbx),%rsi
    13e5:	48 8d 3d 1a 1c 00 00 	lea    0x1c1a(%rip),%rdi        # 3006 <_IO_stdin_used+0x6>
    13ec:	e8 9f fc ff ff       	call   1090 <printf@plt>
    13f1:	bf 08 00 00 00       	mov    $0x8,%edi
    13f6:	e8 85 fd ff ff       	call   1180 <exit@plt>
    13fb:	48 8b 36             	mov    (%rsi),%rsi
    13fe:	48 8d 3d 1e 1c 00 00 	lea    0x1c1e(%rip),%rdi        # 3023 <_IO_stdin_used+0x23>
    1405:	b8 00 00 00 00       	mov    $0x0,%eax
    140a:	e8 81 fc ff ff       	call   1090 <printf@plt>
    140f:	bf 08 00 00 00       	mov    $0x8,%edi
    1414:	e8 67 fd ff ff       	call   1180 <exit@plt>

0000000000001419 <phase_1>:
    1419:	48 83 ec 08          	sub    $0x8,%rsp
    141d:	48 8d 35 2c 1d 00 00 	lea    0x1d2c(%rip),%rsi        # 3150 <_IO_stdin_used+0x150>
    1424:	e8 70 04 00 00       	call   1899 <strings_not_equal>
    1429:	85 c0                	test   %eax,%eax
    142b:	75 05                	jne    1432 <phase_1+0x19>
    142d:	48 83 c4 08          	add    $0x8,%rsp
    1431:	c3                   	ret
    1432:	e8 62 05 00 00       	call   1999 <explode_bomb>
    1437:	eb f4                	jmp    142d <phase_1+0x14>

0000000000001439 <phase_2>:
    1439:	55                   	push   %rbp
    143a:	53                   	push   %rbx
    143b:	48 83 ec 28          	sub    $0x28,%rsp
    143f:	48 89 e6             	mov    %rsp,%rsi
    1442:	e8 78 05 00 00       	call   19bf <read_six_numbers>
    1447:	83 3c 24 00          	cmpl   $0x0,(%rsp)
    144b:	78 0a                	js     1457 <phase_2+0x1e>
    144d:	48 89 e5             	mov    %rsp,%rbp
    1450:	bb 01 00 00 00       	mov    $0x1,%ebx
    1455:	eb 13                	jmp    146a <phase_2+0x31>
    1457:	e8 3d 05 00 00       	call   1999 <explode_bomb>
    145c:	eb ef                	jmp    144d <phase_2+0x14>
    145e:	83 c3 01             	add    $0x1,%ebx
    1461:	48 83 c5 04          	add    $0x4,%rbp
    1465:	83 fb 06             	cmp    $0x6,%ebx
    1468:	74 11                	je     147b <phase_2+0x42>
    146a:	89 d8                	mov    %ebx,%eax
    146c:	03 45 00             	add    0x0(%rbp),%eax
    146f:	39 45 04             	cmp    %eax,0x4(%rbp)
    1472:	74 ea                	je     145e <phase_2+0x25>
    1474:	e8 20 05 00 00       	call   1999 <explode_bomb>
    1479:	eb e3                	jmp    145e <phase_2+0x25>
    147b:	48 83 c4 28          	add    $0x28,%rsp
    147f:	5b                   	pop    %rbx
    1480:	5d                   	pop    %rbp
    1481:	c3                   	ret

0000000000001482 <phase_3>:
    1482:	48 83 ec 18          	sub    $0x18,%rsp
    1486:	48 8d 4c 24 08       	lea    0x8(%rsp),%rcx
    148b:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
    1490:	48 8d 35 98 1e 00 00 	lea    0x1e98(%rip),%rsi        # 332f <array.0+0x14f>
    1497:	b8 00 00 00 00       	mov    $0x0,%eax
    149c:	e8 9f fc ff ff       	call   1140 <__isoc99_sscanf@plt>
    14a1:	83 f8 01             	cmp    $0x1,%eax
    14a4:	7e 1f                	jle    14c5 <phase_3+0x43>
    14a6:	83 7c 24 0c 07       	cmpl   $0x7,0xc(%rsp)
    14ab:	0f 87 8b 00 00 00    	ja     153c <phase_3+0xba>
    14b1:	8b 44 24 0c          	mov    0xc(%rsp),%eax
    14b5:	48 8d 15 04 1d 00 00 	lea    0x1d04(%rip),%rdx        # 31c0 <_IO_stdin_used+0x1c0>
    14bc:	48 63 04 82          	movslq (%rdx,%rax,4),%rax
    14c0:	48 01 d0             	add    %rdx,%rax
    14c3:	ff e0                	jmp    *%rax
    14c5:	e8 cf 04 00 00       	call   1999 <explode_bomb>
    14ca:	eb da                	jmp    14a6 <phase_3+0x24>
    14cc:	b8 00 00 00 00       	mov    $0x0,%eax
    14d1:	2d 15 02 00 00       	sub    $0x215,%eax
    14d6:	05 59 02 00 00       	add    $0x259,%eax
    14db:	2d f6 02 00 00       	sub    $0x2f6,%eax
    14e0:	05 f6 02 00 00       	add    $0x2f6,%eax
    14e5:	2d f6 02 00 00       	sub    $0x2f6,%eax
    14ea:	05 f6 02 00 00       	add    $0x2f6,%eax
    14ef:	2d f6 02 00 00       	sub    $0x2f6,%eax
    14f4:	83 7c 24 0c 05       	cmpl   $0x5,0xc(%rsp)
    14f9:	7f 06                	jg     1501 <phase_3+0x7f>
    14fb:	39 44 24 08          	cmp    %eax,0x8(%rsp)
    14ff:	74 05                	je     1506 <phase_3+0x84>
    1501:	e8 93 04 00 00       	call   1999 <explode_bomb>
    1506:	48 83 c4 18          	add    $0x18,%rsp
    150a:	c3                   	ret
    150b:	b8 9f 02 00 00       	mov    $0x29f,%eax
    1510:	eb bf                	jmp    14d1 <phase_3+0x4f>
    1512:	b8 00 00 00 00       	mov    $0x0,%eax
    1517:	eb bd                	jmp    14d6 <phase_3+0x54>
    1519:	b8 00 00 00 00       	mov    $0x0,%eax
    151e:	eb bb                	jmp    14db <phase_3+0x59>
    1520:	b8 00 00 00 00       	mov    $0x0,%eax
    1525:	eb b9                	jmp    14e0 <phase_3+0x5e>
    1527:	b8 00 00 00 00       	mov    $0x0,%eax
    152c:	eb b7                	jmp    14e5 <phase_3+0x63>
    152e:	b8 00 00 00 00       	mov    $0x0,%eax
    1533:	eb b5                	jmp    14ea <phase_3+0x68>
    1535:	b8 00 00 00 00       	mov    $0x0,%eax
    153a:	eb b3                	jmp    14ef <phase_3+0x6d>
    153c:	e8 58 04 00 00       	call   1999 <explode_bomb>
    1541:	b8 00 00 00 00       	mov    $0x0,%eax
    1546:	eb ac                	jmp    14f4 <phase_3+0x72>

0000000000001548 <func4>:
    1548:	48 83 ec 08          	sub    $0x8,%rsp
    154c:	89 d0                	mov    %edx,%eax
    154e:	29 f0                	sub    %esi,%eax
    1550:	89 c1                	mov    %eax,%ecx
    1552:	c1 e9 1f             	shr    $0x1f,%ecx
    1555:	01 c1                	add    %eax,%ecx
    1557:	d1 f9                	sar    %ecx
    1559:	01 f1                	add    %esi,%ecx
    155b:	39 f9                	cmp    %edi,%ecx
    155d:	7f 0c                	jg     156b <func4+0x23>
    155f:	b8 00 00 00 00       	mov    $0x0,%eax
    1564:	7c 11                	jl     1577 <func4+0x2f>
    1566:	48 83 c4 08          	add    $0x8,%rsp
    156a:	c3                   	ret
    156b:	8d 51 ff             	lea    -0x1(%rcx),%edx
    156e:	e8 d5 ff ff ff       	call   1548 <func4>
    1573:	01 c0                	add    %eax,%eax
    1575:	eb ef                	jmp    1566 <func4+0x1e>
    1577:	8d 71 01             	lea    0x1(%rcx),%esi
    157a:	e8 c9 ff ff ff       	call   1548 <func4>
    157f:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
    1583:	eb e1                	jmp    1566 <func4+0x1e>

0000000000001585 <phase_4>:
    1585:	48 83 ec 18          	sub    $0x18,%rsp
    1589:	48 8d 4c 24 08       	lea    0x8(%rsp),%rcx
    158e:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
    1593:	48 8d 35 95 1d 00 00 	lea    0x1d95(%rip),%rsi        # 332f <array.0+0x14f>
    159a:	b8 00 00 00 00       	mov    $0x0,%eax
    159f:	e8 9c fb ff ff       	call   1140 <__isoc99_sscanf@plt>
    15a4:	83 f8 02             	cmp    $0x2,%eax
    15a7:	75 07                	jne    15b0 <phase_4+0x2b>
    15a9:	83 7c 24 0c 0e       	cmpl   $0xe,0xc(%rsp)
    15ae:	76 05                	jbe    15b5 <phase_4+0x30>
    15b0:	e8 e4 03 00 00       	call   1999 <explode_bomb>
    15b5:	ba 0e 00 00 00       	mov    $0xe,%edx
    15ba:	be 00 00 00 00       	mov    $0x0,%esi
    15bf:	8b 7c 24 0c          	mov    0xc(%rsp),%edi
    15c3:	e8 80 ff ff ff       	call   1548 <func4>
    15c8:	83 f8 02             	cmp    $0x2,%eax
    15cb:	75 07                	jne    15d4 <phase_4+0x4f>
    15cd:	83 7c 24 08 02       	cmpl   $0x2,0x8(%rsp)
    15d2:	74 05                	je     15d9 <phase_4+0x54>
    15d4:	e8 c0 03 00 00       	call   1999 <explode_bomb>
    15d9:	48 83 c4 18          	add    $0x18,%rsp
    15dd:	c3                   	ret

00000000000015de <phase_5>:
    15de:	48 83 ec 18          	sub    $0x18,%rsp
    15e2:	48 8d 4c 24 08       	lea    0x8(%rsp),%rcx
    15e7:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
    15ec:	48 8d 35 3c 1d 00 00 	lea    0x1d3c(%rip),%rsi        # 332f <array.0+0x14f>
    15f3:	b8 00 00 00 00       	mov    $0x0,%eax
    15f8:	e8 43 fb ff ff       	call   1140 <__isoc99_sscanf@plt>
    15fd:	83 f8 01             	cmp    $0x1,%eax
    1600:	7e 4d                	jle    164f <phase_5+0x71>
    1602:	8b 44 24 0c          	mov    0xc(%rsp),%eax
    1606:	83 e0 0f             	and    $0xf,%eax
    1609:	89 44 24 0c          	mov    %eax,0xc(%rsp)
    160d:	83 f8 0f             	cmp    $0xf,%eax
    1610:	74 33                	je     1645 <phase_5+0x67>
    1612:	b9 00 00 00 00       	mov    $0x0,%ecx
    1617:	ba 00 00 00 00       	mov    $0x0,%edx
    161c:	48 8d 35 bd 1b 00 00 	lea    0x1bbd(%rip),%rsi        # 31e0 <array.0>
    1623:	83 c2 01             	add    $0x1,%edx
    1626:	48 98                	cltq
    1628:	8b 04 86             	mov    (%rsi,%rax,4),%eax
    162b:	01 c1                	add    %eax,%ecx
    162d:	83 f8 0f             	cmp    $0xf,%eax
    1630:	75 f1                	jne    1623 <phase_5+0x45>
    1632:	c7 44 24 0c 0f 00 00 	movl   $0xf,0xc(%rsp)
    1639:	00 
    163a:	83 fa 0f             	cmp    $0xf,%edx
    163d:	75 06                	jne    1645 <phase_5+0x67>
    163f:	39 4c 24 08          	cmp    %ecx,0x8(%rsp)
    1643:	74 05                	je     164a <phase_5+0x6c>
    1645:	e8 4f 03 00 00       	call   1999 <explode_bomb>
    164a:	48 83 c4 18          	add    $0x18,%rsp
    164e:	c3                   	ret
    164f:	e8 45 03 00 00       	call   1999 <explode_bomb>
    1654:	eb ac                	jmp    1602 <phase_5+0x24>

0000000000001656 <phase_6>:
    1656:	41 56                	push   %r14
    1658:	41 55                	push   %r13
    165a:	41 54                	push   %r12
    165c:	55                   	push   %rbp
    165d:	53                   	push   %rbx
    165e:	48 83 ec 50          	sub    $0x50,%rsp
    1662:	4c 8d 74 24 30       	lea    0x30(%rsp),%r14
    1667:	4c 89 f6             	mov    %r14,%rsi
    166a:	e8 50 03 00 00       	call   19bf <read_six_numbers>
    166f:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1675:	4d 89 f4             	mov    %r14,%r12
    1678:	e9 ad 00 00 00       	jmp    172a <phase_6+0xd4>
    167d:	e8 17 03 00 00       	call   1999 <explode_bomb>
    1682:	41 83 fd 05          	cmp    $0x5,%r13d
    1686:	0f 8e b6 00 00 00    	jle    1742 <phase_6+0xec>
    168c:	be 00 00 00 00       	mov    $0x0,%esi
    1691:	8b 4c b4 30          	mov    0x30(%rsp,%rsi,4),%ecx
    1695:	b8 01 00 00 00       	mov    $0x1,%eax
    169a:	48 8d 15 4f 3c 00 00 	lea    0x3c4f(%rip),%rdx        # 52f0 <node1>
    16a1:	83 f9 01             	cmp    $0x1,%ecx
    16a4:	7e 0b                	jle    16b1 <phase_6+0x5b>
    16a6:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    16aa:	83 c0 01             	add    $0x1,%eax
    16ad:	39 c8                	cmp    %ecx,%eax
    16af:	75 f5                	jne    16a6 <phase_6+0x50>
    16b1:	48 89 14 f4          	mov    %rdx,(%rsp,%rsi,8)
    16b5:	48 83 c6 01          	add    $0x1,%rsi
    16b9:	48 83 fe 06          	cmp    $0x6,%rsi
    16bd:	75 d2                	jne    1691 <phase_6+0x3b>
    16bf:	48 8b 1c 24          	mov    (%rsp),%rbx
    16c3:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
    16c8:	48 89 43 08          	mov    %rax,0x8(%rbx)
    16cc:	48 8b 54 24 10       	mov    0x10(%rsp),%rdx
    16d1:	48 89 50 08          	mov    %rdx,0x8(%rax)
    16d5:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    16da:	48 89 42 08          	mov    %rax,0x8(%rdx)
    16de:	48 8b 54 24 20       	mov    0x20(%rsp),%rdx
    16e3:	48 89 50 08          	mov    %rdx,0x8(%rax)
    16e7:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    16ec:	48 89 42 08          	mov    %rax,0x8(%rdx)
    16f0:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    16f7:	00 
    16f8:	bd 05 00 00 00       	mov    $0x5,%ebp
    16fd:	eb 51                	jmp    1750 <phase_6+0xfa>
    16ff:	48 83 c3 01          	add    $0x1,%rbx
    1703:	83 fb 05             	cmp    $0x5,%ebx
    1706:	7f 10                	jg     1718 <phase_6+0xc2>
    1708:	41 8b 04 9c          	mov    (%r12,%rbx,4),%eax
    170c:	39 45 00             	cmp    %eax,0x0(%rbp)
    170f:	75 ee                	jne    16ff <phase_6+0xa9>
    1711:	e8 83 02 00 00       	call   1999 <explode_bomb>
    1716:	eb e7                	jmp    16ff <phase_6+0xa9>
    1718:	49 83 c6 04          	add    $0x4,%r14
    171c:	49 83 c5 01          	add    $0x1,%r13
    1720:	49 83 fd 07          	cmp    $0x7,%r13
    1724:	0f 84 62 ff ff ff    	je     168c <phase_6+0x36>
    172a:	4c 89 f5             	mov    %r14,%rbp
    172d:	41 8b 06             	mov    (%r14),%eax
    1730:	83 e8 01             	sub    $0x1,%eax
    1733:	83 f8 05             	cmp    $0x5,%eax
    1736:	0f 87 41 ff ff ff    	ja     167d <phase_6+0x27>
    173c:	41 83 fd 05          	cmp    $0x5,%r13d
    1740:	7f d6                	jg     1718 <phase_6+0xc2>
    1742:	4c 89 eb             	mov    %r13,%rbx
    1745:	eb c1                	jmp    1708 <phase_6+0xb2>
    1747:	48 8b 5b 08          	mov    0x8(%rbx),%rbx
    174b:	83 ed 01             	sub    $0x1,%ebp
    174e:	74 11                	je     1761 <phase_6+0x10b>
    1750:	48 8b 43 08          	mov    0x8(%rbx),%rax
    1754:	8b 00                	mov    (%rax),%eax
    1756:	39 03                	cmp    %eax,(%rbx)
    1758:	7e ed                	jle    1747 <phase_6+0xf1>
    175a:	e8 3a 02 00 00       	call   1999 <explode_bomb>
    175f:	eb e6                	jmp    1747 <phase_6+0xf1>
    1761:	48 83 c4 50          	add    $0x50,%rsp
    1765:	5b                   	pop    %rbx
    1766:	5d                   	pop    %rbp
    1767:	41 5c                	pop    %r12
    1769:	41 5d                	pop    %r13
    176b:	41 5e                	pop    %r14
    176d:	c3                   	ret

000000000000176e <fun7>:
    176e:	48 85 ff             	test   %rdi,%rdi
    1771:	74 32                	je     17a5 <fun7+0x37>
    1773:	48 83 ec 08          	sub    $0x8,%rsp
    1777:	8b 17                	mov    (%rdi),%edx
    1779:	39 f2                	cmp    %esi,%edx
    177b:	7f 0c                	jg     1789 <fun7+0x1b>
    177d:	b8 00 00 00 00       	mov    $0x0,%eax
    1782:	75 12                	jne    1796 <fun7+0x28>
    1784:	48 83 c4 08          	add    $0x8,%rsp
    1788:	c3                   	ret
    1789:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
    178d:	e8 dc ff ff ff       	call   176e <fun7>
    1792:	01 c0                	add    %eax,%eax
    1794:	eb ee                	jmp    1784 <fun7+0x16>
    1796:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    179a:	e8 cf ff ff ff       	call   176e <fun7>
    179f:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
    17a3:	eb df                	jmp    1784 <fun7+0x16>
    17a5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    17aa:	c3                   	ret

00000000000017ab <secret_phase>:
    17ab:	53                   	push   %rbx
    17ac:	e8 4f 02 00 00       	call   1a00 <read_line>
    17b1:	48 89 c7             	mov    %rax,%rdi
    17b4:	ba 0a 00 00 00       	mov    $0xa,%edx
    17b9:	be 00 00 00 00       	mov    $0x0,%esi
    17be:	e8 5d f9 ff ff       	call   1120 <strtol@plt>
    17c3:	89 c3                	mov    %eax,%ebx
    17c5:	83 e8 01             	sub    $0x1,%eax
    17c8:	3d e8 03 00 00       	cmp    $0x3e8,%eax
    17cd:	77 26                	ja     17f5 <secret_phase+0x4a>
    17cf:	89 de                	mov    %ebx,%esi
    17d1:	48 8d 3d 38 3a 00 00 	lea    0x3a38(%rip),%rdi        # 5210 <n1>
    17d8:	e8 91 ff ff ff       	call   176e <fun7>
    17dd:	83 f8 05             	cmp    $0x5,%eax
    17e0:	75 1a                	jne    17fc <secret_phase+0x51>
    17e2:	48 8d 3d 97 19 00 00 	lea    0x1997(%rip),%rdi        # 3180 <_IO_stdin_used+0x180>
    17e9:	e8 72 f8 ff ff       	call   1060 <puts@plt>
    17ee:	e8 41 03 00 00       	call   1b34 <phase_defused>
    17f3:	5b                   	pop    %rbx
    17f4:	c3                   	ret
    17f5:	e8 9f 01 00 00       	call   1999 <explode_bomb>
    17fa:	eb d3                	jmp    17cf <secret_phase+0x24>
    17fc:	e8 98 01 00 00       	call   1999 <explode_bomb>
    1801:	eb df                	jmp    17e2 <secret_phase+0x37>

0000000000001803 <sig_handler>:
    1803:	48 83 ec 08          	sub    $0x8,%rsp
    1807:	48 8d 3d 12 1a 00 00 	lea    0x1a12(%rip),%rdi        # 3220 <array.0+0x40>
    180e:	e8 4d f8 ff ff       	call   1060 <puts@plt>
    1813:	bf 03 00 00 00       	mov    $0x3,%edi
    1818:	e8 83 f9 ff ff       	call   11a0 <sleep@plt>
    181d:	48 8d 3d be 1a 00 00 	lea    0x1abe(%rip),%rdi        # 32e2 <array.0+0x102>
    1824:	b8 00 00 00 00       	mov    $0x0,%eax
    1829:	e8 62 f8 ff ff       	call   1090 <printf@plt>
    182e:	48 8b 3d 0b 3f 00 00 	mov    0x3f0b(%rip),%rdi        # 5740 <stdout@GLIBC_2.2.5>
    1835:	e8 f6 f8 ff ff       	call   1130 <fflush@plt>
    183a:	bf 01 00 00 00       	mov    $0x1,%edi
    183f:	e8 5c f9 ff ff       	call   11a0 <sleep@plt>
    1844:	48 8d 3d 9f 1a 00 00 	lea    0x1a9f(%rip),%rdi        # 32ea <array.0+0x10a>
    184b:	e8 10 f8 ff ff       	call   1060 <puts@plt>
    1850:	bf 10 00 00 00       	mov    $0x10,%edi
    1855:	e8 26 f9 ff ff       	call   1180 <exit@plt>

000000000000185a <invalid_phase>:
    185a:	48 83 ec 08          	sub    $0x8,%rsp
    185e:	48 89 fe             	mov    %rdi,%rsi
    1861:	48 8d 3d 8a 1a 00 00 	lea    0x1a8a(%rip),%rdi        # 32f2 <array.0+0x112>
    1868:	b8 00 00 00 00       	mov    $0x0,%eax
    186d:	e8 1e f8 ff ff       	call   1090 <printf@plt>
    1872:	bf 08 00 00 00       	mov    $0x8,%edi
    1877:	e8 04 f9 ff ff       	call   1180 <exit@plt>

000000000000187c <string_length>:
    187c:	80 3f 00             	cmpb   $0x0,(%rdi)
    187f:	74 12                	je     1893 <string_length+0x17>
    1881:	b8 00 00 00 00       	mov    $0x0,%eax
    1886:	48 83 c7 01          	add    $0x1,%rdi
    188a:	83 c0 01             	add    $0x1,%eax
    188d:	80 3f 00             	cmpb   $0x0,(%rdi)
    1890:	75 f4                	jne    1886 <string_length+0xa>
    1892:	c3                   	ret
    1893:	b8 00 00 00 00       	mov    $0x0,%eax
    1898:	c3                   	ret

0000000000001899 <strings_not_equal>:
    1899:	41 54                	push   %r12
    189b:	55                   	push   %rbp
    189c:	53                   	push   %rbx
    189d:	48 89 fb             	mov    %rdi,%rbx
    18a0:	48 89 f5             	mov    %rsi,%rbp
    18a3:	e8 d4 ff ff ff       	call   187c <string_length>
    18a8:	41 89 c4             	mov    %eax,%r12d
    18ab:	48 89 ef             	mov    %rbp,%rdi
    18ae:	e8 c9 ff ff ff       	call   187c <string_length>
    18b3:	89 c2                	mov    %eax,%edx
    18b5:	b8 01 00 00 00       	mov    $0x1,%eax
    18ba:	41 39 d4             	cmp    %edx,%r12d
    18bd:	75 31                	jne    18f0 <strings_not_equal+0x57>
    18bf:	0f b6 13             	movzbl (%rbx),%edx
    18c2:	84 d2                	test   %dl,%dl
    18c4:	74 1e                	je     18e4 <strings_not_equal+0x4b>
    18c6:	b8 00 00 00 00       	mov    $0x0,%eax
    18cb:	38 54 05 00          	cmp    %dl,0x0(%rbp,%rax,1)
    18cf:	75 1a                	jne    18eb <strings_not_equal+0x52>
    18d1:	48 83 c0 01          	add    $0x1,%rax
    18d5:	0f b6 14 03          	movzbl (%rbx,%rax,1),%edx
    18d9:	84 d2                	test   %dl,%dl
    18db:	75 ee                	jne    18cb <strings_not_equal+0x32>
    18dd:	b8 00 00 00 00       	mov    $0x0,%eax
    18e2:	eb 0c                	jmp    18f0 <strings_not_equal+0x57>
    18e4:	b8 00 00 00 00       	mov    $0x0,%eax
    18e9:	eb 05                	jmp    18f0 <strings_not_equal+0x57>
    18eb:	b8 01 00 00 00       	mov    $0x1,%eax
    18f0:	5b                   	pop    %rbx
    18f1:	5d                   	pop    %rbp
    18f2:	41 5c                	pop    %r12
    18f4:	c3                   	ret

00000000000018f5 <initialize_bomb>:
    18f5:	48 83 ec 08          	sub    $0x8,%rsp
    18f9:	48 8d 35 03 ff ff ff 	lea    -0xfd(%rip),%rsi        # 1803 <sig_handler>
    1900:	bf 02 00 00 00       	mov    $0x2,%edi
    1905:	e8 e6 f7 ff ff       	call   10f0 <signal@plt>
    190a:	48 83 c4 08          	add    $0x8,%rsp
    190e:	c3                   	ret

000000000000190f <initialize_bomb_solve>:
    190f:	c3                   	ret

0000000000001910 <blank_line>:
    1910:	55                   	push   %rbp
    1911:	53                   	push   %rbx
    1912:	48 83 ec 08          	sub    $0x8,%rsp
    1916:	48 89 fd             	mov    %rdi,%rbp
    1919:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
    191d:	84 db                	test   %bl,%bl
    191f:	74 1e                	je     193f <blank_line+0x2f>
    1921:	e8 8a f8 ff ff       	call   11b0 <__ctype_b_loc@plt>
    1926:	48 83 c5 01          	add    $0x1,%rbp
    192a:	48 0f be db          	movsbq %bl,%rbx
    192e:	48 8b 00             	mov    (%rax),%rax
    1931:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
    1936:	75 e1                	jne    1919 <blank_line+0x9>
    1938:	b8 00 00 00 00       	mov    $0x0,%eax
    193d:	eb 05                	jmp    1944 <blank_line+0x34>
    193f:	b8 01 00 00 00       	mov    $0x1,%eax
    1944:	48 83 c4 08          	add    $0x8,%rsp
    1948:	5b                   	pop    %rbx
    1949:	5d                   	pop    %rbp
    194a:	c3                   	ret

000000000000194b <skip>:
    194b:	55                   	push   %rbp
    194c:	53                   	push   %rbx
    194d:	48 83 ec 08          	sub    $0x8,%rsp
    1951:	48 8d 2d 88 3e 00 00 	lea    0x3e88(%rip),%rbp        # 57e0 <input_strings>
    1958:	48 63 05 71 3e 00 00 	movslq 0x3e71(%rip),%rax        # 57d0 <num_input_strings>
    195f:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
    1963:	48 c1 e7 04          	shl    $0x4,%rdi
    1967:	48 01 ef             	add    %rbp,%rdi
    196a:	48 8b 15 ff 3d 00 00 	mov    0x3dff(%rip),%rdx        # 5770 <infile>
    1971:	be 50 00 00 00       	mov    $0x50,%esi
    1976:	e8 55 f7 ff ff       	call   10d0 <fgets@plt>
    197b:	48 89 c3             	mov    %rax,%rbx
    197e:	48 85 c0             	test   %rax,%rax
    1981:	74 0c                	je     198f <skip+0x44>
    1983:	48 89 c7             	mov    %rax,%rdi
    1986:	e8 85 ff ff ff       	call   1910 <blank_line>
    198b:	85 c0                	test   %eax,%eax
    198d:	75 c9                	jne    1958 <skip+0xd>
    198f:	48 89 d8             	mov    %rbx,%rax
    1992:	48 83 c4 08          	add    $0x8,%rsp
    1996:	5b                   	pop    %rbx
    1997:	5d                   	pop    %rbp
    1998:	c3                   	ret

0000000000001999 <explode_bomb>:
    1999:	48 83 ec 08          	sub    $0x8,%rsp
    199d:	48 8d 3d 5f 19 00 00 	lea    0x195f(%rip),%rdi        # 3303 <array.0+0x123>
    19a4:	e8 b7 f6 ff ff       	call   1060 <puts@plt>
    19a9:	48 8d 3d 5c 19 00 00 	lea    0x195c(%rip),%rdi        # 330c <array.0+0x12c>
    19b0:	e8 ab f6 ff ff       	call   1060 <puts@plt>
    19b5:	bf 08 00 00 00       	mov    $0x8,%edi
    19ba:	e8 c1 f7 ff ff       	call   1180 <exit@plt>

00000000000019bf <read_six_numbers>:
    19bf:	48 83 ec 08          	sub    $0x8,%rsp
    19c3:	48 89 f2             	mov    %rsi,%rdx
    19c6:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
    19ca:	48 8d 46 14          	lea    0x14(%rsi),%rax
    19ce:	50                   	push   %rax
    19cf:	48 8d 46 10          	lea    0x10(%rsi),%rax
    19d3:	50                   	push   %rax
    19d4:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
    19d8:	4c 8d 46 08          	lea    0x8(%rsi),%r8
    19dc:	48 8d 35 40 19 00 00 	lea    0x1940(%rip),%rsi        # 3323 <array.0+0x143>
    19e3:	b8 00 00 00 00       	mov    $0x0,%eax
    19e8:	e8 53 f7 ff ff       	call   1140 <__isoc99_sscanf@plt>
    19ed:	48 83 c4 10          	add    $0x10,%rsp
    19f1:	83 f8 05             	cmp    $0x5,%eax
    19f4:	7e 05                	jle    19fb <read_six_numbers+0x3c>
    19f6:	48 83 c4 08          	add    $0x8,%rsp
    19fa:	c3                   	ret
    19fb:	e8 99 ff ff ff       	call   1999 <explode_bomb>

0000000000001a00 <read_line>:
    1a00:	55                   	push   %rbp
    1a01:	53                   	push   %rbx
    1a02:	48 83 ec 08          	sub    $0x8,%rsp
    1a06:	b8 00 00 00 00       	mov    $0x0,%eax
    1a0b:	e8 3b ff ff ff       	call   194b <skip>
    1a10:	48 85 c0             	test   %rax,%rax
    1a13:	74 5d                	je     1a72 <read_line+0x72>
    1a15:	8b 2d b5 3d 00 00    	mov    0x3db5(%rip),%ebp        # 57d0 <num_input_strings>
    1a1b:	48 63 c5             	movslq %ebp,%rax
    1a1e:	48 8d 1c 80          	lea    (%rax,%rax,4),%rbx
    1a22:	48 c1 e3 04          	shl    $0x4,%rbx
    1a26:	48 8d 05 b3 3d 00 00 	lea    0x3db3(%rip),%rax        # 57e0 <input_strings>
    1a2d:	48 01 c3             	add    %rax,%rbx
    1a30:	48 89 df             	mov    %rbx,%rdi
    1a33:	e8 48 f6 ff ff       	call   1080 <strlen@plt>
    1a38:	83 f8 4e             	cmp    $0x4e,%eax
    1a3b:	0f 8f a9 00 00 00    	jg     1aea <read_line+0xea>
    1a41:	83 e8 01             	sub    $0x1,%eax
    1a44:	48 98                	cltq
    1a46:	48 63 d5             	movslq %ebp,%rdx
    1a49:	48 8d 0c 92          	lea    (%rdx,%rdx,4),%rcx
    1a4d:	48 c1 e1 04          	shl    $0x4,%rcx
    1a51:	48 8d 15 88 3d 00 00 	lea    0x3d88(%rip),%rdx        # 57e0 <input_strings>
    1a58:	48 01 ca             	add    %rcx,%rdx
    1a5b:	c6 04 02 00          	movb   $0x0,(%rdx,%rax,1)
    1a5f:	83 c5 01             	add    $0x1,%ebp
    1a62:	89 2d 68 3d 00 00    	mov    %ebp,0x3d68(%rip)        # 57d0 <num_input_strings>
    1a68:	48 89 d8             	mov    %rbx,%rax
    1a6b:	48 83 c4 08          	add    $0x8,%rsp
    1a6f:	5b                   	pop    %rbx
    1a70:	5d                   	pop    %rbp
    1a71:	c3                   	ret
    1a72:	48 8b 05 d7 3c 00 00 	mov    0x3cd7(%rip),%rax        # 5750 <stdin@GLIBC_2.2.5>
    1a79:	48 39 05 f0 3c 00 00 	cmp    %rax,0x3cf0(%rip)        # 5770 <infile>
    1a80:	74 1b                	je     1a9d <read_line+0x9d>
    1a82:	48 8d 3d ca 18 00 00 	lea    0x18ca(%rip),%rdi        # 3353 <array.0+0x173>
    1a89:	e8 a2 f5 ff ff       	call   1030 <getenv@plt>
    1a8e:	48 85 c0             	test   %rax,%rax
    1a91:	74 20                	je     1ab3 <read_line+0xb3>
    1a93:	bf 00 00 00 00       	mov    $0x0,%edi
    1a98:	e8 e3 f6 ff ff       	call   1180 <exit@plt>
    1a9d:	48 8d 3d 91 18 00 00 	lea    0x1891(%rip),%rdi        # 3335 <array.0+0x155>
    1aa4:	e8 b7 f5 ff ff       	call   1060 <puts@plt>
    1aa9:	bf 08 00 00 00       	mov    $0x8,%edi
    1aae:	e8 cd f6 ff ff       	call   1180 <exit@plt>
    1ab3:	48 8b 05 96 3c 00 00 	mov    0x3c96(%rip),%rax        # 5750 <stdin@GLIBC_2.2.5>
    1aba:	48 89 05 af 3c 00 00 	mov    %rax,0x3caf(%rip)        # 5770 <infile>
    1ac1:	b8 00 00 00 00       	mov    $0x0,%eax
    1ac6:	e8 80 fe ff ff       	call   194b <skip>
    1acb:	48 85 c0             	test   %rax,%rax
    1ace:	0f 85 41 ff ff ff    	jne    1a15 <read_line+0x15>
    1ad4:	48 8d 3d 5a 18 00 00 	lea    0x185a(%rip),%rdi        # 3335 <array.0+0x155>
    1adb:	e8 80 f5 ff ff       	call   1060 <puts@plt>
    1ae0:	bf 00 00 00 00       	mov    $0x0,%edi
    1ae5:	e8 96 f6 ff ff       	call   1180 <exit@plt>
    1aea:	48 8d 3d 6d 18 00 00 	lea    0x186d(%rip),%rdi        # 335e <array.0+0x17e>
    1af1:	e8 6a f5 ff ff       	call   1060 <puts@plt>
    1af6:	8b 05 d4 3c 00 00    	mov    0x3cd4(%rip),%eax        # 57d0 <num_input_strings>
    1afc:	8d 50 01             	lea    0x1(%rax),%edx
    1aff:	89 15 cb 3c 00 00    	mov    %edx,0x3ccb(%rip)        # 57d0 <num_input_strings>
    1b05:	48 98                	cltq
    1b07:	48 6b c0 50          	imul   $0x50,%rax,%rax
    1b0b:	48 8d 15 ce 3c 00 00 	lea    0x3cce(%rip),%rdx        # 57e0 <input_strings>
    1b12:	48 be 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rsi
    1b19:	75 6e 63 
    1b1c:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
    1b23:	2a 2a 00 
    1b26:	48 89 34 02          	mov    %rsi,(%rdx,%rax,1)
    1b2a:	48 89 7c 02 08       	mov    %rdi,0x8(%rdx,%rax,1)
    1b2f:	e8 65 fe ff ff       	call   1999 <explode_bomb>

0000000000001b34 <phase_defused>:
    1b34:	83 3d 95 3c 00 00 06 	cmpl   $0x6,0x3c95(%rip)        # 57d0 <num_input_strings>
    1b3b:	74 01                	je     1b3e <phase_defused+0xa>
    1b3d:	c3                   	ret
    1b3e:	48 83 ec 68          	sub    $0x68,%rsp
    1b42:	48 8d 4c 24 08       	lea    0x8(%rsp),%rcx
    1b47:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
    1b4c:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
    1b51:	48 8d 35 21 18 00 00 	lea    0x1821(%rip),%rsi        # 3379 <array.0+0x199>
    1b58:	48 8d 3d 71 3d 00 00 	lea    0x3d71(%rip),%rdi        # 58d0 <input_strings+0xf0>
    1b5f:	b8 00 00 00 00       	mov    $0x0,%eax
    1b64:	e8 d7 f5 ff ff       	call   1140 <__isoc99_sscanf@plt>
    1b69:	83 f8 03             	cmp    $0x3,%eax
    1b6c:	74 11                	je     1b7f <phase_defused+0x4b>
    1b6e:	48 8d 3d 43 17 00 00 	lea    0x1743(%rip),%rdi        # 32b8 <array.0+0xd8>
    1b75:	e8 e6 f4 ff ff       	call   1060 <puts@plt>
    1b7a:	48 83 c4 68          	add    $0x68,%rsp
    1b7e:	c3                   	ret
    1b7f:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
    1b84:	48 8d 35 f7 17 00 00 	lea    0x17f7(%rip),%rsi        # 3382 <array.0+0x1a2>
    1b8b:	e8 09 fd ff ff       	call   1899 <strings_not_equal>
    1b90:	85 c0                	test   %eax,%eax
    1b92:	75 da                	jne    1b6e <phase_defused+0x3a>
    1b94:	48 8d 3d bd 16 00 00 	lea    0x16bd(%rip),%rdi        # 3258 <array.0+0x78>
    1b9b:	e8 c0 f4 ff ff       	call   1060 <puts@plt>
    1ba0:	48 8d 3d d9 16 00 00 	lea    0x16d9(%rip),%rdi        # 3280 <array.0+0xa0>
    1ba7:	e8 b4 f4 ff ff       	call   1060 <puts@plt>
    1bac:	b8 00 00 00 00       	mov    $0x0,%eax
    1bb1:	e8 f5 fb ff ff       	call   17ab <secret_phase>
    1bb6:	eb b6                	jmp    1b6e <phase_defused+0x3a>

0000000000001bb8 <sigalrm_handler>:
    1bb8:	48 83 ec 08          	sub    $0x8,%rsp
    1bbc:	ba 00 00 00 00       	mov    $0x0,%edx
    1bc1:	48 8d 35 28 18 00 00 	lea    0x1828(%rip),%rsi        # 33f0 <array.0+0x210>
    1bc8:	48 8b 3d 91 3b 00 00 	mov    0x3b91(%rip),%rdi        # 5760 <stderr@GLIBC_2.2.5>
    1bcf:	b8 00 00 00 00       	mov    $0x0,%eax
    1bd4:	e8 37 f5 ff ff       	call   1110 <fprintf@plt>
    1bd9:	bf 01 00 00 00       	mov    $0x1,%edi
    1bde:	e8 9d f5 ff ff       	call   1180 <exit@plt>

0000000000001be3 <rio_readlineb>:
    1be3:	41 56                	push   %r14
    1be5:	41 55                	push   %r13
    1be7:	41 54                	push   %r12
    1be9:	55                   	push   %rbp
    1bea:	53                   	push   %rbx
    1beb:	49 89 f4             	mov    %rsi,%r12
    1bee:	48 83 fa 01          	cmp    $0x1,%rdx
    1bf2:	0f 86 90 00 00 00    	jbe    1c88 <rio_readlineb+0xa5>
    1bf8:	48 89 fb             	mov    %rdi,%rbx
    1bfb:	4c 8d 74 16 ff       	lea    -0x1(%rsi,%rdx,1),%r14
    1c00:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1c06:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
    1c0a:	eb 54                	jmp    1c60 <rio_readlineb+0x7d>
    1c0c:	e8 2f f4 ff ff       	call   1040 <__errno_location@plt>
    1c11:	83 38 04             	cmpl   $0x4,(%rax)
    1c14:	75 53                	jne    1c69 <rio_readlineb+0x86>
    1c16:	8b 3b                	mov    (%rbx),%edi
    1c18:	ba 00 20 00 00       	mov    $0x2000,%edx
    1c1d:	48 89 ee             	mov    %rbp,%rsi
    1c20:	e8 9b f4 ff ff       	call   10c0 <read@plt>
    1c25:	89 c2                	mov    %eax,%edx
    1c27:	89 43 04             	mov    %eax,0x4(%rbx)
    1c2a:	85 c0                	test   %eax,%eax
    1c2c:	78 de                	js     1c0c <rio_readlineb+0x29>
    1c2e:	74 42                	je     1c72 <rio_readlineb+0x8f>
    1c30:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
    1c34:	48 8b 43 08          	mov    0x8(%rbx),%rax
    1c38:	0f b6 08             	movzbl (%rax),%ecx
    1c3b:	48 83 c0 01          	add    $0x1,%rax
    1c3f:	48 89 43 08          	mov    %rax,0x8(%rbx)
    1c43:	83 ea 01             	sub    $0x1,%edx
    1c46:	89 53 04             	mov    %edx,0x4(%rbx)
    1c49:	49 83 c4 01          	add    $0x1,%r12
    1c4d:	41 88 4c 24 ff       	mov    %cl,-0x1(%r12)
    1c52:	80 f9 0a             	cmp    $0xa,%cl
    1c55:	74 3c                	je     1c93 <rio_readlineb+0xb0>
    1c57:	41 83 c5 01          	add    $0x1,%r13d
    1c5b:	4d 39 f4             	cmp    %r14,%r12
    1c5e:	74 30                	je     1c90 <rio_readlineb+0xad>
    1c60:	8b 53 04             	mov    0x4(%rbx),%edx
    1c63:	85 d2                	test   %edx,%edx
    1c65:	7e af                	jle    1c16 <rio_readlineb+0x33>
    1c67:	eb cb                	jmp    1c34 <rio_readlineb+0x51>
    1c69:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    1c70:	eb 05                	jmp    1c77 <rio_readlineb+0x94>
    1c72:	b8 00 00 00 00       	mov    $0x0,%eax
    1c77:	85 c0                	test   %eax,%eax
    1c79:	75 29                	jne    1ca4 <rio_readlineb+0xc1>
    1c7b:	b8 00 00 00 00       	mov    $0x0,%eax
    1c80:	41 83 fd 01          	cmp    $0x1,%r13d
    1c84:	75 0d                	jne    1c93 <rio_readlineb+0xb0>
    1c86:	eb 13                	jmp    1c9b <rio_readlineb+0xb8>
    1c88:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1c8e:	eb 03                	jmp    1c93 <rio_readlineb+0xb0>
    1c90:	4d 89 f4             	mov    %r14,%r12
    1c93:	41 c6 04 24 00       	movb   $0x0,(%r12)
    1c98:	49 63 c5             	movslq %r13d,%rax
    1c9b:	5b                   	pop    %rbx
    1c9c:	5d                   	pop    %rbp
    1c9d:	41 5c                	pop    %r12
    1c9f:	41 5d                	pop    %r13
    1ca1:	41 5e                	pop    %r14
    1ca3:	c3                   	ret
    1ca4:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
    1cab:	eb ee                	jmp    1c9b <rio_readlineb+0xb8>

0000000000001cad <submitr>:
    1cad:	41 57                	push   %r15
    1caf:	41 56                	push   %r14
    1cb1:	41 55                	push   %r13
    1cb3:	41 54                	push   %r12
    1cb5:	55                   	push   %rbp
    1cb6:	53                   	push   %rbx
    1cb7:	48 81 ec 68 a0 00 00 	sub    $0xa068,%rsp
    1cbe:	48 89 fd             	mov    %rdi,%rbp
    1cc1:	41 89 f5             	mov    %esi,%r13d
    1cc4:	48 89 14 24          	mov    %rdx,(%rsp)
    1cc8:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
    1ccd:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
    1cd2:	4c 89 4c 24 10       	mov    %r9,0x10(%rsp)
    1cd7:	48 8b 9c 24 a0 a0 00 	mov    0xa0a0(%rsp),%rbx
    1cde:	00 
    1cdf:	4c 8b bc 24 a8 a0 00 	mov    0xa0a8(%rsp),%r15
    1ce6:	00 
    1ce7:	c7 84 24 3c 20 00 00 	movl   $0x0,0x203c(%rsp)
    1cee:	00 00 00 00 
    1cf2:	ba 00 00 00 00       	mov    $0x0,%edx
    1cf7:	be 01 00 00 00       	mov    $0x1,%esi
    1cfc:	bf 02 00 00 00       	mov    $0x2,%edi
    1d01:	e8 ba f4 ff ff       	call   11c0 <socket@plt>
    1d06:	85 c0                	test   %eax,%eax
    1d08:	0f 88 13 01 00 00    	js     1e21 <submitr+0x174>
    1d0e:	41 89 c4             	mov    %eax,%r12d
    1d11:	48 89 ef             	mov    %rbp,%rdi
    1d14:	e8 e7 f3 ff ff       	call   1100 <gethostbyname@plt>
    1d19:	48 85 c0             	test   %rax,%rax
    1d1c:	0f 84 4e 01 00 00    	je     1e70 <submitr+0x1c3>
    1d22:	48 8d ac 24 50 a0 00 	lea    0xa050(%rsp),%rbp
    1d29:	00 
    1d2a:	48 c7 84 24 52 a0 00 	movq   $0x0,0xa052(%rsp)
    1d31:	00 00 00 00 00 
    1d36:	48 c7 84 24 58 a0 00 	movq   $0x0,0xa058(%rsp)
    1d3d:	00 00 00 00 00 
    1d42:	66 c7 84 24 50 a0 00 	movw   $0x2,0xa050(%rsp)
    1d49:	00 02 00 
    1d4c:	48 63 50 14          	movslq 0x14(%rax),%rdx
    1d50:	48 8b 40 18          	mov    0x18(%rax),%rax
    1d54:	48 8b 30             	mov    (%rax),%rsi
    1d57:	48 8d bc 24 54 a0 00 	lea    0xa054(%rsp),%rdi
    1d5e:	00 
    1d5f:	e8 ec f3 ff ff       	call   1150 <memmove@plt>
    1d64:	66 41 c1 c5 08       	rol    $0x8,%r13w
    1d69:	66 44 89 ac 24 52 a0 	mov    %r13w,0xa052(%rsp)
    1d70:	00 00 
    1d72:	ba 10 00 00 00       	mov    $0x10,%edx
    1d77:	48 89 ee             	mov    %rbp,%rsi
    1d7a:	44 89 e7             	mov    %r12d,%edi
    1d7d:	e8 0e f4 ff ff       	call   1190 <connect@plt>
    1d82:	85 c0                	test   %eax,%eax
    1d84:	0f 88 4b 01 00 00    	js     1ed5 <submitr+0x228>
    1d8a:	48 89 df             	mov    %rbx,%rdi
    1d8d:	e8 ee f2 ff ff       	call   1080 <strlen@plt>
    1d92:	48 89 c5             	mov    %rax,%rbp
    1d95:	48 8b 3c 24          	mov    (%rsp),%rdi
    1d99:	e8 e2 f2 ff ff       	call   1080 <strlen@plt>
    1d9e:	49 89 c6             	mov    %rax,%r14
    1da1:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    1da6:	e8 d5 f2 ff ff       	call   1080 <strlen@plt>
    1dab:	49 89 c5             	mov    %rax,%r13
    1dae:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
    1db3:	e8 c8 f2 ff ff       	call   1080 <strlen@plt>
    1db8:	48 89 c2             	mov    %rax,%rdx
    1dbb:	4b 8d 84 2e 80 00 00 	lea    0x80(%r14,%r13,1),%rax
    1dc2:	00 
    1dc3:	48 01 d0             	add    %rdx,%rax
    1dc6:	48 8d 54 6d 00       	lea    0x0(%rbp,%rbp,2),%rdx
    1dcb:	48 01 d0             	add    %rdx,%rax
    1dce:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
    1dd4:	0f 87 52 01 00 00    	ja     1f2c <submitr+0x27f>
    1dda:	48 8d 94 24 40 40 00 	lea    0x4040(%rsp),%rdx
    1de1:	00 
    1de2:	b9 00 04 00 00       	mov    $0x400,%ecx
    1de7:	b8 00 00 00 00       	mov    $0x0,%eax
    1dec:	48 89 d7             	mov    %rdx,%rdi
    1def:	f3 48 ab             	rep stos %rax,%es:(%rdi)
    1df2:	48 89 df             	mov    %rbx,%rdi
    1df5:	e8 86 f2 ff ff       	call   1080 <strlen@plt>
    1dfa:	85 c0                	test   %eax,%eax
    1dfc:	0f 84 1f 02 00 00    	je     2021 <submitr+0x374>
    1e02:	8d 40 ff             	lea    -0x1(%rax),%eax
    1e05:	4c 8d 6c 03 01       	lea    0x1(%rbx,%rax,1),%r13
    1e0a:	48 8d ac 24 40 40 00 	lea    0x4040(%rsp),%rbp
    1e11:	00 
    1e12:	49 be d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r14
    1e19:	00 20 00 
    1e1c:	e9 94 01 00 00       	jmp    1fb5 <submitr+0x308>
    1e21:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    1e28:	3a 20 43 
    1e2b:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    1e32:	20 75 6e 
    1e35:	49 89 07             	mov    %rax,(%r15)
    1e38:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1e3c:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    1e43:	74 6f 20 
    1e46:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    1e4d:	65 20 73 
    1e50:	49 89 47 10          	mov    %rax,0x10(%r15)
    1e54:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1e58:	48 b8 20 73 6f 63 6b 	movabs $0x74656b636f7320,%rax
    1e5f:	65 74 00 
    1e62:	49 89 47 1e          	mov    %rax,0x1e(%r15)
    1e66:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1e6b:	e9 b6 04 00 00       	jmp    2326 <submitr+0x679>
    1e70:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    1e77:	3a 20 44 
    1e7a:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    1e81:	20 75 6e 
    1e84:	49 89 07             	mov    %rax,(%r15)
    1e87:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1e8b:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    1e92:	74 6f 20 
    1e95:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    1e9c:	76 65 20 
    1e9f:	49 89 47 10          	mov    %rax,0x10(%r15)
    1ea3:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1ea7:	48 b8 20 73 65 72 76 	movabs $0x2072657672657320,%rax
    1eae:	65 72 20 
    1eb1:	48 ba 61 64 64 72 65 	movabs $0x73736572646461,%rdx
    1eb8:	73 73 00 
    1ebb:	49 89 47 1f          	mov    %rax,0x1f(%r15)
    1ebf:	49 89 57 27          	mov    %rdx,0x27(%r15)
    1ec3:	44 89 e7             	mov    %r12d,%edi
    1ec6:	e8 e5 f1 ff ff       	call   10b0 <close@plt>
    1ecb:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1ed0:	e9 51 04 00 00       	jmp    2326 <submitr+0x679>
    1ed5:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
    1edc:	3a 20 55 
    1edf:	48 ba 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rdx
    1ee6:	20 74 6f 
    1ee9:	49 89 07             	mov    %rax,(%r15)
    1eec:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1ef0:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
    1ef7:	65 63 74 
    1efa:	48 ba 20 74 6f 20 74 	movabs $0x20656874206f7420,%rdx
    1f01:	68 65 20 
    1f04:	49 89 47 10          	mov    %rax,0x10(%r15)
    1f08:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1f0c:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    1f13:	65 72 00 
    1f16:	49 89 47 1f          	mov    %rax,0x1f(%r15)
    1f1a:	44 89 e7             	mov    %r12d,%edi
    1f1d:	e8 8e f1 ff ff       	call   10b0 <close@plt>
    1f22:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1f27:	e9 fa 03 00 00       	jmp    2326 <submitr+0x679>
    1f2c:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    1f33:	3a 20 52 
    1f36:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    1f3d:	20 73 74 
    1f40:	49 89 07             	mov    %rax,(%r15)
    1f43:	49 89 57 08          	mov    %rdx,0x8(%r15)
    1f47:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
    1f4e:	74 6f 6f 
    1f51:	48 ba 20 6c 61 72 67 	movabs $0x202e656772616c20,%rdx
    1f58:	65 2e 20 
    1f5b:	49 89 47 10          	mov    %rax,0x10(%r15)
    1f5f:	49 89 57 18          	mov    %rdx,0x18(%r15)
    1f63:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
    1f6a:	61 73 65 
    1f6d:	48 ba 20 53 55 42 4d 	movabs $0x5254494d42555320,%rdx
    1f74:	49 54 52 
    1f77:	49 89 47 20          	mov    %rax,0x20(%r15)
    1f7b:	49 89 57 28          	mov    %rdx,0x28(%r15)
    1f7f:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
    1f86:	55 46 00 
    1f89:	49 89 47 30          	mov    %rax,0x30(%r15)
    1f8d:	44 89 e7             	mov    %r12d,%edi
    1f90:	e8 1b f1 ff ff       	call   10b0 <close@plt>
    1f95:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    1f9a:	e9 87 03 00 00       	jmp    2326 <submitr+0x679>
    1f9f:	49 0f a3 c6          	bt     %rax,%r14
    1fa3:	73 1a                	jae    1fbf <submitr+0x312>
    1fa5:	88 55 00             	mov    %dl,0x0(%rbp)
    1fa8:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    1fac:	48 83 c3 01          	add    $0x1,%rbx
    1fb0:	49 39 dd             	cmp    %rbx,%r13
    1fb3:	74 6c                	je     2021 <submitr+0x374>
    1fb5:	0f b6 13             	movzbl (%rbx),%edx
    1fb8:	8d 42 d6             	lea    -0x2a(%rdx),%eax
    1fbb:	3c 35                	cmp    $0x35,%al
    1fbd:	76 e0                	jbe    1f9f <submitr+0x2f2>
    1fbf:	89 d0                	mov    %edx,%eax
    1fc1:	83 e0 df             	and    $0xffffffdf,%eax
    1fc4:	83 e8 41             	sub    $0x41,%eax
    1fc7:	3c 19                	cmp    $0x19,%al
    1fc9:	76 da                	jbe    1fa5 <submitr+0x2f8>
    1fcb:	80 fa 20             	cmp    $0x20,%dl
    1fce:	74 47                	je     2017 <submitr+0x36a>
    1fd0:	8d 42 e0             	lea    -0x20(%rdx),%eax
    1fd3:	3c 5f                	cmp    $0x5f,%al
    1fd5:	76 09                	jbe    1fe0 <submitr+0x333>
    1fd7:	80 fa 09             	cmp    $0x9,%dl
    1fda:	0f 85 cb 03 00 00    	jne    23ab <submitr+0x6fe>
    1fe0:	0f b6 d2             	movzbl %dl,%edx
    1fe3:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
    1fe8:	48 8d 35 d7 14 00 00 	lea    0x14d7(%rip),%rsi        # 34c6 <array.0+0x2e6>
    1fef:	b8 00 00 00 00       	mov    $0x0,%eax
    1ff4:	e8 77 f1 ff ff       	call   1170 <sprintf@plt>
    1ff9:	0f b6 44 24 28       	movzbl 0x28(%rsp),%eax
    1ffe:	88 45 00             	mov    %al,0x0(%rbp)
    2001:	0f b6 44 24 29       	movzbl 0x29(%rsp),%eax
    2006:	88 45 01             	mov    %al,0x1(%rbp)
    2009:	0f b6 44 24 2a       	movzbl 0x2a(%rsp),%eax
    200e:	88 45 02             	mov    %al,0x2(%rbp)
    2011:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
    2015:	eb 95                	jmp    1fac <submitr+0x2ff>
    2017:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
    201b:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
    201f:	eb 8b                	jmp    1fac <submitr+0x2ff>
    2021:	48 8d 9c 24 40 60 00 	lea    0x6040(%rsp),%rbx
    2028:	00 
    2029:	48 83 ec 08          	sub    $0x8,%rsp
    202d:	48 8d 84 24 48 40 00 	lea    0x4048(%rsp),%rax
    2034:	00 
    2035:	50                   	push   %rax
    2036:	4c 8b 4c 24 20       	mov    0x20(%rsp),%r9
    203b:	4c 8b 44 24 28       	mov    0x28(%rsp),%r8
    2040:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
    2045:	48 8b 54 24 10       	mov    0x10(%rsp),%rdx
    204a:	48 8d 35 c7 13 00 00 	lea    0x13c7(%rip),%rsi        # 3418 <array.0+0x238>
    2051:	48 89 df             	mov    %rbx,%rdi
    2054:	b8 00 00 00 00       	mov    $0x0,%eax
    2059:	e8 12 f1 ff ff       	call   1170 <sprintf@plt>
    205e:	48 89 df             	mov    %rbx,%rdi
    2061:	e8 1a f0 ff ff       	call   1080 <strlen@plt>
    2066:	48 89 c3             	mov    %rax,%rbx
    2069:	48 83 c4 10          	add    $0x10,%rsp
    206d:	48 85 c0             	test   %rax,%rax
    2070:	74 3e                	je     20b0 <submitr+0x403>
    2072:	48 8d ac 24 40 60 00 	lea    0x6040(%rsp),%rbp
    2079:	00 
    207a:	41 bd 00 00 00 00    	mov    $0x0,%r13d
    2080:	eb 08                	jmp    208a <submitr+0x3dd>
    2082:	48 01 c5             	add    %rax,%rbp
    2085:	48 29 c3             	sub    %rax,%rbx
    2088:	74 26                	je     20b0 <submitr+0x403>
    208a:	48 89 da             	mov    %rbx,%rdx
    208d:	48 89 ee             	mov    %rbp,%rsi
    2090:	44 89 e7             	mov    %r12d,%edi
    2093:	e8 d8 ef ff ff       	call   1070 <write@plt>
    2098:	48 85 c0             	test   %rax,%rax
    209b:	7f e5                	jg     2082 <submitr+0x3d5>
    209d:	e8 9e ef ff ff       	call   1040 <__errno_location@plt>
    20a2:	83 38 04             	cmpl   $0x4,(%rax)
    20a5:	0f 85 34 01 00 00    	jne    21df <submitr+0x532>
    20ab:	4c 89 e8             	mov    %r13,%rax
    20ae:	eb d2                	jmp    2082 <submitr+0x3d5>
    20b0:	44 89 a4 24 40 80 00 	mov    %r12d,0x8040(%rsp)
    20b7:	00 
    20b8:	c7 84 24 44 80 00 00 	movl   $0x0,0x8044(%rsp)
    20bf:	00 00 00 00 
    20c3:	48 8d bc 24 40 80 00 	lea    0x8040(%rsp),%rdi
    20ca:	00 
    20cb:	48 8d 84 24 50 80 00 	lea    0x8050(%rsp),%rax
    20d2:	00 
    20d3:	48 89 84 24 48 80 00 	mov    %rax,0x8048(%rsp)
    20da:	00 
    20db:	48 8d b4 24 40 60 00 	lea    0x6040(%rsp),%rsi
    20e2:	00 
    20e3:	ba 00 20 00 00       	mov    $0x2000,%edx
    20e8:	e8 f6 fa ff ff       	call   1be3 <rio_readlineb>
    20ed:	48 85 c0             	test   %rax,%rax
    20f0:	0f 8e 4e 01 00 00    	jle    2244 <submitr+0x597>
    20f6:	48 8d 8c 24 3c 20 00 	lea    0x203c(%rsp),%rcx
    20fd:	00 
    20fe:	48 8d 94 24 40 20 00 	lea    0x2040(%rsp),%rdx
    2105:	00 
    2106:	48 8d bc 24 40 60 00 	lea    0x6040(%rsp),%rdi
    210d:	00 
    210e:	4c 8d 44 24 30       	lea    0x30(%rsp),%r8
    2113:	48 8d 35 b3 13 00 00 	lea    0x13b3(%rip),%rsi        # 34cd <array.0+0x2ed>
    211a:	b8 00 00 00 00       	mov    $0x0,%eax
    211f:	e8 1c f0 ff ff       	call   1140 <__isoc99_sscanf@plt>
    2124:	8b 94 24 3c 20 00 00 	mov    0x203c(%rsp),%edx
    212b:	81 fa c8 00 00 00    	cmp    $0xc8,%edx
    2131:	0f 85 7d 01 00 00    	jne    22b4 <submitr+0x607>
    2137:	48 8d 1d a0 13 00 00 	lea    0x13a0(%rip),%rbx        # 34de <array.0+0x2fe>
    213e:	48 8d bc 24 40 60 00 	lea    0x6040(%rsp),%rdi
    2145:	00 
    2146:	48 89 de             	mov    %rbx,%rsi
    2149:	e8 92 ef ff ff       	call   10e0 <strcmp@plt>
    214e:	85 c0                	test   %eax,%eax
    2150:	0f 84 86 01 00 00    	je     22dc <submitr+0x62f>
    2156:	48 8d b4 24 40 60 00 	lea    0x6040(%rsp),%rsi
    215d:	00 
    215e:	48 8d bc 24 40 80 00 	lea    0x8040(%rsp),%rdi
    2165:	00 
    2166:	ba 00 20 00 00       	mov    $0x2000,%edx
    216b:	e8 73 fa ff ff       	call   1be3 <rio_readlineb>
    2170:	48 85 c0             	test   %rax,%rax
    2173:	7f c9                	jg     213e <submitr+0x491>
    2175:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    217c:	3a 20 43 
    217f:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2186:	20 75 6e 
    2189:	49 89 07             	mov    %rax,(%r15)
    218c:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2190:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2197:	74 6f 20 
    219a:	48 ba 72 65 61 64 20 	movabs $0x6165682064616572,%rdx
    21a1:	68 65 61 
    21a4:	49 89 47 10          	mov    %rax,0x10(%r15)
    21a8:	49 89 57 18          	mov    %rdx,0x18(%r15)
    21ac:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
    21b3:	66 72 6f 
    21b6:	48 ba 6d 20 73 65 72 	movabs $0x726576726573206d,%rdx
    21bd:	76 65 72 
    21c0:	49 89 47 20          	mov    %rax,0x20(%r15)
    21c4:	49 89 57 28          	mov    %rdx,0x28(%r15)
    21c8:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
    21cd:	44 89 e7             	mov    %r12d,%edi
    21d0:	e8 db ee ff ff       	call   10b0 <close@plt>
    21d5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    21da:	e9 47 01 00 00       	jmp    2326 <submitr+0x679>
    21df:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    21e6:	3a 20 43 
    21e9:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    21f0:	20 75 6e 
    21f3:	49 89 07             	mov    %rax,(%r15)
    21f6:	49 89 57 08          	mov    %rdx,0x8(%r15)
    21fa:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2201:	74 6f 20 
    2204:	48 ba 77 72 69 74 65 	movabs $0x6f74206574697277,%rdx
    220b:	20 74 6f 
    220e:	49 89 47 10          	mov    %rax,0x10(%r15)
    2212:	49 89 57 18          	mov    %rdx,0x18(%r15)
    2216:	48 b8 65 20 74 6f 20 	movabs $0x656874206f742065,%rax
    221d:	74 68 65 
    2220:	48 ba 20 73 65 72 76 	movabs $0x72657672657320,%rdx
    2227:	65 72 00 
    222a:	49 89 47 1c          	mov    %rax,0x1c(%r15)
    222e:	49 89 57 24          	mov    %rdx,0x24(%r15)
    2232:	44 89 e7             	mov    %r12d,%edi
    2235:	e8 76 ee ff ff       	call   10b0 <close@plt>
    223a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    223f:	e9 e2 00 00 00       	jmp    2326 <submitr+0x679>
    2244:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    224b:	3a 20 43 
    224e:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2255:	20 75 6e 
    2258:	49 89 07             	mov    %rax,(%r15)
    225b:	49 89 57 08          	mov    %rdx,0x8(%r15)
    225f:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    2266:	74 6f 20 
    2269:	48 ba 72 65 61 64 20 	movabs $0x7269662064616572,%rdx
    2270:	66 69 72 
    2273:	49 89 47 10          	mov    %rax,0x10(%r15)
    2277:	49 89 57 18          	mov    %rdx,0x18(%r15)
    227b:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
    2282:	61 64 65 
    2285:	48 ba 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rdx
    228c:	6d 20 73 
    228f:	49 89 47 20          	mov    %rax,0x20(%r15)
    2293:	49 89 57 28          	mov    %rdx,0x28(%r15)
    2297:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    229e:	65 72 00 
    22a1:	49 89 47 2e          	mov    %rax,0x2e(%r15)
    22a5:	44 89 e7             	mov    %r12d,%edi
    22a8:	e8 03 ee ff ff       	call   10b0 <close@plt>
    22ad:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    22b2:	eb 72                	jmp    2326 <submitr+0x679>
    22b4:	48 8d 4c 24 30       	lea    0x30(%rsp),%rcx
    22b9:	48 8d 35 b0 11 00 00 	lea    0x11b0(%rip),%rsi        # 3470 <array.0+0x290>
    22c0:	4c 89 ff             	mov    %r15,%rdi
    22c3:	b8 00 00 00 00       	mov    $0x0,%eax
    22c8:	e8 a3 ee ff ff       	call   1170 <sprintf@plt>
    22cd:	44 89 e7             	mov    %r12d,%edi
    22d0:	e8 db ed ff ff       	call   10b0 <close@plt>
    22d5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    22da:	eb 4a                	jmp    2326 <submitr+0x679>
    22dc:	48 8d b4 24 40 60 00 	lea    0x6040(%rsp),%rsi
    22e3:	00 
    22e4:	48 8d bc 24 40 80 00 	lea    0x8040(%rsp),%rdi
    22eb:	00 
    22ec:	ba 00 20 00 00       	mov    $0x2000,%edx
    22f1:	e8 ed f8 ff ff       	call   1be3 <rio_readlineb>
    22f6:	48 85 c0             	test   %rax,%rax
    22f9:	7e 3d                	jle    2338 <submitr+0x68b>
    22fb:	48 8d b4 24 40 60 00 	lea    0x6040(%rsp),%rsi
    2302:	00 
    2303:	4c 89 ff             	mov    %r15,%rdi
    2306:	e8 45 ed ff ff       	call   1050 <strcpy@plt>
    230b:	44 89 e7             	mov    %r12d,%edi
    230e:	e8 9d ed ff ff       	call   10b0 <close@plt>
    2313:	48 8d 35 c7 11 00 00 	lea    0x11c7(%rip),%rsi        # 34e1 <array.0+0x301>
    231a:	4c 89 ff             	mov    %r15,%rdi
    231d:	e8 be ed ff ff       	call   10e0 <strcmp@plt>
    2322:	f7 d8                	neg    %eax
    2324:	19 c0                	sbb    %eax,%eax
    2326:	48 81 c4 68 a0 00 00 	add    $0xa068,%rsp
    232d:	5b                   	pop    %rbx
    232e:	5d                   	pop    %rbp
    232f:	41 5c                	pop    %r12
    2331:	41 5d                	pop    %r13
    2333:	41 5e                	pop    %r14
    2335:	41 5f                	pop    %r15
    2337:	c3                   	ret
    2338:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    233f:	3a 20 43 
    2342:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2349:	20 75 6e 
    234c:	49 89 07             	mov    %rax,(%r15)
    234f:	49 89 57 08          	mov    %rdx,0x8(%r15)
    2353:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    235a:	74 6f 20 
    235d:	48 ba 72 65 61 64 20 	movabs $0x6174732064616572,%rdx
    2364:	73 74 61 
    2367:	49 89 47 10          	mov    %rax,0x10(%r15)
    236b:	49 89 57 18          	mov    %rdx,0x18(%r15)
    236f:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
    2376:	65 73 73 
    2379:	48 ba 61 67 65 20 66 	movabs $0x6d6f726620656761,%rdx
    2380:	72 6f 6d 
    2383:	49 89 47 20          	mov    %rax,0x20(%r15)
    2387:	49 89 57 28          	mov    %rdx,0x28(%r15)
    238b:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
    2392:	65 72 00 
    2395:	49 89 47 30          	mov    %rax,0x30(%r15)
    2399:	44 89 e7             	mov    %r12d,%edi
    239c:	e8 0f ed ff ff       	call   10b0 <close@plt>
    23a1:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    23a6:	e9 7b ff ff ff       	jmp    2326 <submitr+0x679>
    23ab:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
    23b2:	3a 20 52 
    23b5:	48 ba 65 73 75 6c 74 	movabs $0x747320746c757365,%rdx
    23bc:	20 73 74 
    23bf:	49 89 07             	mov    %rax,(%r15)
    23c2:	49 89 57 08          	mov    %rdx,0x8(%r15)
    23c6:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
    23cd:	63 6f 6e 
    23d0:	48 ba 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rdx
    23d7:	20 61 6e 
    23da:	49 89 47 10          	mov    %rax,0x10(%r15)
    23de:	49 89 57 18          	mov    %rdx,0x18(%r15)
    23e2:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
    23e9:	67 61 6c 
    23ec:	48 ba 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rdx
    23f3:	6e 70 72 
    23f6:	49 89 47 20          	mov    %rax,0x20(%r15)
    23fa:	49 89 57 28          	mov    %rdx,0x28(%r15)
    23fe:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
    2405:	6c 65 20 
    2408:	48 ba 63 68 61 72 61 	movabs $0x6574636172616863,%rdx
    240f:	63 74 65 
    2412:	49 89 47 30          	mov    %rax,0x30(%r15)
    2416:	49 89 57 38          	mov    %rdx,0x38(%r15)
    241a:	41 c7 47 3f 65 72 2e 	movl   $0x2e7265,0x3f(%r15)
    2421:	00 
    2422:	44 89 e7             	mov    %r12d,%edi
    2425:	e8 86 ec ff ff       	call   10b0 <close@plt>
    242a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    242f:	e9 f2 fe ff ff       	jmp    2326 <submitr+0x679>

0000000000002434 <init_timeout>:
    2434:	85 ff                	test   %edi,%edi
    2436:	75 01                	jne    2439 <init_timeout+0x5>
    2438:	c3                   	ret
    2439:	53                   	push   %rbx
    243a:	89 fb                	mov    %edi,%ebx
    243c:	48 8d 35 75 f7 ff ff 	lea    -0x88b(%rip),%rsi        # 1bb8 <sigalrm_handler>
    2443:	bf 0e 00 00 00       	mov    $0xe,%edi
    2448:	e8 a3 ec ff ff       	call   10f0 <signal@plt>
    244d:	85 db                	test   %ebx,%ebx
    244f:	b8 00 00 00 00       	mov    $0x0,%eax
    2454:	0f 49 c3             	cmovns %ebx,%eax
    2457:	89 c7                	mov    %eax,%edi
    2459:	e8 42 ec ff ff       	call   10a0 <alarm@plt>
    245e:	5b                   	pop    %rbx
    245f:	c3                   	ret

0000000000002460 <init_driver>:
    2460:	41 54                	push   %r12
    2462:	55                   	push   %rbp
    2463:	53                   	push   %rbx
    2464:	48 83 ec 10          	sub    $0x10,%rsp
    2468:	48 89 fd             	mov    %rdi,%rbp
    246b:	be 01 00 00 00       	mov    $0x1,%esi
    2470:	bf 0d 00 00 00       	mov    $0xd,%edi
    2475:	e8 76 ec ff ff       	call   10f0 <signal@plt>
    247a:	be 01 00 00 00       	mov    $0x1,%esi
    247f:	bf 1d 00 00 00       	mov    $0x1d,%edi
    2484:	e8 67 ec ff ff       	call   10f0 <signal@plt>
    2489:	be 01 00 00 00       	mov    $0x1,%esi
    248e:	bf 1d 00 00 00       	mov    $0x1d,%edi
    2493:	e8 58 ec ff ff       	call   10f0 <signal@plt>
    2498:	ba 00 00 00 00       	mov    $0x0,%edx
    249d:	be 01 00 00 00       	mov    $0x1,%esi
    24a2:	bf 02 00 00 00       	mov    $0x2,%edi
    24a7:	e8 14 ed ff ff       	call   11c0 <socket@plt>
    24ac:	85 c0                	test   %eax,%eax
    24ae:	0f 88 84 00 00 00    	js     2538 <init_driver+0xd8>
    24b4:	89 c3                	mov    %eax,%ebx
    24b6:	48 8d 3d 27 10 00 00 	lea    0x1027(%rip),%rdi        # 34e4 <array.0+0x304>
    24bd:	e8 3e ec ff ff       	call   1100 <gethostbyname@plt>
    24c2:	48 85 c0             	test   %rax,%rax
    24c5:	0f 84 ba 00 00 00    	je     2585 <init_driver+0x125>
    24cb:	49 89 e4             	mov    %rsp,%r12
    24ce:	48 c7 44 24 02 00 00 	movq   $0x0,0x2(%rsp)
    24d5:	00 00 
    24d7:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    24de:	00 00 
    24e0:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
    24e6:	48 63 50 14          	movslq 0x14(%rax),%rdx
    24ea:	48 8b 40 18          	mov    0x18(%rax),%rax
    24ee:	48 8b 30             	mov    (%rax),%rsi
    24f1:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
    24f6:	e8 55 ec ff ff       	call   1150 <memmove@plt>
    24fb:	66 c7 44 24 02 3b 6e 	movw   $0x6e3b,0x2(%rsp)
    2502:	ba 10 00 00 00       	mov    $0x10,%edx
    2507:	4c 89 e6             	mov    %r12,%rsi
    250a:	89 df                	mov    %ebx,%edi
    250c:	e8 7f ec ff ff       	call   1190 <connect@plt>
    2511:	85 c0                	test   %eax,%eax
    2513:	0f 88 d1 00 00 00    	js     25ea <init_driver+0x18a>
    2519:	89 df                	mov    %ebx,%edi
    251b:	e8 90 eb ff ff       	call   10b0 <close@plt>
    2520:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
    2526:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
    252a:	b8 00 00 00 00       	mov    $0x0,%eax
    252f:	48 83 c4 10          	add    $0x10,%rsp
    2533:	5b                   	pop    %rbx
    2534:	5d                   	pop    %rbp
    2535:	41 5c                	pop    %r12
    2537:	c3                   	ret
    2538:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
    253f:	3a 20 43 
    2542:	48 ba 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rdx
    2549:	20 75 6e 
    254c:	48 89 45 00          	mov    %rax,0x0(%rbp)
    2550:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    2554:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    255b:	74 6f 20 
    255e:	48 ba 63 72 65 61 74 	movabs $0x7320657461657263,%rdx
    2565:	65 20 73 
    2568:	48 89 45 10          	mov    %rax,0x10(%rbp)
    256c:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    2570:	48 b8 20 73 6f 63 6b 	movabs $0x74656b636f7320,%rax
    2577:	65 74 00 
    257a:	48 89 45 1e          	mov    %rax,0x1e(%rbp)
    257e:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2583:	eb aa                	jmp    252f <init_driver+0xcf>
    2585:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
    258c:	3a 20 44 
    258f:	48 ba 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rdx
    2596:	20 75 6e 
    2599:	48 89 45 00          	mov    %rax,0x0(%rbp)
    259d:	48 89 55 08          	mov    %rdx,0x8(%rbp)
    25a1:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
    25a8:	74 6f 20 
    25ab:	48 ba 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rdx
    25b2:	76 65 20 
    25b5:	48 89 45 10          	mov    %rax,0x10(%rbp)
    25b9:	48 89 55 18          	mov    %rdx,0x18(%rbp)
    25bd:	48 b8 20 73 65 72 76 	movabs $0x2072657672657320,%rax
    25c4:	65 72 20 
    25c7:	48 ba 61 64 64 72 65 	movabs $0x73736572646461,%rdx
    25ce:	73 73 00 
    25d1:	48 89 45 1f          	mov    %rax,0x1f(%rbp)
    25d5:	48 89 55 27          	mov    %rdx,0x27(%rbp)
    25d9:	89 df                	mov    %ebx,%edi
    25db:	e8 d0 ea ff ff       	call   10b0 <close@plt>
    25e0:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    25e5:	e9 45 ff ff ff       	jmp    252f <init_driver+0xcf>
    25ea:	48 8d 15 f3 0e 00 00 	lea    0xef3(%rip),%rdx        # 34e4 <array.0+0x304>
    25f1:	48 8d 35 a8 0e 00 00 	lea    0xea8(%rip),%rsi        # 34a0 <array.0+0x2c0>
    25f8:	48 89 ef             	mov    %rbp,%rdi
    25fb:	b8 00 00 00 00       	mov    $0x0,%eax
    2600:	e8 6b eb ff ff       	call   1170 <sprintf@plt>
    2605:	89 df                	mov    %ebx,%edi
    2607:	e8 a4 ea ff ff       	call   10b0 <close@plt>
    260c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    2611:	e9 19 ff ff ff       	jmp    252f <init_driver+0xcf>

0000000000002616 <driver_post>:
    2616:	53                   	push   %rbx
    2617:	4c 89 c3             	mov    %r8,%rbx
    261a:	85 c9                	test   %ecx,%ecx
    261c:	75 17                	jne    2635 <driver_post+0x1f>
    261e:	48 85 ff             	test   %rdi,%rdi
    2621:	74 05                	je     2628 <driver_post+0x12>
    2623:	80 3f 00             	cmpb   $0x0,(%rdi)
    2626:	75 31                	jne    2659 <driver_post+0x43>
    2628:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    262d:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    2631:	89 c8                	mov    %ecx,%eax
    2633:	5b                   	pop    %rbx
    2634:	c3                   	ret
    2635:	48 89 d6             	mov    %rdx,%rsi
    2638:	48 8d 3d bd 0e 00 00 	lea    0xebd(%rip),%rdi        # 34fc <array.0+0x31c>
    263f:	b8 00 00 00 00       	mov    $0x0,%eax
    2644:	e8 47 ea ff ff       	call   1090 <printf@plt>
    2649:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
    264e:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
    2652:	b8 00 00 00 00       	mov    $0x0,%eax
    2657:	eb da                	jmp    2633 <driver_post+0x1d>
    2659:	41 50                	push   %r8
    265b:	52                   	push   %rdx
    265c:	4c 8d 0d b0 0e 00 00 	lea    0xeb0(%rip),%r9        # 3513 <array.0+0x333>
    2663:	49 89 f0             	mov    %rsi,%r8
    2666:	48 89 f9             	mov    %rdi,%rcx
    2669:	48 8d 15 ab 0e 00 00 	lea    0xeab(%rip),%rdx        # 351b <array.0+0x33b>
    2670:	be 6e 3b 00 00       	mov    $0x3b6e,%esi
    2675:	48 8d 3d 68 0e 00 00 	lea    0xe68(%rip),%rdi        # 34e4 <array.0+0x304>
    267c:	e8 2c f6 ff ff       	call   1cad <submitr>
    2681:	48 83 c4 10          	add    $0x10,%rsp
    2685:	eb ac                	jmp    2633 <driver_post+0x1d>

Disassembly of section .fini:

0000000000002688 <_fini>:
    2688:	48 83 ec 08          	sub    $0x8,%rsp
    268c:	48 83 c4 08          	add    $0x8,%rsp
    2690:	c3                   	ret
