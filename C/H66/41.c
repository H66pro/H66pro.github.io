#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    char *lan[] = {"fortran","basic", "pascal", "sava","c"};
    // printf("%p\n",lan+2);
    printf("%s\n",lan[2]);
    int a[6][6]={
        {0,0,0,0,0,0},{0,1,1,1,1,1},
    }
    
    return 0;
}