#include <stdio.h>

struct{                     //  结构的声明
    int amount;
    char *name;
}coins[] = {
    {1,"penny"},
    {5,"nickel"},
    {10,"dime"},
    {25,"quarter"},
    {50,"half-dollar"}
};

int main(){
    int x;
    scanf("%d",&x);
    for ( int i=0; i<sizeof(coins)/sizeof(coins[0]); i++){
        if( x==coins[i].amount){            //  结构的用法
            printf("%s\n",coins[i].name);
            break;
        }
    }
    return 0;
}