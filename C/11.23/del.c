#include <stdio.h>
#include <string.h>

void del(char a[]){
    int i,p;
    for( i=0,p=0; i<strlen(a); i++){
        if( a[i]== ' '){
            continue;
        }
        a[p] = a[i];
        p++;
    }
    a[p] = '\0';
}