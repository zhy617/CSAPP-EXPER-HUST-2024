0:   f3 0f 1e fa             endbr64 
4:   55                      push   %rbp
5:   48 89 e5                mov    %rsp,%rbp
8:   48 83 ec 10             sub    $0x10,%rsp
c:   89 7d fc                mov    %edi,-0x4(%rbp)
f:   8b 45 fc                mov    -0x4(%rbp),%eax
12:   48 98                   cltq   
14:   48 8d 15 00 00 00 00    lea    0x0(%rip),%rdx        # 1b <do_phase+0x1b>
1b:   48 01 d0                add    %rdx,%rax
1e:   48 89 c6                mov    %rax,%rsi
21:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 28 <do_phase+0x28>
28:   b8 00 00 00 00          mov    $0x0,%eax
2d:   e8 00 00 00 00          call   32 <do_phase+0x32>
32:   90                      nop
33:   c9                      leave  
34:   c3                      ret

rdx = do+0x1b
rdx = do+0x1b+rax

