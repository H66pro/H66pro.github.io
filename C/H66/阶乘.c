#include <stdio.h>
int main()
{
	int into = 0;	//	����ֵ
	int i;	
	int out = 1;	//	���ֵ

	scanf("%d",&into);

	for( i=1; i<=into; i++){
		out *= i; 
	}
	
	printf("%d! = %d\n",into,out);
	
	return 0;
 } 
