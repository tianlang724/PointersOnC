#include<stdio.h>
#include<string.h>
int format(char * format_string,char const *src){
    int ret=1;
    if(strlen(src)==0)
        ret=0;
    char * dest=format_string;
    char const *tsrc=src;
    while(*dest!='\0')
        dest++;
    dest--;
    while(*tsrc!='\0')
        tsrc++;
    tsrc--;
    while(dest!=format_string&&tsrc!=src){
        if(*dest=='#'){
            *dest=*tsrc;
            dest--;
            tsrc--;
        }else if(*dest==','||*dest=='.'){
            dest--;
        }
    }
    while(dest!=format_string){

    }

}
