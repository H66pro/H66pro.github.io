//
// Created by H66 on 2023/11/2.
//
#include <stdlib.h>
#include "stdio.h"
#include "math.h"

int main() {
    //  数据输入
    double UL=0.5, Ud=0.005;
    double L, d;
    printf("请输入L(cm):");
    scanf("%lf", &L);
    printf("请输入d(mm):");
    scanf("%lf", &d);

    double r[8];
    printf("请依次输入平均值：\n");
    for (int i = 0; i < 8; ++i) {
        scanf("%lf", &r[i]);
    }

    //逐差法
    double l[4], averOfl=0, differOfl[4];

    for (int i = 0; i < 4; ++i) {
        l[i] = r[i+4] - r[i];
        averOfl += l[i];
    }
    averOfl = averOfl / 4.0;

    for (int i = 0; i < 4; ++i) {
        differOfl[i] = l[i] - averOfl;
    }

    double UlA, UlB, Ul;
    UlA = 1.6 * sqrt((differOfl[0]*differOfl[0] + differOfl[1]*differOfl[1] + differOfl[2]*differOfl[2] +differOfl[3]*differOfl[3]) / 3.0);
    UlB = sqrt(2.0) * 0.05;
    Ul = sqrt(UlA*UlA + UlB*UlB);

    //杨氏模量
    double E, Ur, UE;
    E = 16 * 0.2 * 9.8 * (L / 100) / (3.1415926 * d * d / 1000000 * averOfl / 1000);
    Ur = sqrt(4 * pow(Ud/d, 2) + pow(Ul/averOfl, 2) + pow(UL/L, 2));
    UE = E * Ur;

    //打印
    printf("逐差法部分：\n");
    for (int i = 0; i < 4; ++i) {
        printf("l%d\t=\t%lfmm\tΔl%d\t=\t%lfmm\n", i+1, l[i], i+1, differOfl[i]);
    }
    printf("l\t=\t%lfmm\n", averOfl);
    printf("UlA\t=\t%lfmm\n", UlA);
    printf("UlB\t=\t%lfmm\n", UlB);
    printf("Ul\t=\t%lfmm\n", Ul);
    printf("E\t=\t%lf x10^11N/m2\n", E/pow(10,11));
    printf("Ur\t=\t%lf%\n", Ur * 100);
    printf("UE\t=\t%lf x10^11N/m2\n", UE/pow(10,11));
    printf("E+UE\t=\t(%lf ± %lf) x10^11N/m2\n", E/pow(10,11), UE/pow(10,11));

    system("pause");
    return 0;
}
