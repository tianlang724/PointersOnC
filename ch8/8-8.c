/*******
 *八皇后问题，很有意思
 *回溯的方法很神奇
 *
 * ***********/
#include<stdio.h>
int queue[8][8]={0};
int count=1;
void printfqueue(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d ",queue[i][j]);
        }
        printf("\n");
    }
}
int check(int x,int y){
    for(int i=0;i<8;i++){
        if(queue[i][y]==1||queue[x][i]==1)
            return 0;
    }
    for(int i=0;(x+i<8)&&(y+i<8);i++){
            if(queue[x+i][y+i]==1)
                return 0;
     }

    for(int i=0;(x-i>=0)&&(y-i>=0);i++){
            if(queue[x-i][y-i]==1)
                return 0;
     }
    for(int i=0;(x+i<8)&&(y-i>=0);i++){
            if(queue[x+i][y-i]==1)
                return 0;
     }
    for(int i=0;(x-i>=0)&&(y+i<8);i++){
            if(queue[x-i][y+i]==1)
                return 0;
     }
     return 1;
}
void solve(int i){
        for(int j=0;j<8;j++){
            if(check(i,j)==1){
                queue[i][j]=1;
                if(i+1<8)
                    solve(i+1);
                else{
                    printf("solution %d:\n",count++);
                    printfqueue();
                }
            }
            queue[i][j]=0;//此处回溯，需要细细品味
        }

}
void main(){
  solve(0);
 // printfqueue();
}
