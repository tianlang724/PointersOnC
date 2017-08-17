#include<stdio.h>
#include<ctype.h>
int main(int argc,char *argv[]){
    FILE *f;
    if(argc<=1){
        f=stdin;
    }else{
        f=fopen(argv[1],"r");
        if(f==NULL){
            printf("open file error\n");
            return 0;
        }
    }
    char  tempCh[17];
    int  ch;
    while(1){
        printf("%06X ",ftell(f));
        int i;
        for(i=0;i<16;i++){
            if((ch=getc(f))==EOF)
                break;
            printf("%02X",ch);
            if(isprint(ch)||ch!=' '){
                tempCh[i]=ch;
            }else{
                tempCh[i]='.';
            }
            if(i%4==3)
                printf(" ");
        }
        tempCh[i]='\0';
        printf("*");
        printf("%s",tempCh);
        printf("*\n");
        if(i<16)
            break;
    }
}
