#include<stdio.h>
int assic_to_integer(char * string){
    int ret=0;
    while(*string!='\0'){
        if(*string>='0'&&*string<='9'){
            ret=ret*10+*string-'0';
        }else{
            return 0;
        }
        string++;
    }
    return ret;
}
int main(){
    char test[20];
    scanf("%s",test);
    printf("num=%d\n",assic_to_integer(test));
}
