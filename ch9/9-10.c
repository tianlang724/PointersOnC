#include<stdio.h>
#include<string.h>
#include<ctype.h>
int palindrom(char * string){
    char *begin=string;
    char *end=string;
    while(*end!='\0')
        end++;
    end--;
    while(begin<end){
        if(tolower(*begin)==tolower(*end)){
                begin++;
                end--;
        }else{
            return 0;
         }
    }
    return 1;
}
void main(){
    printf("%d\n",palindrom("abcCBA"));
    printf("%d\n",palindrom("abcCBAa"));
}
