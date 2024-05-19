0x0000555555555ccd <+0>:     f3 0f 1e fa     endbr64
0x0000555555555cd1 <+4>:     55      push   rbp
0x0000555555555cd2 <+5>:     48 89 e5        mov    rbp,rsp
0x0000555555555cd5 <+8>:     48 83 ec 30     sub    rsp,0x30
0x0000555555555cd9 <+12>:    48 89 7d d8     mov    QWORD PTR [rbp-0x28],rdi
保存 [-0x28] = rdi = 0x555555559800 = char* ptr;
0x0000555555555cdd <+16>:    64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28
0x0000555555555ce6 <+25>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax
保存 [-0x8] = rax = 0x28
0x0000555555555cea <+29>:    31 c0   xor    eax,eax
0x0000555555555cec <+31>:    48 8b 45 d8     mov    rax,QWORD PTR [rbp-0x28]
rax = ptr
0x0000555555555cf0 <+35>:    48 89 c7        mov    rdi,rax
rdi = ptr;
0x0000555555555cf3 <+38>:    e8 d1 f8 ff ff  call   0x5555555555c9 <string_length>

0x0000555555555cf8 <+43>:    89 45 ec        mov    DWORD PTR [rbp-0x14],eax
length = [-0x14] ;
0x0000555555555cfb <+46>:    83 7d ec 06     cmp    DWORD PTR [rbp-0x14],0x6
if length == 6
0x0000555555555cff <+50>:    74 05   je     0x555555555d06 <phase_5+57>
0x0000555555555d01 <+52>:    e8 f8 fb ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555d06 <+57>:    c7 45 e8 00 00 00 00    mov    DWORD PTR [rbp-0x18],0x0
int i = [-0x18] = 0;
0x0000555555555d0d <+64>:    eb 30   jmp    0x555555555d3f <phase_5+114>
0x0000555555555d0f <+66>:    8b 45 e8        mov    eax,DWORD PTR [rbp-0x18]
eax = i;
0x0000555555555d12 <+69>:    48 63 d0        movsxd rdx,eax
rdx = eax = i;
0x0000555555555d15 <+72>:    48 8b 45 d8     mov    rax,QWORD PTR [rbp-0x28]
rax = ptr;
0x0000555555555d19 <+76>:    48 01 d0        add    rax,rdx
rax += rdx = ptr + i;
0x0000555555555d1c <+79>:    0f b6 00        movzx  eax,BYTE PTR [rax]
eax = string[ptr+i];
0x0000555555555d1f <+82>:    0f be c0        movsx  eax,al
0x0000555555555d22 <+85>:    83 e0 0f        and    eax,0xf
eax &= 0xf;
0x0000555555555d25 <+88>:    48 98   cdqe
eax 扩展 
0x0000555555555d27 <+90>:    48 8d 15 12 38 00 00    lea    rdx,[rip+0x3812]        # 0x555555559540 <array.3096>
rdx = 0x555555559540
 = ['m', 'a', 'd', 'u', 
    'i', 'e', 'r', 's',
    'n', 'f', 'o', 't',
    'v', 'b', 'y', 'l']
0x0000555555555d2e <+97>:    0f b6 14 10     movzx  edx,BYTE PTR [rax+rdx*1]
edx = [rdx + rax] = array[char[ptr+i]&0xf] 
0x0000555555555d32 <+101>:   8b 45 e8        mov    eax,DWORD PTR [rbp-0x18]
eax = i;
0x0000555555555d35 <+104>:   48 98   cdqe
0x0000555555555d37 <+106>:   88 54 05 f1     mov    BYTE PTR [rbp+rax*1-0xf],dl
ans[i] = dl = array[char[ptr+i]&0xf] 
0x0000555555555d3b <+110>:   83 45 e8 01     add    DWORD PTR [rbp-0x18],0x1
i = i + 1;
0x0000555555555d3f <+114>:   83 7d e8 05     cmp    DWORD PTR [rbp-0x18],0x5
if i <= 5
0x0000555555555d43 <+118>:   7e ca   jle    0x555555555d0f <phase_5+66>
0x0000555555555d45 <+120>:   c6 45 f7 00     mov    BYTE PTR [rbp-0x9],0x0
end = 0;
0x0000555555555d49 <+124>:   48 8d 45 f1     lea    rax,[rbp-0xf]
char * rax = ans 
0x0000555555555d4d <+128>:   48 8d 35 10 16 00 00    lea    rsi,[rip+0x1610]        # 0x555555557364
[b, r, u, i, n, s]
0x0000555555555d54 <+135>:   48 89 c7        mov    rdi,rax

0x0000555555555d57 <+138>:   e8 a3 f8 ff ff  call   0x5555555555ff <strings_not_equal>
0x0000555555555d5c <+143>:   85 c0   test   eax,eax
0x0000555555555d5e <+145>:   74 05   je     0x555555555d65 <phase_5+152>
0x0000555555555d60 <+147>:   e8 99 fb ff ff  call   0x5555555558fe <explode_bomb>
0x0000555555555d65 <+152>:   90      nop
0x0000555555555d66 <+153>:   48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
0x0000555555555d6a <+157>:   64 48 33 04 25 28 00 00 00      xor    rax,QWORD PTR fs:0x28
0x0000555555555d73 <+166>:   74 05   je     0x555555555d7a <phase_5+173>
0x0000555555555d75 <+168>:   e8 d6 f3 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
0x0000555555555d7a <+173>:   c9      leave
0x0000555555555d7b <+174>:   c3      ret


= ['m', 'a', 'd', 'u', 
    'i', 'e', 'r', 's',
    'n', 'f', 'o', 't',
    'v', 'b', 'y', 'l']

    [b, r, u, i, n, s]
    m, f/v, c/s, d/t, h/x, g/w
    mfcdhg
a 0001 a
b 0010 d
c 0011 u
d 0100 i
e 0101 e
f 0110 r
g 0111 s
h 1000 n
i 1001 f
j 1010 o
k 1011 t
l 1100 v

m 1101 b
n 1110 y
o 1111 l
p 0000 m
q 0001 a
r 0010 d
s 0011 u
t 0100 i
u 0101 e
v 0110 r
w 0111 s
x 1000 n
y 1001 f
z 1010 o