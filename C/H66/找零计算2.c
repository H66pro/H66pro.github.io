#include <stdio.h>
int main()
{
    //  ��ʼ��
    int prise = 0;
    int money = 0;
    //  ��ȡ�۸�ͽ��
    printf("��������Ʒ�۸�");
    scanf("%d",&prise);
    printf("�����븶���");
    scanf("%d",&money);
    //  �ж��Ƿ������
    if(money==prise)
        printf("ף���������\n");
    else if(money>prise)
            printf("����%dԪ��ף���������\n",money-prise);
        else
            printf("���ĸ�����㣬�����¸���\n");
        
    return 0;
} 