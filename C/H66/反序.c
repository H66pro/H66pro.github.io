#include <stdio.h>
#include <string.h>

void fan(char a[],int len);

int main(void){
    char a[1000];
    gets(a);
    int len = strlen(a);
    fan(a,len);
    puts(a);

    return 0;
}

void fan(char a[],int len){
    char b;
    int j = len-1;
    for(int i=0;i<j; i++,j--){
        b=a[i];
        a[i] = a[j];
        a[j] = b;
    }
}