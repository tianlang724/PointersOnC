#include<stdio.h>
#include<stdarg.h>
int myprintf(char* string,...){
    va_list arg;
    va_start(arg,string);
    char *ch=string,*temp;
    for(;*ch!='\0';ch++){
        if(*ch=='%'){
            ch++;
            switch(*ch){
            case 'd':
                printf("%d",va_arg(arg,int));
                break;
            case 'f':
                printf("%f",va_arg(arg,double));
                break;
            case 'c':
                putchar(va_arg(arg,int));
                break;
            case 's':
                temp=va_arg(arg,char *);
                for(;*temp!='\0';temp++)
                    putchar(*temp);
                break;
            }
        }else{
            putchar(*ch);
        }
    }
}
void main(){
    myprintf("abcd%d,%f,%s,%c\n",5,3.14,"i love you",'.');
}
