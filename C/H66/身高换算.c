#include <stdio.h>
int main()
{
	double foot;
	double inch;
	
	printf("������������ߣ�Ӣ�ƣ�\n""������\"5 7\"��ʾ5Ӣ��7Ӣ��\n");
	scanf("%lf %lf",&foot,&inch);
	
	
	printf("�������Ϊ%f��\n", (foot + inch / 12.0) * 0.3048);

	return 0;
 } 
