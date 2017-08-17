#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char buf[100];
    char *ret;
 //   while(gets(buf)!=NULL){
    while(fgets(stdin,100,buf)){
        char* age;
        int total=0;
        int pernum=0;
        for(age=strtok(buf," ");age!=NULL;age=strtok(NULL," ")){
            int num=atoi(age);
            total+=num;
            pernum++;
        }
        float average=(int)total/pernum;
        printf("%5.2f",average);
    }
}
