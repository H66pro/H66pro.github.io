#include <stdio.h>
int main(){
    int a[3]={1,1,1},x;
    int n;
    
    printf("Êä³ö¸öÊı£º");
    scanf("%d",&n);

    printf("1 1 ");
    for(int i=3;i<=n;i++){
        x = a[1]+a[2];
        a[1] = a[2];
        a[2] = a[3];
        printf("%d ",x);
    }
    return 0;
}