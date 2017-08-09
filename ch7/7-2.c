#include<stdio.h>
int gcd(int m,int n){
    int ret;
    while((ret=m%n)>0){
        m=n;
        n=ret;
    }
    return n;
}
int main(){
    printf("(81,18)=%d\n",gcd(81,18));
    printf("(32,18)=%d\n",gcd(32,18));
}
