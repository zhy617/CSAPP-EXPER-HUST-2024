char *Gets(char *dest, char *src, int len)
{
    memcpy(dest,src,len);
    return dest;
}

int getbuf(char *src, int len)
{
    char buf[NORMAL_BUFFER_SIZE=32];
    Gets(buf,src,len);
    return 1;
}


smoke 首地址： 0x00000000004013e8

getbuf 首地址 0x0000000000401d5d

./bufbomb U202210755 string1.txt 0

gdb bufbomb U202210755 string1.txt 0
bufbomb U202210755 string1.txt 0


getbuf
0x0000000000401d5d <+0>:     f3 0f 1e fa     endbr64
0x0000000000401d61 <+4>:     55      push   rbp
0x0000000000401d62 <+5>:     48 89 e5        mov    rbp,rsp
0x0000000000401d65 <+8>:     48 83 ec 30     sub    rsp,0x30
0x0000000000401d69 <+12>:    48 89 7d d8     mov    QWORD PTR [rbp-0x28],rdi
0x0000000000401d6d <+16>:    89 75 d4        mov    DWORD PTR [rbp-0x2c],esi

120         char buf[NORMAL_BUFFER_SIZE];
121         Gets(buf,src,len);
0x0000000000401d70 <+19>:    8b 55 d4        mov    edx,DWORD PTR [rbp-0x2c]
0x0000000000401d73 <+22>:    48 8b 4d d8     mov    rcx,QWORD PTR [rbp-0x28]
0x0000000000401d77 <+26>:    48 8d 45 e0     lea    rax,[rbp-0x20]固定
0x0000000000401d7b <+30>:    48 89 ce        mov    rsi,rcx
0x0000000000401d7e <+33>:    48 89 c7        mov    rdi,rax
0x0000000000401d81 <+36>:    e8 b2 f9 ff ff  call   0x401738 <Gets>

122         return 1;
0x0000000000401d86 <+41>:    b8 01 00 00 00  mov    eax,0x1

123     }
0x0000000000401d8b <+46>:    c9      leave
0x0000000000401d8c <+47>:    c3      ret

ret 值
上一个 rbp 的值 

返回前：
rbp = 0x7fffffffdff0
rbp-0x20 = 0x7fffffffdfd0
rsp = 0x7fffffffdfc0

查看可知从0x7fffffffdfd0开始存

查看 f7fff7e08d27

返回后
rbp = 

rsp = 0x7fffffffe000