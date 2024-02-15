#include<stdio.h>
#include "input.c"
#include "del.c"
#include "out.c"

int main(){
    char a[10000] = ""; 

    input(a);
    del(a);
    out(a);

    return 0;
}