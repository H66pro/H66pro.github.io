#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input(double m[], double *p_h,double b[]);

int main()
{
    printf("Version --0.0.5\n请按照网站数据严格填写\n");    
    printf("-----------------------------------------------------\n");
    printf("本程序计算结果仅供参考,请求帮助请联系qq 3393831873\n");
    printf("                              ————多吃韩66、苏帅哥\n");
    printf("-----------------------------------------------------\n");
    const double PI = 3.1415926;

    double m[2]={0}, h=0, d[6]={0}, M=0, D=0, U_m=0;
    double UrOfM=0, UrOfh=0, UrOfd=0, S_d=0, sumOfd_2=0, U_d=0;
    double UrOfp=0, P=0, U_p=0;
    input( m, &h, d);

    printf("-----------------------------------------------------\n");
    
    M = sqrt( m[0] * m[1]);
    U_m = 0.01;
    UrOfM = U_m / M;
    printf("m平\t=\t%.2lf\tg\n", M);

    UrOfh = 0.5/h;

    for( int i=0; i<6; i++){
        D += d[i];
    }
    D = D/6;
    for( int i=0; i<6; i++){
        sumOfd_2 += ( d[i]-D)*( d[i]-D);
    }
    S_d = sqrt( sumOfd_2/5);
    printf("Sd\t=\t%.3lf\tmm\n", S_d);
    U_d = sqrt( S_d*S_d + 0.005*0.005);
    printf("Ud\t=\t%.3lf\tmm\n", U_d);
    UrOfd = U_d/D;

    UrOfp = sqrt( UrOfM*UrOfM + 4*UrOfd*UrOfd + UrOfh*UrOfh);
    printf("Ur(ρ)\t=\t%.2lf\t%\n", UrOfp*100);
    P = 4* (M/1000) / ( PI*(D/1000)*(D/1000)*(h/1000));
    printf("ρ平\t=\t%.2lf x10^3\t\tkg/m^3\n", P/1000);
    U_p = P * UrOfp;
    printf("Uρ\t=\t%.2lf x10^3\t\tkg/m^3\n", U_p/1000);
    printf("ρ=ρ平±Uρ=\t(%.2lf ± %.2lf) x10^3\tkg/m^3\n", P/1000, U_p/1000);

    printf("-----------------------------------------------------\n");
    
    system("pause");

    return 0;
}

void input(double m[], double *p_h, double d[])
{
    for(int i=0; i<2; i++){   
        printf("请输入质量m%d：\t",i+1);
        scanf("%lf",&m[i]);
    }
    
    printf("请输入长度h：\t");
    scanf("%lf",p_h);
    
    for( int i=0; i<6; i++){   
        printf("请输入直径d%d：\t",i+1);
        scanf("%lf",&d[i]);
    }
}