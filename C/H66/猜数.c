#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int a;
    int num = rand()%100;
    int count = 0;
    printf("���������һ����������Ȼ��������һ�����Ĵ�С\n");
    printf("%d",num);
    // do{
    //     printf("������\n");
    //     scanf("%d",&a);
    //     count++;
    //     if(a>num){
    //         printf("��µ�����̫���ˣ�\n");
    //     }else if(a<num){
    //         printf("��µ�����̫С�ˣ�\n");
    //     }else if(a==num){
    //         printf("�����ڲ¶��ˣ�\n������%d��\n",count);
    //     }
    // }while(a!=num);
    // printf("��Ϸ����\n");
    return 0;
}