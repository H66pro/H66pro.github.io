#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int a;
    int num = rand()%100;
    int count = 0;
    printf("已随机生成一个百以内自然数，来猜一猜它的大小\n");
    printf("%d",num);
    // do{
    //     printf("请输入\n");
    //     scanf("%d",&a);
    //     count++;
    //     if(a>num){
    //         printf("你猜的数字太大了！\n");
    //     }else if(a<num){
    //         printf("你猜的数字太小了！\n");
    //     }else if(a==num){
    //         printf("你终于猜对了！\n共猜了%d次\n",count);
    //     }
    // }while(a!=num);
    // printf("游戏结束\n");
    return 0;
}