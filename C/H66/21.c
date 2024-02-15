#include <stdio.h>
#include <stdlib.h>



int main(){
    void *p;
    int num=6;
    p = malloc(num * sizeof(int));

    free(p);
    return 0;
}