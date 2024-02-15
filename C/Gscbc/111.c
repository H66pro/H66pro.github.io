#include <stdlib.h>
#include "stdio.h"
#include "math.h"

int main(){
    double u[5], t[5];
    printf("请直接输入5个U值（回车输入下一个）：\t\t\t————多吃韩66\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%lf", &u[i]);
    }
    printf("请直接输入5个t值（回车输入下一个）：\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%lf", &t[i]);
    }

    double v[5], r[5], q[5];
    double d = 0.005, l = 0.002, density = 981, g = 9.8, p = 101300;
    double PI = 3.1415926, b = 0.00822, n = 0.00183;
    for (int i = 0; i < 5; ++i) {
        v[i] = l / t[i];
//        printf("v[%d]  =  %lf\t", i, v[i]);
        r[i] = sqrt(9 * n * v[i] / ( 2 * density * g ));
//        printf("r[%d]  =  %e\t", i+1, r[i]);
        q[i] = (18 * PI * d) / sqrt(2 * density * g) / (u[i] * n) * sqrt(pow(n * v[i] / ((1 + b / (p * r[i])) * t[i]), 3));
        printf("q[%d]  =  %e\n", i+1, q[i]);
    }
    system("pause");
    return 0;
}