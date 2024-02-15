#include <stdio.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;

    printf("请输入两个时刻\n");
    scanf("%d:%d %d:%d",&hour1,&minute1,&hour2,&minute2);

    int ih = hour2 - hour1;
    int im = minute2 - minute1;
    if ( im<0 ) {
        im +=60;
        ih --;
    }

    printf("时间差为%d小时%d分钟\n",ih,im);
    return 0;
}
