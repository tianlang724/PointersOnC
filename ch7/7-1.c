#include<stdio.h>
int hermite(int n,int x){
    int ppre=1;
    int pre=2*x;
    int ret;
    if(n<=0)
        return ppre;
    if(n==1)
        return pre;
    while(n>=2){
        ret=2*x*pre-2*(n-1)*ppre;
        ppre=pre;
        pre=ret;
        n--;
    }
    return ret;
}
int main(){
   printf("h(3,2)=%d\n",hermite(3,2));
}
