#include <stdio.h>
int main()
{
 int j = 1;
 int i = 1;
 int ret = 1;
 int sum = 0;
    for (j = 1;j <= 3;j++)
    {
        ret = 1;
        for ( i = 1; i <= j; i++){
            ret = ret * i;
        }
        sum = sum + ret;
    }
    printf("%d\n", sum);
 return 0;
}