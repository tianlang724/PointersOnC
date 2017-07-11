#include<stdio.h>
int main(){
    char checksum=-1;
    char ch;
    while((ch=getchar())!='\n'){
        putchar(ch);
        checksum+=ch;
    }
    printf("\n");
    checksum+='\n';
    printf("%d\n",checksum);
    return 0;
}
