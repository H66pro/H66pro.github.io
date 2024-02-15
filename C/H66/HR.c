#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input(double VH[]);

int main( int argc, char *argv[]){

    double K, VH[6], KH, aveVH=0, aveIs=1.75;
    double Is[6] = { 0.50, 1.00, 1.50, 2.00, 2.50, 3.00, };

    input( VH);

    for(int i=0; i<6; i++){
        aveVH += VH[i];
    }
    aveVH /= 6;
    K = aveVH / aveIs;
    KH = K / 0.01125;

    printf("-----------------------输出部分--------------------------\n");

    printf("K\t=\t%lf\nKH\t=\t%lf\n", K, KH);
    
    printf("-------------------------end-----------------------------\n\n");
    
    printf("感谢您对本程序的信任与支持！                 ————多吃韩66\n\n");
    system("pause");

    return 0;
}

void input( double VH[])
{   
    printf("---------------------------------------------------------\n");
    printf("苏高封向您问好！\n");
    printf("---------------------------------------------------------\n");
    printf("请严格按照网站数据填写\n本程序数据仅供参考\n\n");
    printf("如数据有过大差距请联系QQ 3393831873\n捐助请+QQ 2140707839\n\n");
    printf("-----------------------输入部分--------------------------\n");
    for(int i=0; i<6; i++){   
        printf("请输入第%d个VH：\t",i+1);
        scanf("%lf",&VH[i]);
    }
    printf("-------------------------end-----------------------------\n\n");
}