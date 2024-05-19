main
        (gdb) i reg rax
        rax            0x7fffffffde1c      140737488346652
        (gdb) i reg rbp
        rbp            0x7fffffffde30      0x7fffffffde30

Breakpoint 3, 0x00000000004013e2 in do_phase ()
(gdb) i reg rbp
rbp            0x7fffffffddf0      0x7fffffffddf0

df0 = 3568
e1c = 3612 

rax - rbp = 44d = 0x2c

0000000000000000 <.text>:
   0:   48 89 ef                mov    %rbp,%rdi
   3:   48 83 c7 2c             add    $0x2c,%rdi

48 89 ef 
48 83 c7 2c
e8 92 ff ff ff 

0 - 6d = 0 - 109 = 4294967187 = ffff ff93