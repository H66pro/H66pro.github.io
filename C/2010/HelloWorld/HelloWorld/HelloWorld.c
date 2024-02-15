#include <stdio.h>
#include <conio.h>

int main( int argc, char argv[])
{
	int c;
	printf("请输入密码：\n");
	c = getch();
	printf("输入的密码为：%d\n",c);
	getch();
	return 0;
}