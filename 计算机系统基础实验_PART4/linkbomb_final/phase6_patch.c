#include<stdio.h>
long long myprint = 0x4013bf;
void print_id(){
    printf("U202210755\n");
}

/*

gcc -no-pie -o linkbomb6 main.o phase6.o phase6_patch.c

*/