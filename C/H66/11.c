#include<stdio.h>
int main(){
    int n, m, i, sum=0, a[100];
    scanf("%d",&n);
    for( i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<n;i++){
        if( m == a[i]){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}