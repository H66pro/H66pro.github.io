#include <stdio.h>
#include <stdlib.h>

void Top ();
void Tail ();

int main(){
    Top();

    double Rs, U, a, Ur;
    printf("请输入Rs：");
    scanf("%lf",&Rs);

    U = Rs*0.0002;
    a = (int)(U*100)%10;
    if( a<=5 && a>0){
        U += 0.1 - a/100; 
    }
    Ur = U/Rs;

    printf("-----------------------输出部分--------------------------\n");
    printf("Rx\t=\t%.2lf\t\tΩ\n", Rs);
    printf("U\t=\t%.1lf\t\tΩ\n", U);
    printf("Rx±UΔ仪\t=\t%.1lf±%.1lf\tΩ\n", Rs, U);
    printf("Ur\t=\t%.2lf%\n", Ur*100);
    Tail();
    system("pause");
    return 0;
}

void Top ()
{
    printf("---------------------------------------------------------\n");
    printf("苏高封向您问好！\n");
    printf("---------------------------------------------------------\n");
    printf("请严格按照网站数据填写\n本程序数据仅供参考\n\n");
    printf("如数据有过大差距请联系QQ 3393831873\n捐助请+QQ 2140707839\n\n");
    printf("-----------------------输入部分--------------------------\n");
}

void Tail ()
{
    printf("-------------------------end-----------------------------\n\n");
    printf("感谢您对本程序的信任与支持！                 ————多吃韩66\n\n");
    
}