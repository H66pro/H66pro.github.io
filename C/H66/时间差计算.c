#include <stdio.h>
int main()
{
    int hour1,minute1;
    int hour2,minute2;

    printf("����������ʱ��\n");
    scanf("%d:%d %d:%d",&hour1,&minute1,&hour2,&minute2);

    int ih = hour2 - hour1;
    int im = minute2 - minute1;
    if ( im<0 ) {
        im +=60;
        ih --;
    }

    printf("ʱ���Ϊ%dСʱ%d����\n",ih,im);
    return 0;
}
