#include <stdio.h>
int main(){
    int a,b,c;
    int i=0;
    
    for(a=1;a<5;a++){
        for(b=1;b<5;b++){
            for(c=1;c<5;c++){
                if( a!=b && a!=c && b!=c){
                    printf("%d%d%d\n",a,b,c);
                    i++;
                }
            }
        }
    }
    printf("共组成了%d个三位数",i);
    return 0;
}