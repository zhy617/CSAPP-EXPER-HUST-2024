

把rsp减去16，给传参预留空间

   0x00000000000019fc <+0>:     f3 0f 1e fa     endbr64
   0x0000000000001a00 <+4>:     55      push   rbp
   把rbp保存下来
   0x0000000000001a01 <+5>:     48 89 e5        mov    rbp,rsp
   把rsp赋值给新的rbp，当作新的基址
   0x0000000000001a04 <+8>:     48 83 ec 10     sub    rsp,0x10
   把rsp减去16，给传参预留空间
   0x0000000000001a08 <+12>:    48 89 7d f8     mov    QWORD PTR [rbp-0x8],rdi
   把rdi 64位 移到rbp-8字节所指的地方
   0x0000000000001a0c <+16>:    48 8b 45 f8     mov    rax,QWORD PTR [rbp-0x8]
   把rbp-8移到rax里
   0x0000000000001a10 <+20>:    48 8d 35 01 19 00 00    lea    rsi,[rip+0x1901]        # 0x3318
   静态变量是rip + 相对地址
   0x0000000000001a17 <+27>:    48 89 c7        mov    rdi,rax
   可知是rdi和rsi之间比较
   0x0000000000001a1a <+30>:    e8 e0 fb ff ff  call   0x15ff <strings_not_equal>
   0x0000000000001a1f <+35>:    85 c0   test   eax,eax
   0x0000000000001a21 <+37>:    74 05   je     0x1a28 <phase_1+44>
   0x0000000000001a23 <+39>:    e8 d6 fe ff ff  call   0x18fe <explode_bomb>
   0x0000000000001a28 <+44>:    90      nop
   0x0000000000001a29 <+45>:    c9      leave
   0x0000000000001a2a <+46>:    c3      ret

The future will be better tomorrow.