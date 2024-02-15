#include <stdio.h>
int main()
{
	int price = 0;
	int amount = 100;
	
	printf("支付金额/元\n");
	scanf("%d",&amount);
	
	printf("请输入价格/元\n");
	scanf("%d",&price);
	
	int change =  amount - price; 
	
	printf("找零%d元",change);
	
	return 0; 
}

 
