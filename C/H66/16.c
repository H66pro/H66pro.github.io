#include <stdio.h>
#include <stdlib.h>
int main(){
    int number;
    int *p = NULL;
    printf("ÊäÈëÊıÁ¿£º");
    scanf("%d",&number);
    int a[number];
    p = (int*)malloc(number * sizeof(int));
    free(p);
    for(int i = 0; i<number; i++){
        scanf("%d",&a[i]);
    }
    for( int i = number-1;i>-1;i--){
        printf("%d ",a[i]);
    }
    
    return 0;
}