#include <stdio.h>

int main(int argc, char argv[])
{
    int num;
    printf("%d%n%d\n",123,&num,456);
    
    printf("%d\n",num);

    return 0;
}