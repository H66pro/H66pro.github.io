#include <stdio.h>
int main(){
    int a,b;
    int num,i;
    
    scanf("%d %d",&a,&b);

    for(i=1;i<a && i<b;i++){
        if(a%i ==0 && b%i ==0){            
            num = i;           
        }
    }
    printf("%d��%d�����Լ��Ϊ%d\n",a,b,num);
    return 0;
}
