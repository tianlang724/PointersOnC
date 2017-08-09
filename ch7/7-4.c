#include<stdio.h>
#include<stdarg.h>
int max_of_list(int n_value, ...){
    va_list var_arg;
    int count;
    int max=0;
    int temp;
    va_start(var_arg,n_value);
    for(count=0;count<n_value;count++){
        if((temp=va_arg(var_arg,int))>max){
            max=temp;
        }
    }
    va_end(var_arg);
    return max;
}
int max_of_list2(int num, ...){
    va_list var_arg;
    int temp;
    int max=0;
    va_start(var_arg,num);
    max=num;
    while((temp=va_arg(var_arg,int))!=-1){
        if(temp>max){
            max=temp;
        }
    }
    va_end(var_arg);
    return max;
}
void main(){
    printf("max=%d\n",max_of_list2(2,4,10,5,20,3,21,5,-1));
}
