#include <stdio.h>
void ex(int *q1,int *q2,int *q3){

}
int main(void){
    
    int a[10],i,*p;
    p=a;
    for(i=0; i<10;i++){
        scanf("%d",p);
        p +=1;
    }

    printf("\n");

    for(i=0;i<10;i++,p++){
        printf(" %d ",*p);
    }
    printf("\n");
    
    return 0;
}