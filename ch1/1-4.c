#include<stdio.h>
#include<string.h>
int main(){
    char maxline[1000];
    char line[1000];
    int maxlen=0;
    int templen;
    while(gets(line)!=NULL){
        if(strlen(line)>maxlen){
            strcpy(maxline,line);
            maxlen=strlen(line);
        }
    }
    printf("%s\n",maxline);
}
