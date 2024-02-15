#include <stdio.h>
int main(){
    int a[] = {15,59,48,26,33,77,597,484,567,888,984,211,0,99999};
    int t=0,x;
    int len = sizeof(a)/sizeof(a[0]);
    // for(int i=0;i<10;i++){
    //     scanf("%d",&a[i]);
    // }
    for( int z=1; z<len; z++ ){
        t=z-1;
        for(int i=z;i<len;i++){
            if(a[t]>a[i]){
                t = i;
            }
        }
        x = a[z-1];
        a[z-1] = a[t];
        a[t] = x;
    }
    for( int i=0;i<len;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}