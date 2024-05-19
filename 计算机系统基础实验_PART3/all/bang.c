int p=0;//&p = 0x4014
int main(){
    *((int*)0x4014) = 0xc0d7dc3;
    return 0;
}