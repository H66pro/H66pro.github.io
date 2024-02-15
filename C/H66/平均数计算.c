#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int main()
{
    int num = 0;
    double ans = 0;
    int i = 0;
    printf("结束请输入“-1”\n");
    do{
        printf("请输入一个自然数：");
        scanf("%d",&num);
        if(num > -1){
            ans += num;
            i++;
        }

    }while (num != -1);
    printf("这%d个数的平均数为%g",i,ans/i);
    
    return 0;
}