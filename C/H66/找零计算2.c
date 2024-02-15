#include <stdio.h>
int main()
{
    //  初始化
    int prise = 0;
    int money = 0;
    //  读取价格和金额
    printf("请输入商品价格：");
    scanf("%d",&prise);
    printf("请输入付款金额：");
    scanf("%d",&money);
    //  判断是否足额并输出
    if(money==prise)
        printf("祝您购物愉快\n");
    else if(money>prise)
            printf("找您%d元，祝您购物愉快\n",money-prise);
        else
            printf("您的付款金额不足，请重新付款\n");
        
    return 0;
} 