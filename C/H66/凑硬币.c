#include <stdio.h>
int main(){
    double a=0;
    int one,two,five;
    printf("�������");
    scanf("%lf",&a);

    for(one=0;one<=a*10;one++){
        for(two=0;two<=a*10/2;two++){
            for(five=1;five<=a*10/5;five++){
                if(a*10 == one+two*2+five*5){
                    printf("������%d��5�ǡ�%d��2�ǡ�%d��1��Ӳ�ҵõ�%gԪ",five,two,one,a);
                    
                    goto out;
                }
            }
        }
    }
    out:
    return 0;
}
