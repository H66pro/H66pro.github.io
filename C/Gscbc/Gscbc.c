#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define PI 3.1415926

double rad(int degree, int minute);

int main() {

    //数据输入
    printf("请输入所有数字，非数字换成空格（°‘也得换成空格），用空格分开，可以一次性粘贴：\t\t————多吃韩66\n");
    int r[8][4];
    for(int r1 = 0; r1 <8; r1 ++) {
        for(int r2 = 0; r2 <4; r2++) {
            scanf("%d", &r[r1][r2]);
//            printf("%d\t", r[r1][r2]);
        }
    }

    //弧度制转换
    double R[8][2];
    for(int r1 = 0; r1 <8; r1 ++) {
        for(int r2 = 0, r3 = 0; r2 <4; r2 = r2 + 2, r3 ++) {
            R[r1][r3] = rad(r[r1][r2], r[r1][r2+1]);
//            printf("%lf\t", R[r1][r3]);
        }
    }

    //数据处理
    double w[8]={};
    for(int r1 = 0; r1 < 8; r1 ++) {
        w[r1] = R[r1][0] - R[r1][1];
        if( w[r1]<0 ) {
            w[r1] = -w[r1];
        }
//        printf("%lf\t", w[r1]);
    }
//    printf("\n");
    double p[4]={};
    for (int i = 0; i < 8; i += 2) {
        p[ i/2 ] = (w[i] + w[i+1]) / 4;
//        printf("%lf\t", p[ i/2 ]);
    }
    double ud = 5.4607 * 0.0000001 * cos(p[2]) / sin(p[2]) / sin(p[2]) * 0.0001;
    double d = 5.4607 * 0.0000001 / sin(p[2]);
    double wave[3] = {};
    wave[0] = d * sin(p[0]);
    wave[1] = d * sin(p[1]);
    wave[2] = d * sin(p[3]);
    double e[3] = {};
    e[0] = fabs((wave[0]*pow(10,10) - 5790.7) / 5790.7);
    e[1] = fabs((wave[1]*pow(10,10) - 5769.6) / 5769.6);
    e[2] = fabs((wave[2]*pow(10,10) - 4358.3) / 4358.3);


    //结果输出
    printf("第一个：\t%lf\n", p[2] * 10000);
    printf("第二个：\t%lf\n", p[0] * 10000);
    printf("第三个：\t%lf\n", p[1] * 10000);
    printf("第四个：\t%lf\n", p[3] * 10000);
    printf("d = \t%.0lf ± %.0lf * 10^-9\n", d*pow(10,9), ud*pow(10,9));
    printf("黄I的波长为\t%.1lf\n", wave[0]*pow(10,10));
    printf("黄II的波长为\t%.1lf\n", wave[1]*pow(10,10));
    printf("紫蓝的波长为\t%.1lf\n", wave[2]*pow(10,10));
    printf("E黄I = \t%.2lf%\n", e[0]*100);
    printf("E黄II = \t%.2lf%\n", e[1]*100);
    printf("E紫蓝 = \t%.2lf%\n", e[2]*100);

    system("pause");
    return 0;
}

double rad(int degree, int minute) {
    double r = (degree / 1.0 + minute / 60.0) * PI / 180.0;
    return r;
}