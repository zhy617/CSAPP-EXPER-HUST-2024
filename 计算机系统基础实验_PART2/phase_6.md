0x0000555555555d7c <+0>:     f3 0f 1e fa     endbr64
0x0000555555555d80 <+4>:     55      push   rbp
0x0000555555555d81 <+5>:     48 89 e5        mov    rbp,rsp
0x0000555555555d84 <+8>:     48 81 ec 90 00 00 00    sub    rsp,0x90
0x0000555555555d8b <+15>:    48 89 bd 78 ff ff ff    mov    QWORD PTR [rbp-0x88],rdi
rdi = 0x555555559850 = ptr
0x0000555555555d92 <+22>:    64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28
0x0000555555555d9b <+31>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax
0x0000555555555d9f <+35>:    31 c0   xor    eax,eax
0x0000555555555da1 <+37>:    48 8d 05 e8 37 00 00    lea    rax,[rip+0x37e8]        # 0x555555559590 <node1>
rax = &node1
0x0000555555555da8 <+44>:    48 89 45 98     mov    QWORD PTR [rbp-0x68],rax
begin = [-0x68] = rax = &node1;
0x0000555555555dac <+48>:    48 8d 55 a0     lea    rdx,[rbp-0x60]
rdx = -0x60 = &numbers[]
0x0000555555555db0 <+52>:    48 8b 85 78 ff ff ff    mov    rax,QWORD PTR [rbp-0x88]
rax = ptr;
0x0000555555555db7 <+59>:    48 89 d6        mov    rsi,rdx
0x0000555555555dba <+62>:    48 89 c7        mov    rdi,rax
0x0000555555555dbd <+65>:    e8 98 f7 ff ff  call   0x55555555555a <read_six_numbers>
0x0000555555555dc2 <+70>:    c7 45 88 00 00 00 00    mov    DWORD PTR [rbp-0x78],0x0
int i = [-0x78] = 0;
0x0000555555555dc9 <+77>:    eb 54   jmp    0x555555555e1f <phase_6+163>
0x0000555555555dcb <+79>:    8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555dce <+82>:    48 98   cdqe
0x0000555555555dd0 <+84>:    8b 44 85 a0     mov    eax,DWORD PTR [rbp+rax*4-0x60]
eax = numbers[i];
0x0000555555555dd4 <+88>:    85 c0   test   eax,eax
0x0000555555555dd6 <+90>:    7e 0e   jle    0x555555555de6 <phase_6+106>
if eax <= 0
0x0000555555555dd8 <+92>:    8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555ddb <+95>:    48 98   cdqe
0x0000555555555ddd <+97>:    8b 44 85 a0     mov    eax,DWORD PTR [rbp+rax*4-0x60]
eax = numbers[i];
0x0000555555555de1 <+101>:   83 f8 06        cmp    eax,0x6
if(numbers[i] <= 6)
0x0000555555555de4 <+104>:   7e 05   jle    0x555555555deb <phase_6+111>
0x0000555555555de6 <+106>:   e8 13 fb ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555deb <+111>:   8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555dee <+114>:   83 c0 01        add    eax,0x1
eax += 1;
0x0000555555555df1 <+117>:   89 45 8c        mov    DWORD PTR [rbp-0x74],eax
int j = [-0x74] = i+1;
0x0000555555555df4 <+120>:   eb 1f   jmp    0x555555555e15 <phase_6+153>
0x0000555555555df6 <+122>:   8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555df9 <+125>:   48 98   cdqe
0x0000555555555dfb <+127>:   8b 54 85 a0     mov    edx,DWORD PTR [rbp+rax*4-0x60]
edx = numbers[i];
0x0000555555555dff <+131>:   8b 45 8c        mov    eax,DWORD PTR [rbp-0x74]
eax = j;
0x0000555555555e02 <+134>:   48 98   cdqe
0x0000555555555e04 <+136>:   8b 44 85 a0     mov    eax,DWORD PTR [rbp+rax*4-0x60]
eax = numbers[j];
0x0000555555555e08 <+140>:   39 c2   cmp    edx,eax
if(numbers[i] != numbers[j])
0x0000555555555e0a <+142>:   75 05   jne    0x555555555e11 <phase_6+149>
0x0000555555555e0c <+144>:   e8 ed fa ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555e11 <+149>:   83 45 8c 01     add    DWORD PTR [rbp-0x74],0x1

0x0000555555555e15 <+153>:   83 7d 8c 05     cmp    DWORD PTR [rbp-0x74],0x5
if( j < = 5 )
0x0000555555555e19 <+157>:   7e db   jle    0x555555555df6 <phase_6+122>
0x0000555555555e1b <+159>:   83 45 88 01     add    DWORD PTR [rbp-0x78],0x1

0x0000555555555e1f <+163>:   83 7d 88 05     cmp    DWORD PTR [rbp-0x78],0x5
if i <= 5 
0x0000555555555e23 <+167>:   7e a6   jle    0x555555555dcb <phase_6+79>



0x0000555555555e25 <+169>:   c7 45 88 00 00 00 00    mov    DWORD PTR [rbp-0x78],0x0
i = 0;
0x0000555555555e2c <+176>:   eb 41   jmp    0x555555555e6f <phase_6+243>
0x0000555555555e2e <+178>:   48 8b 45 98     mov    rax,QWORD PTR [rbp-0x68]
rax = &node1;
0x0000555555555e32 <+182>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
&nodei = [-0x70] = rax = &node1;
0x0000555555555e36 <+186>:   c7 45 8c 01 00 00 00    mov    DWORD PTR [rbp-0x74],0x1
j = 1;
0x0000555555555e3d <+193>:   eb 10   jmp    0x555555555e4f <phase_6+211>
0x0000555555555e3f <+195>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
rax = &node1 = 0x555555559590;
0x0000555555555e43 <+199>:   48 8b 40 08     mov    rax,QWORD PTR [rax+0x8]
rax = [rax + 8] = node.next;
0x0000555555555e47 <+203>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
[-0x70] = rax;
0x0000555555555e4b <+207>:   83 45 8c 01     add    DWORD PTR [rbp-0x74],0x1
j ++;
0x0000555555555e4f <+211>:   8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555e52 <+214>:   48 98   cdqe
0x0000555555555e54 <+216>:   8b 44 85 a0     mov    eax,DWORD PTR [rbp+rax*4-0x60]
eax = numbers[i];
0x0000555555555e58 <+220>:   39 45 8c        cmp    DWORD PTR [rbp-0x74],eax
if(j < eax = numbers[i])
0x0000555555555e5b <+223>:   7c e2   jl     0x555555555e3f <phase_6+195>

0x0000555555555e5d <+225>:   8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555e60 <+228>:   48 98   cdqe
0x0000555555555e62 <+230>:   48 8b 55 90     mov    rdx,QWORD PTR [rbp-0x70]
rdx = nodei;
0x0000555555555e66 <+234>:   48 89 54 c5 c0  mov    QWORD PTR [rbp+rax*8-0x40],rdx
ans[i] = rdx;
0x0000555555555e6b <+239>:   83 45 88 01     add    DWORD PTR [rbp-0x78],0x1
i++;
0x0000555555555e6f <+243>:   83 7d 88 05     cmp    DWORD PTR [rbp-0x78],0x5
0x0000555555555e73 <+247>:   7e b9   jle    0x555555555e2e <phase_6+178>
if(i <= 5)

0x0000555555555e75 <+249>:   48 8b 45 c0     mov    rax,QWORD PTR [rbp-0x40]
rax = &ans;
0x0000555555555e79 <+253>:   48 89 45 98     mov    QWORD PTR [rbp-0x68],rax

0x0000555555555e7d <+257>:   48 8b 45 98     mov    rax,QWORD PTR [rbp-0x68]
rax = &node1
0x0000555555555e81 <+261>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
it = &node1
0x0000555555555e85 <+265>:   c7 45 88 01 00 00 00    mov    DWORD PTR [rbp-0x78],0x1
i = 1;
0x0000555555555e8c <+272>:   eb 22   jmp    0x555555555eb0 <phase_6+308>
0x0000555555555e8e <+274>:   8b 45 88        mov    eax,DWORD PTR [rbp-0x78]
eax = i;
0x0000555555555e91 <+277>:   48 98   cdqe
0x0000555555555e93 <+279>:   48 8b 54 c5 c0  mov    rdx,QWORD PTR [rbp+rax*8-0x40]
rdx = ans[i];
0x0000555555555e98 <+284>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
rax = it;
0x0000555555555e9c <+288>:   48 89 50 08     mov    QWORD PTR [rax+0x8],rdx
it
0x0000555555555ea0 <+292>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
0x0000555555555ea4 <+296>:   48 8b 40 08     mov    rax,QWORD PTR [rax+0x8]
0x0000555555555ea8 <+300>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
0x0000555555555eac <+304>:   83 45 88 01     add    DWORD PTR [rbp-0x78],0x1
0x0000555555555eb0 <+308>:   83 7d 88 05     cmp    DWORD PTR [rbp-0x78],0x5
if i <= 5
0x0000555555555eb4 <+312>:   7e d8   jle    0x555555555e8e <phase_6+274>
0x0000555555555eb6 <+314>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
0x0000555555555eba <+318>:   48 c7 40 08 00 00 00 00 mov    QWORD PTR [rax+0x8],0x0
0x0000555555555ec2 <+326>:   48 8b 45 98     mov    rax,QWORD PTR [rbp-0x68]
0x0000555555555ec6 <+330>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
0x0000555555555eca <+334>:   c7 45 88 00 00 00 00    mov    DWORD PTR [rbp-0x78],0x0
0x0000555555555ed1 <+341>:   eb 29   jmp    0x555555555efc <phase_6+384>
0x0000555555555ed3 <+343>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
0x0000555555555ed7 <+347>:   8b 10   mov    edx,DWORD PTR [rax]
0x0000555555555ed9 <+349>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
0x0000555555555edd <+353>:   48 8b 40 08     mov    rax,QWORD PTR [rax+0x8]
0x0000555555555ee1 <+357>:   8b 00   mov    eax,DWORD PTR [rax]
0x0000555555555ee3 <+359>:   39 c2   cmp    edx,eax
0x0000555555555ee5 <+361>:   7d 05   jge    0x555555555eec <phase_6+368>
0x0000555555555ee7 <+363>:   e8 12 fa ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555eec <+368>:   48 8b 45 90     mov    rax,QWORD PTR [rbp-0x70]
0x0000555555555ef0 <+372>:   48 8b 40 08     mov    rax,QWORD PTR [rax+0x8]
0x0000555555555ef4 <+376>:   48 89 45 90     mov    QWORD PTR [rbp-0x70],rax
0x0000555555555ef8 <+380>:   83 45 88 01     add    DWORD PTR [rbp-0x78],0x1
0x0000555555555efc <+384>:   83 7d 88 04     cmp    DWORD PTR [rbp-0x78],0x4
0x0000555555555f00 <+388>:   7e d1   jle    0x555555555ed3 <phase_6+343>
0x0000555555555f02 <+390>:   90      nop
0x0000555555555f03 <+391>:   48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
0x0000555555555f07 <+395>:   64 48 33 04 25 28 00 00 00      xor    rax,QWORD PTR fs:0x28
0x0000555555555f10 <+404>:   74 05   je     0x555555555f17 <phase_6+411>
0x0000555555555f12 <+406>:   e8 39 f2 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
0x0000555555555f17 <+411>:   c9      leave
0x0000555555555f18 <+412>:   c3      ret


1 0x555555559590  0x00000001 0x00000119
2 0x555555559580  0x00000002 0x0000038b
3 0x555555559570  0x00000003 0x00000142
4 0x555555559560  0x00000004 0x00000079
5 0x555555559550  0x00000005 0x00000338
6 0x555555559430  0x00000006 0x00000210

2 5 6 3 1 4