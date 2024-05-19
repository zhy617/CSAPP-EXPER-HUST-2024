0x0000555555555c27 <+0>:     f3 0f 1e fa     endbr64
0x0000555555555c2b <+4>:     55      push   rbp
0x0000555555555c2c <+5>:     48 89 e5        mov    rbp,rsp
0x0000555555555c2f <+8>:     48 83 ec 30     sub    rsp,0x30
0x0000555555555c33 <+12>:    48 89 7d d8     mov    QWORD PTR [rbp-0x28],rdi
保存现场 rdi -> [-0x28] = 0x5555555597b0
0x0000555555555c37 <+16>:    64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28

0x0000555555555c40 <+25>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax

0x0000555555555c44 <+29>:    31 c0   xor    eax,eax
0x0000555555555c46 <+31>:    48 8d 4d e8     lea    rcx,[rbp-0x18]
rcx 保存 (rbp-0x18) 地址 = 0x7fffffffe0b8
0x0000555555555c4a <+35>:    48 8d 55 e4     lea    rdx,[rbp-0x1c]
rdx 保存 (rbp-0x1c) 地址 = 0x7fffffffe0b4
0x0000555555555c4e <+39>:    48 8b 45 d8     mov    rax,QWORD PTR [rbp-0x28]
rax = rdi = 0x5555555597b0
0x0000555555555c52 <+43>:    48 8d 35 e3 16 00 00    lea    rsi,[rip+0x16e3]        # 0x55555555733c
rsi = 0x55555555733c
0x0000555555555c59 <+50>:    48 89 c7        mov    rdi,rax
rdi = rax = 0x5555555597b0
0x0000555555555c5c <+53>:    b8 00 00 00 00  mov    eax,0x0
eax = 0
0x0000555555555c61 <+58>:    e8 3a f5 ff ff  call   0x5555555551a0 <__isoc99_sscanf@plt>
0x0000555555555c66 <+63>:    89 45 ec        mov    DWORD PTR [rbp-0x14],eax
cnt = eax = 读取个数
0x0000555555555c69 <+66>:    83 7d ec 02     cmp    DWORD PTR [rbp-0x14],0x2
0x0000555555555c6d <+70>:    75 0f   jne    0x555555555c7e <phase_4+87>
0x0000555555555c6f <+72>:    8b 45 e4        mov    eax,DWORD PTR [rbp-0x1c]
eax = 1 第一个参数
0x0000555555555c72 <+75>:    85 c0   test   eax,eax
与运算
0x0000555555555c74 <+77>:    78 08   js     0x555555555c7e <phase_4+87>
当执行到JS指令时，如果标志位SF=1，则跳转到指定的地址，如果SF=0，不跳转
if(eax < 0) bomb
0x0000555555555c76 <+79>:    8b 45 e4        mov    eax,DWORD PTR [rbp-0x1c]
eax = 1
0x0000555555555c79 <+82>:    83 f8 0e        cmp    eax,0xe
if(eax <= 14)
0x0000555555555c7c <+85>:    7e 05   jle    0x555555555c83 <phase_4+92>
0x0000555555555c7e <+87>:    e8 7b fc ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555c83 <+92>:    c7 45 f0 07 00 00 00    mov    DWORD PTR [rbp-0x10],0x7
int x = 7 (rbp-0x10)
0x0000555555555c8a <+99>:    8b 45 e4        mov    eax,DWORD PTR [rbp-0x1c]
eax = 1;
0x0000555555555c8d <+102>:   ba 0e 00 00 00  mov    edx,0xe
edx = 14
0x0000555555555c92 <+107>:   be 00 00 00 00  mov    esi,0x0
esi = 0
0x0000555555555c97 <+112>:   89 c7   mov    edi,eax
edi = eax = 1;
0x0000555555555c99 <+114>:   e8 0f ff ff ff  call   0x555555555bad <func4>
0x0000555555555c9e <+119>:   89 45 f4        mov    DWORD PTR [rbp-0xc],eax
[-0xc] = eax = ans;
0x0000555555555ca1 <+122>:   8b 45 f4        mov    eax,DWORD PTR [rbp-0xc]
eax = ans
0x0000555555555ca4 <+125>:   3b 45 f0        cmp    eax,DWORD PTR [rbp-0x10]
if ans != 7
0x0000555555555ca7 <+128>:   75 08   jne    0x555555555cb1 <phase_4+138>
0x0000555555555ca9 <+130>:   8b 45 e8        mov    eax,DWORD PTR [rbp-0x18]
eax = x_2 = 3;
0x0000555555555cac <+133>:   39 45 f0        cmp    DWORD PTR [rbp-0x10],eax
if 7 == x_2
0x0000555555555caf <+136>:   74 05   je     0x555555555cb6 <phase_4+143>
0x0000555555555cb1 <+138>:   e8 48 fc ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555cb6 <+143>:   90      nop
0x0000555555555cb7 <+144>:   48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
rax = 恢复现场
0x0000555555555cbb <+148>:   64 48 33 04 25 28 00 00 00      xor    rax,QWORD PTR fs:0x28
0x0000555555555cc4 <+157>:   74 05   je     0x555555555ccb <phase_4+164>
0x0000555555555cc6 <+159>:   e8 85 f4 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
0x0000555555555ccb <+164>:   c9      leave
0x0000555555555ccc <+165>:   c3      ret





func4:
edi = 1,esi = 0,edx = 14;

0x0000555555555bad <+0>:     f3 0f 1e fa     endbr64
0x0000555555555bb1 <+4>:     55      push   rbp
0x0000555555555bb2 <+5>:     48 89 e5        mov    rbp,rsp
0x0000555555555bb5 <+8>:     48 83 ec 20     sub    rsp,0x20
0x0000555555555bb9 <+12>:    89 7d ec        mov    DWORD PTR [rbp-0x14],edi
[-0x14] = 1 = x
0x0000555555555bbc <+15>:    89 75 e8        mov    DWORD PTR [rbp-0x18],esi
[-0x18] = esi = 0 = l
0x0000555555555bbf <+18>:    89 55 e4        mov    DWORD PTR [rbp-0x1c],edx
[-0x1c] = edx = 14 = r;
0x0000555555555bc2 <+21>:    8b 45 e4        mov    eax,DWORD PTR [rbp-0x1c]
eax = [-0x1c] = 14 = r;
0x0000555555555bc5 <+24>:    2b 45 e8        sub    eax,DWORD PTR [rbp-0x18]
eax = eax - [-0x18] = 14 = len = r - l;
0x0000555555555bc8 <+27>:    89 c2   mov    edx,eax
edx = eax = 14;
0x0000555555555bca <+29>:    c1 ea 1f        shr    edx,0x1f
edx >>= 31 = 0;
0x0000555555555bcd <+32>:    01 d0   add    eax,edx
eax = 14 + edx = 14;?
0x0000555555555bcf <+34>:    d1 f8   sar    eax,1
eax /=2 =7;
0x0000555555555bd1 <+36>:    89 c2   mov    edx,eax
edx = eax = 7;
0x0000555555555bd3 <+38>:    8b 45 e8        mov    eax,DWORD PTR [rbp-0x18]
eax = [-0x18] = l = 0
0x0000555555555bd6 <+41>:    01 d0   add    eax,edx
eax += edx = 7;
0x0000555555555bd8 <+43>:    89 45 fc        mov    DWORD PTR [rbp-0x4],eax
mid = [-0x4] = eax = 7; mid = (r-l)/2+l;
0x0000555555555bdb <+46>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
eax = mid = 7;
0x0000555555555bde <+49>:    3b 45 ec        cmp    eax,DWORD PTR [rbp-0x14]
if(mid <= x)
0x0000555555555be1 <+52>:    7e 19   jle    0x555555555bfc <func4+79>

mid > x
0x0000555555555be3 <+54>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
eax = mid;
0x0000555555555be6 <+57>:    8d 50 ff        lea    edx,[rax-0x1]
edx = rax -1 = mid -1;
0x0000555555555be9 <+60>:    8b 4d e8        mov    ecx,DWORD PTR [rbp-0x18]
ecx = l;
0x0000555555555bec <+63>:    8b 45 ec        mov    eax,DWORD PTR [rbp-0x14]
eax = x;
0x0000555555555bef <+66>:    89 ce   mov    esi,ecx
esi = ecx = l;
0x0000555555555bf1 <+68>:    89 c7   mov    edi,eax
edi = eax = x

_x = x,_l = l,_r = mid-1
0x0000555555555bf3 <+70>:    e8 b5 ff ff ff  call   0x555555555bad <func4>
0x0000555555555bf8 <+75>:    01 c0   add    eax,eax
eax *= 2;?
0x0000555555555bfa <+77>:    eb 29   jmp    0x555555555c25 <func4+120>
0x0000555555555bfc <+79>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
eax = mid;
0x0000555555555bff <+82>:    3b 45 ec        cmp    eax,DWORD PTR [rbp-0x14]
if(mid >= x)
0x0000555555555c02 <+85>:    7d 1c   jge    0x555555555c20 <func4+115>

mid < x
0x0000555555555c04 <+87>:    8b 45 fc        mov    eax,DWORD PTR [rbp-0x4]
eax = mid;
0x0000555555555c07 <+90>:    8d 48 01        lea    ecx,[rax+0x1]
ecx = mid+1;
0x0000555555555c0a <+93>:    8b 55 e4        mov    edx,DWORD PTR [rbp-0x1c]
edx = r;
0x0000555555555c0d <+96>:    8b 45 ec        mov    eax,DWORD PTR [rbp-0x14]
eax = x;
0x0000555555555c10 <+99>:    89 ce   mov    esi,ecx
esi = ecx = mid+1;
0x0000555555555c12 <+101>:   89 c7   mov    edi,eax
edi = eax = mid;

_x = x,_l = mid+1,_r = r;
0x0000555555555c14 <+103>:   e8 94 ff ff ff  call   0x555555555bad <func4>
0x0000555555555c19 <+108>:   01 c0   add    eax,eax
0x0000555555555c1b <+110>:   83 c0 01        add    eax,0x1
eax = 2*eax + 1;
0x0000555555555c1e <+113>:   eb 05   jmp    0x555555555c25 <func4+120>
0x0000555555555c20 <+115>:   b8 00 00 00 00  mov    eax,0x0
eax = 0;
0x0000555555555c25 <+120>:   c9      leave
0x0000555555555c26 <+121>:   c3      ret

0 14
ans = 7 = 0111

0 14     
0 6                 8 14
0 2       4 6       8 10        12 14
0 0 2 2   4 4 6 6   8 8 10 10   12 12  14 14

14 14 0
12 14 1
8 14  3
0 14  7

14 7