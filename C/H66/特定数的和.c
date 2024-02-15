#include <stdio.h>
int main(){
    int i,sum=0,a;
    int n;

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        a = i;
        while(a!=0){
            if(a%10==2 || a%10==0 || a%10==1 || a%10==9){
                sum +=i;
				break;
            }
            a /=10;
        }
        
    }
    printf("%d",sum);
    return 0;
}
