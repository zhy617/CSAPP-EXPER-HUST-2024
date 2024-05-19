   0x0000555555555ab6 <+0>:     f3 0f 1e fa     endbr64
   0x0000555555555aba <+4>:     55      push   rbp
   0x0000555555555abb <+5>:     48 89 e5        mov    rbp,rsp
   0x0000555555555abe <+8>:     48 83 ec 30     sub    rsp,0x30
   0x0000555555555ac2 <+12>:    48 89 7d d8     mov    QWORD PTR [rbp-0x28],rdi
   ptr [-0x28] = rdi = char* = 0x555555559760 = 
   **char* 与机器指令之间的距离不变吗？**
   0x0000555555555ac6 <+16>:    64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28

   0x0000555555555acf <+25>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax
   0x0000555555555ad3 <+29>:    31 c0   xor    eax,eax

   0x0000555555555ad5 <+31>:    c7 45 f0 00 00 00 00    mov    DWORD PTR [rbp-0x10],0x0
   [-0x10] = 0
   0x0000555555555adc <+38>:    c7 45 f4 00 00 00 00    mov    DWORD PTR [rbp-0xc],0x0
   [-0xc] = 0
   0x0000555555555ae3 <+45>:    48 8d 4d ec     lea    rcx,[rbp-0x14]
   rcx = -0x14 地址
   0x0000555555555ae7 <+49>:    48 8d 55 e8     lea    rdx,[rbp-0x18]
   rdx = -0x18 地址
   0x0000555555555aeb <+53>:    48 8b 45 d8     mov    rax,QWORD PTR [rbp-0x28]
   rax = [-0x28] = char* = 0x555555559760
   0x0000555555555aef <+57>:    48 8d 35 46 18 00 00    lea    rsi,[rip+0x1846]        # 0x55555555733c
   **rip+0x1846**
   rsi = 0x25    0x64    0x20    0x25    0x64    0x00    0x00    0x00    0xf8    0xe7    0xff    0xff    0x01    0xe8    0xff    0xff
       = &("%d %d")
   0x0000555555555af6 <+64>:    48 89 c7        mov    rdi,rax
   rdi = rax = char* = input = 0x555555559760
   0x0000555555555af9 <+67>:    b8 00 00 00 00  mov    eax,0x0
   eax = 0
   0x0000555555555afe <+72>:    e8 9d f6 ff ff  call   0x5555555551a0 <__isoc99_sscanf@plt>
   0x0000555555555b03 <+77>:    89 45 f4        mov    DWORD PTR [rbp-0xc],eax
   [-0xc] = eax = Count
   0x0000555555555b06 <+80>:    83 7d f4 01     cmp    DWORD PTR [rbp-0xc],0x1
   if Count > 1
   0x0000555555555b0a <+84>:    7f 05   jg     0x555555555b11 <phase_3+91>
   0x0000555555555b0c <+86>:    e8 ed fd ff ff  call   0x5555555558fe <explode_bomb>
   读入少了报错
   0x0000555555555b11 <+91>:    8b 45 e8        mov    eax,DWORD PTR [rbp-0x18]
   **eax = (int)[-0x18] = num1? 确实是num1**
   0x0000555555555b14 <+94>:    83 f8 07        cmp    eax,0x7
    if(eax > unsigned 7)
   0x0000555555555b17 <+97>:    77 6b   ja     0x555555555b84 <phase_3+206>
   无符号大于则跳转
   0x0000555555555b19 <+99>:    89 c0   mov    eax,eax 
   **test? eax < 0**
   0x0000555555555b1b <+101>:   48 8d 14 85 00 00 00 00 lea    rdx,[rax*4+0x0]
   rdx = rax*4 + 0 = 4*num1
   0x0000555555555b23 <+109>:   48 8d 05 1a 18 00 00    lea    rax,[rip+0x181a]        # 0x555555557344
   *rax = 0x555555557344

   = 4294961144, 4294961153, 4294961162, 4294961171
   = -6152, -6143, -6134, -6125,-6116, -6107

   0x555555557344: 0xf8    0xe7    0xff    0xff    0x01    0xe8    0xff    0xff = 
   0x55555555734c: 0x0a    0xe8    0xff    0xff    0x13    0xe8    0xff    0xff
   0x555555557354: 0x1c    0xe8    0xff    0xff    0x25    0xe8    0xff    0xff
   0x55555555735c: 0x2e    0xe8    0xff    0xff    0x37    0xe8    0xff    0xff
   0x555555557364: 0x62    0x72    0x75    0x69    0x6e    0x73    0x00    0x00
       
   0x0000555555555b2a <+116>:   8b 04 02        mov    eax,DWORD PTR [rdx+rax*1]
   eax = * (rdx + rax) = * (rdx + rax) = *(4*num1 + 0x55557344) = rax[num1];
   0x0000555555555b2d <+119>:   48 98   cdqe
   eax = (long long) eax;
   0x0000555555555b2f <+121>:   48 8d 15 0e 18 00 00    lea    rdx,[rip+0x180e]        # 0x555555557344
   rdx = 0x555555557344
   0x0000555555555b36 <+128>:   48 01 d0        add    rax,rdx
   rax += rdx;
   rax = rax + rdx = 0x555555557344 - 6152 + 9*num1 = 0x 5555555555B3C + 9 *num1

   0x0000555555555b39 <+131>:   3e ff e0        notrack jmp rax
   0x0000555555555b3c <+134>:   c7 45 f0 2f 03 00 00    mov    DWORD PTR [rbp-0x10],0x32f
   815
   0x0000555555555b43 <+141>:   eb 44   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b45 <+143>:   c7 45 f0 30 01 00 00    mov    DWORD PTR [rbp-0x10],0x130
   304
   0x0000555555555b4c <+150>:   eb 3b   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b4e <+152>:   c7 45 f0 84 01 00 00    mov    DWORD PTR [rbp-0x10],0x184
   388
   0x0000555555555b55 <+159>:   eb 32   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b57 <+161>:   c7 45 f0 8e 02 00 00    mov    DWORD PTR [rbp-0x10],0x28e
    654
   0x0000555555555b5e <+168>:   eb 29   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b60 <+170>:   c7 45 f0 1c 01 00 00    mov    DWORD PTR [rbp-0x10],0x11c
   284
   0x0000555555555b67 <+177>:   eb 20   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b69 <+179>:   c7 45 f0 01 02 00 00    mov    DWORD PTR [rbp-0x10],0x201
   513
   0x0000555555555b70 <+186>:   eb 17   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b72 <+188>:   c7 45 f0 a9 01 00 00    mov    DWORD PTR [rbp-0x10],0x1a9
   425
   0x0000555555555b79 <+195>:   eb 0e   jmp    0x555555555b89 <phase_3+211>
   0x0000555555555b7b <+197>:   c7 45 f0 74 03 00 00    mov    DWORD PTR [rbp-0x10],0x374
   884
   0x0000555555555b82 <+204>:   eb 05   jmp    0x555555555b89 <phase_3+211>


   0x0000555555555b84 <+206>:   e8 75 fd ff ff  call   0x5555555558fe <explode_bomb>
   [-0x18]>7则爆炸
   0x0000555555555b89 <+211>:   8b 45 ec        mov    eax,DWORD PTR [rbp-0x14]
   eax = [-0x14] = num2?
   0x0000555555555b8c <+214>:   39 45 f0        cmp    DWORD PTR [rbp-0x10],eax
   eax == [-0x10]
   0x0000555555555b8f <+217>:   74 05   je     0x555555555b96 <phase_3+224>
   0x0000555555555b91 <+219>:   e8 68 fd ff ff  call   0x5555555558fe <explode_bomb>
   0x0000555555555b96 <+224>:   90      nop
   0x0000555555555b97 <+225>:   48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
   rax = [-0x8]
   0x0000555555555b9b <+229>:   64 48 33 04 25 28 00 00 00      xor    rax,QWORD PTR fs:0x28
   0x0000555555555ba4 <+238>:   74 05   je     0x555555555bab <phase_3+245>
   0x0000555555555ba6 <+240>:   e8 a5 f5 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
   0x0000555555555bab <+245>:   c9      leave
   0x0000555555555bac <+246>:   c3      ret


   0 815
   1 304
   2 388
   3 654
   4 284
   5 513
   6 425
   7 884