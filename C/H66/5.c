#include <stdio.h>
int main(){
    int stu = 1000, z=100000;
    int sum=0,i,x;

    for( i=0; i<=stu && sum<=z; ){
        i++;
        scanf("%d",&x);
        sum += x;
    }
    printf("�������Ϊ%d\nƽ��ÿ�˾��%gԪ",i,sum/1.0/i);
    return 0;
}