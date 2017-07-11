#include<stdio.h>
int main(){
    int ch;
    int at_begining=1;
    int line=1;
    while((ch=getchar())!=EOF){
        if(at_begining==1){
            printf("%d: ",line);
            line++;
            at_begining=0;
        }
        putchar(ch);
        if(ch=='\n'){
            at_begining=1;
        }

    }
    return 0;
}
