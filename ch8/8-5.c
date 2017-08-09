#include<stdio.h>
void matrix_mul(int*m1,int* m2,int *r,int x,int y,int z){
    for(int i=0;i<x;i++){
        for(int j=0;j<z;j++){
           *(r+i*z+j)=0;
            for(int k=0;k<y;k++){
              *(r+i*z+j)+=*(m1+i*y+k)*(*(m2+k*z+j));
            }
        }
    }
}
void main(){
    int m1[]={2,-6,3,5,1,-1};
    int m2[]={4,-2,-4,-5,-7,-3,6,7};
    int r[12]={0};
    matrix_mul(m1,m2,r,3,2,4);
    for(int i=0;i<12;i++)
        printf("%d ",r[i]);
}
