#include <stdio.h>
int main()
{
    //  ��ʼ��
    int a = 0;
    int n = 0;
    //  ��ȡ����
    printf("������Ҫ��������֣�");
    scanf("%d",&a);
    //  ����
    
   do{
    a /= 10;
    n++;
   }while(a>0);
    printf("������Ϊ%dλ��\n",n);
    return 0;
}