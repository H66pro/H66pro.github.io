#include <stdio.h>
int main(){
    double a=0;
    int one,two,five;
    printf("请输入金额：");
    scanf("%lf",&a);

    for(one=0;one<=a*10;one++){
        for(two=0;two<=a*10/2;two++){
            for(five=1;five<=a*10/5;five++){
                if(a*10 == one+two*2+five*5){
                    printf("可以用%d个5角、%d个2角、%d个1角硬币得到%g元",five,two,one,a);
                    
                    goto out;
                }
            }
        }
    }
    out:
    return 0;
}
