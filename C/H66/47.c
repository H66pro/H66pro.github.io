#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 函数int_to_str的功能是将参数n中的整数转换成字符串，存入s指内存中 */
void int_to_str(int n,char *s)
{
    sprintf(s,"%d",n);	
}

char  *fun(int x[], int n)
{
    static char str[200],s[10];
    int i;
    *str = 0;
    /* 请在这里填入你编写的代码*/
	int b = 0, j=0, k=0;
	for( i=0; i<n; i++){
		j = 0;
		b = x[i];
		if( b%2!=0){
			continue;
		}
		s[j++] = '.';
		do{	
			s[j++] = b%10 + '0';
			b /= 10;
		}while( b!=0);
		for( j-=1; j>=0;j--){
			str[k++] = s[j];
		}
	}

    return str;
}

int main()
{
    void NONO();
    int x[] = {1,4,19,82,61,2};
    printf("str=%s\n", fun(x, 6));
    NONO();
    return 0;
}

void NONO()
{
    int i;
    int x[10][20] = {{11,5,6,8,9,18,54},{1,4,19,82,61,2},
    {87,78,54,32},{9,1,2,3,4,67,8,12},
    {91,12,33,55,66},{9,7,8,5,6,4,3,2,1,12},
    {12,13,14,15,11,16,17,18},{21,23,22,24,25,26,27,28,29},
    {33,32,31,41,42,43,51,42,53,54,66},{71,72,81,82,91,92}};
    int y[10] ={7,6,4,8,5,10,8,9,11,6};
    FILE *fp;

    fp = fopen("out.dat","w") ;
    for(i = 0; i< 10; i++)
        fprintf(fp, "str=%s\n", fun(x[i], y[i]));
  fclose(fp);

}

