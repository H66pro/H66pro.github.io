#include <stdio.h>
int main(){
    int stu = 1000, z=100000;
    int sum=0,i,x;

    for( i=0; i<=stu && sum<=z; ){
        i++;
        scanf("%d",&x);
        sum += x;
    }
    printf("捐款人数为%d\n平均每人捐款%g元",i,sum/1.0/i);
    return 0;
}