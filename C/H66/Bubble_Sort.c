#include <stdio.h>
#include<string.h>
void Bubble(char a[],int len);
int main (){
    char a[11] ;
    int len = 10;

    gets(a);
    Bubble(a,len);
    puts(a);
    return 0;
}
void Bubble(char a[],int len){
    int z,i;
    char x;
    
    for(  z=len; z>=0; z--){
        for(  i=0; i<z-1; i++){
            if( a[i]> a[i+1]){
                x = a[i];
                a[i] = a[i+1];
                a[i+1] = x;
            }
        }
    }
}