#include<stdio.h>
#include<string.h>
void my_do_arg(int ch,char *value){
    printf("process arg:%c",ch);
    if(value!=NULL){
        printf(" value is %s",value);
    }
    printf("\n");
}
void my_illegal_arg(int ch){
    printf("process illegral arg:%c\n",ch);
}
int checkarg(char *ctrl,char ch){
    int len=strlen(ctrl);
    for(int i=0;i<len;i++){
        if(ctrl[i]==ch){
            if(ctrl[i+1]=='+')
                return 2;
            else
                return 1;
        }
    }
    return 0;
}
char** do_args(int argc,char**argv,char *control,
        void (*do_arg)(int ch,char *value),
        void(*illegal_arg)(int ch)){
    int i=1;
    while(i<argc&&argv[i][0]=='-'){
        int j=1;
        while(j<strlen(argv[i])){
        int ret=checkarg(control,argv[i][j]);
        switch(ret){
            case 0:
                illegal_arg(argv[i][j]);
                break;
            case 1:
                do_arg(argv[i][j],NULL);
                break;
            case 2:
                if(argv[i][j+1]!='\0'){
                    do_arg(argv[i][j],&argv[i][j+1]);
                    j=strlen(argv[i]);
                }else if(argv[i+1]!=NULL){
                    do_arg(argv[i][j],argv[i+1]);
                    i++;
                }else{
                    illegal_arg(argv[i][j]);
                }
                break;
        }
        j++;
        }
        i++;
    }
    return &argv[i];
}
int main(int argc,char* argv[]){
    char ctrl[10];
    scanf("%s",ctrl);
    char** ret=do_args(argc,argv,ctrl,my_do_arg,my_illegal_arg);
}
