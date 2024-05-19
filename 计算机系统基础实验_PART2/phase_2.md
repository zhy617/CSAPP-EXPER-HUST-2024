   0x0000555555555a2b <+0>:     f3 0f 1e fa     endbr64
   0x0000555555555a2f <+4>:     55      push   %rbp
   0x0000555555555a30 <+5>:     48 89 e5        mov    %rsp,%rbp
   0x0000555555555a33 <+8>:     48 83 ec 40     sub    $0x40,%rsp
   0x0000555555555a37 <+12>:    48 89 7d c8     mov    %rdi,-0x38(%rbp)
   0x0000555555555a3b <+16>:    64 48 8b 04 25 28 00 00 00      mov    %fs:0x28,%rax
   0x0000555555555a44 <+25>:    48 89 45 f8     mov    %rax,-0x8(%rbp)
   0x0000555555555a48 <+29>:    31 c0   xor    %eax,%eax
   0x0000555555555a4a <+31>:    48 8d 55 e0     lea    -0x20(%rbp),%rdx
   0x0000555555555a4e <+35>:    48 8b 45 c8     mov    -0x38(%rbp),%rax
   0x0000555555555a52 <+39>:    48 89 d6        mov    %rdx,%rsi
   0x0000555555555a55 <+42>:    48 89 c7        mov    %rax,%rdi
   0x0000555555555a58 <+45>:    e8 fd fa ff ff  call   0x55555555555a <read_six_numbers>
   0x0000555555555a5d <+50>:    8b 45 e0        mov    -0x20(%rbp),%eax
   0x0000555555555a60 <+53>:    85 c0   test   %eax,%eax
   0x0000555555555a62 <+55>:    79 05   jns    0x555555555a69 <phase_2+62>
   0x0000555555555a64 <+57>:    e8 95 fe ff ff  call   0x5555555558fe <explode_bomb>
   0x0000555555555a69 <+62>:    c7 45 dc 01 00 00 00    movl   $0x1,-0x24(%rbp)
   0x0000555555555a70 <+69>:    eb 27   jmp    0x555555555a99 <phase_2+110>
   0x0000555555555a72 <+71>:    8b 45 dc        mov    -0x24(%rbp),%eax
   0x0000555555555a75 <+74>:    48 98   cltq
   0x0000555555555a77 <+76>:    8b 54 85 e0     mov    -0x20(%rbp,%rax,4),%edx
   0x0000555555555a7b <+80>:    8b 45 dc        mov    -0x24(%rbp),%eax
   0x0000555555555a7e <+83>:    83 e8 01        sub    $0x1,%eax
   0x0000555555555a81 <+86>:    48 98   cltq
   0x0000555555555a83 <+88>:    8b 4c 85 e0     mov    -0x20(%rbp,%rax,4),%ecx
   0x0000555555555a87 <+92>:    8b 45 dc        mov    -0x24(%rbp),%eax
   0x0000555555555a8a <+95>:    01 c8   add    %ecx,%eax
   0x0000555555555a8c <+97>:    39 c2   cmp    %eax,%edx
   0x0000555555555a8e <+99>:    74 05   je     0x555555555a95 <phase_2+106>
   0x0000555555555a90 <+101>:   e8 69 fe ff ff  call   0x5555555558fe <explode_bomb>
   0x0000555555555a95 <+106>:   83 45 dc 01     addl   $0x1,-0x24(%rbp)
   0x0000555555555a99 <+110>:   83 7d dc 05     cmpl   $0x5,-0x24(%rbp)
   0x0000555555555a9d <+114>:   7e d3   jle    0x555555555a72 <phase_2+71>
   0x0000555555555a9f <+116>:   90      nop
   0x0000555555555aa0 <+117>:   48 8b 45 f8     mov    -0x8(%rbp),%rax
   0x0000555555555aa4 <+121>:   64 48 33 04 25 28 00 00 00      xor    %fs:0x28,%rax
   0x0000555555555aad <+130>:   74 05   je     0x555555555ab4 <phase_2+137>
   0x0000555555555aaf <+132>:   e8 9c f6 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
   0x0000555555555ab4 <+137>:   c9      leave
   0x0000555555555ab5 <+138>:   c3      ret


   0x0000555555555a2b <+0>:     f3 0f 1e fa     endbr64
   0x0000555555555a2f <+4>:     55      push   rbp
   0x0000555555555a30 <+5>:     48 89 e5        mov    rbp,rsp
   0x0000555555555a33 <+8>:     48 83 ec 40     sub    rsp,0x40
   rsp -= 0x40
   0x0000555555555a37 <+12>:    48 89 7d c8     mov    QWORD PTR [rbp-0x38],rdi
   0x0000555555555a3b <+16>:    64 48 8b 04 25 28 00 00 00      mov    rax,QWORD PTR fs:0x28
   0x0000555555555a44 <+25>:    48 89 45 f8     mov    QWORD PTR [rbp-0x8],rax
   0x0000555555555a48 <+29>:    31 c0   xor    eax,eax
   0x0000555555555a4a <+31>:    48 8d 55 e0     lea    rdx,[rbp-0x20]
   0x0000555555555a4e <+35>:    48 8b 45 c8     mov    rax,QWORD PTR [rbp-0x38]
   0x0000555555555a52 <+39>:    48 89 d6        mov    rsi,rdx
   rsi : int * 保存输入的6个数字的地址
   0x0000555555555a55 <+42>:    48 89 c7        mov    rdi,rax
   rdi : char* [rbp-0x38]
   0x0000555555555a58 <+45>:    e8 fd fa ff ff  call   0x55555555555a <read_six_numbers>
   0x0000555555555a5d <+50>:    8b 45 e0        mov    eax,DWORD PTR [rbp-0x20]
   0x0000555555555a60 <+53>:    85 c0   test   eax,eax
   0x0000555555555a62 <+55>:    79 05   jns    0x555555555a69 <phase_2+62>
   SF=0就跳
   0x0000555555555a64 <+57>:    e8 95 fe ff ff  call   0x5555555558fe <explode_bomb>
   0x0000555555555a69 <+62>:    c7 45 dc 01 00 00 00    mov    DWORD PTR [rbp-0x24],0x1
   i 置为 1
   0x0000555555555a70 <+69>:    eb 27   jmp    0x555555555a99 <phase_2+110>
    跳到110
   0x0000555555555a72 <+71>:    8b 45 dc        mov    eax,DWORD PTR [rbp-0x24]
   eax = (int) i
   0x0000555555555a75 <+74>:    48 98   cdqe
   CDQE复制EAX寄存器双字的符号位(bit 31)到RAX的高32位。
   0x0000555555555a77 <+76>:    8b 54 85 e0     mov    edx,DWORD PTR [rbp+rax*4-0x20]
   edx = [rbp + i*4- 0x20]
   0x0000555555555a7b <+80>:    8b 45 dc        mov    eax,DWORD PTR [rbp-0x24]
   eax = i
   0x0000555555555a7e <+83>:    83 e8 01        sub    eax,0x1
   eax -= 1
   0x0000555555555a81 <+86>:    48 98   cdqe
   CDQE复制EAX寄存器双字的符号位(bit 31)到RAX的高32位。
   0x0000555555555a83 <+88>:    8b 4c 85 e0     mov    ecx,DWORD PTR [rbp+rax*4-0x20]
   ecx = [rbp + rax*4 - 0x20] = [rbp + (i-1)*4 - 0x20]
   0x0000555555555a87 <+92>:    8b 45 dc        mov    eax,DWORD PTR [rbp-0x24]
   eax = i
   0x0000555555555a8a <+95>:    01 c8   add    eax,ecx
   eax += ecx = numbers[i]
   0x0000555555555a8c <+97>:    39 c2   cmp    edx,eax
   edx eax 比较
   0x0000555555555a8e <+99>:    74 05   je     0x555555555a95 <phase_2+106>

   0x0000555555555a90 <+101>:   e8 69 fe ff ff  call   0x5555555558fe <explode_bomb>
   0x0000555555555a95 <+106>:   83 45 dc 01     add    DWORD PTR [rbp-0x24],0x1
   i++
   0x0000555555555a99 <+110>:   83 7d dc 05     cmp    DWORD PTR [rbp-0x24],0x5
    和5比较
   0x0000555555555a9d <+114>:   7e d3   jle    0x555555555a72 <phase_2+71>
   跳回循环
   0x0000555555555a9f <+116>:   90      nop
   0x0000555555555aa0 <+117>:   48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
   0x0000555555555aa4 <+121>:   64 48 33 04 25 28 00 00 00      xor    rax,QWORD PTR fs:0x28
   0x0000555555555aad <+130>:   74 05   je     0x555555555ab4 <phase_2+137>
   0x0000555555555aaf <+132>:   e8 9c f6 ff ff  call   0x555555555150 <__stack_chk_fail@plt>
   0x0000555555555ab4 <+137>:   c9      leave
   0x0000555555555ab5 <+138>:   c3      ret

    i=1
    number[i] ==? number[i+1] + i
    number[1] ==? number[2] + 1


0 1 3 6 10 15