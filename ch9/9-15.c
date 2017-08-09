#include<stdio.h>
#include<string.h>
void dollars(char *dest,char const *src){
    char const* tsrc=src;
    int len=strlen(src);
    if(len==0){
        strcpy(dest,"$0.00");
    }else if(len==1){
        strcpy(dest,"$0.0");
        strcat(dest,src);
    }else if(len==2){
        strcpy(dest,"$0.");
        strcat(dest,src);
    }
    int first=(len-2)%3;
    *dest='$';
    tsrc=src;
    if(first!=0){
        strncat(dest,tsrc,first);
        strncat(dest,",",1);
        tsrc+=first;
        len=len-first;
    }
    while(len>2){
        strncat(dest,tsrc,3);
        len=len-3;
        if(len>2){
            strncat(dest,",",1);
        }
        tsrc+=3;
    }
    strncat(dest,".",1);
    strncat(dest,tsrc,3);
}   
void main(){
    char dest[15]={0};
    dollars(dest,"1214151616");
    printf("%s=%s\n","1214151617",dest);
}
