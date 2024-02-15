#include <stdio.h>
int main(){
    int n,i;
    double num=0.0;
    double sign=1.0;
    
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        num += sign/i;
        sign = -sign;
    }
    printf("f(n)=%f\n",num);
    return 0;
}