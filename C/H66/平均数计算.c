#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int main()
{
    int num = 0;
    double ans = 0;
    int i = 0;
    printf("���������롰-1��\n");
    do{
        printf("������һ����Ȼ����");
        scanf("%d",&num);
        if(num > -1){
            ans += num;
            i++;
        }

    }while (num != -1);
    printf("��%d������ƽ����Ϊ%g",i,ans/i);
    
    return 0;
}