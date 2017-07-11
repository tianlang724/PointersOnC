#include<stdio.h>
int main(){
    int num;
    float pre=0;
    float now;
    scanf("%d",&num);
    now=1;
    while(now!=pre){
        pre=now;
        now=(now+num/now)/2;
    }
    printf("%d 的平方根是 %f\n",num,now);
    return 0;
}
