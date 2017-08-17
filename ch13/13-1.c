#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int is_not_print(int ch){
    return !isprint(ch);
}
int (*char_add[])(int ch)={iscntrl,isgraph,isdigit,islower,isupper,ispunct,is_not_print};
int main(){
    int  ch;
    double num[7]={0};
    int count=0;
    while( (ch=getchar()) !=EOF){
        count++;
        for(int i=0;i<7;i++){
            if(char_add[i](ch))
                num[i]++;
        }
    }
    for(int i=0;i<7;i++){
        num[i]/=count;
    }
    printf("ctrl=%f,graph=%f,digit=%f,lower=%f,upper=%f,punct=%f,noprint=%f",num[0],
            num[1],num[2],num[3],num[4],num[5],num[6]);
}
