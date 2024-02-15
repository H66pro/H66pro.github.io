#include <stdio.h>
int main()
{
    //  初始化
    int a = 0;
    int n = 0;
    //  读取数字
    printf("请输入要计算的数字：");
    scanf("%d",&a);
    //  计算
    
   do{
    a /= 10;
    n++;
   }while(a>0);
    printf("该数字为%d位数\n",n);
    return 0;
}