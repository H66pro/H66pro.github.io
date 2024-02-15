#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(){
    int number, i;
    int *p=0;
    p = &i;
    
    while( (p = malloc(1024*1024))){
        i ++;
    }
    printf("%gGB",i/1024.0);
    // Sleep(600);
    free(p);

    return 0;
}