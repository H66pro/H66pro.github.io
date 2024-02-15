#include <stdio.h>
int main(){
    int i,amount=0;
    int a;
    scanf("%d",&i);
    a = i/100000;
    switch ( a){
        case 0 :
            amount = i * 0.1;
            break;
        case 1 :
            amount = 100000 * 0.1 + ( i - 100000)*0.075;
            break;
        case 2 :
            amount = 100000 * 0.1 + 100000*0.075 + ( i- 200000)*0.05;
            break;
        case 4 :
            amount = 100000*0.1 + 100000*0.075 + 200000*0.05 + (i-400000)*0.03;
            break;
        case 6 :
            amount = 100000*0.1 + 100000 * 0.075+ 200000* 0.05 +200000*0.03+ ( i-600000)*0.015;
            break;
        default :
            amount = 100000*0.1 + 100000 * 0.075 + 200000*0.05 + 200000*0.03 +400000*0.015 + (i-1000000)*0.001;
            break;
    }
    printf("%d",amount);
    return 0;
}