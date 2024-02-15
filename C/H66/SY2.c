#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input(double U_m[], double U1[],double U2[]);

int main( int argc, char *argv[]){
    double U_m[6] = { 14.7, 28.9, 42.5, 57.0, 71.1, 85.2}, E_V = 0.1, m = 0.500, g = 9.8020;
    double Aver_U_m, S_U_m, U_U_m, Aver_K, U_K, K, Ur_K, S_Mis_U, U_Mis_U;
    double U1[6] ={ 63.4, 63.1, 62.9, 62.7, 63.2, 62.5}, U2[6] ={ 15.2, 15.4, 15.2, 15.1, 15.0, 14.9};
    double Mis_U[6] = { 0}, Aver_Mis_U, num=0, Aver_a, U_a, Ur_a, D1 = 34.96, D2 = 33.10;
    const double PI = 3.1415926;

    // input( U_m, U1, U2);

    Aver_U_m = (( U_m[3]-U_m[0]) + ( U_m[4]-U_m[1]) + ( U_m[5]-U_m[2])) / 9;
    S_U_m = sqrt(( pow( U_m[0]-Aver_U_m, 2)+pow( U_m[1]-U_m[0]-Aver_U_m, 2)+pow(U_m[2]-U_m[1]-Aver_U_m, 2)+pow(U_m[3]-U_m[2]-Aver_U_m, 2)+pow(U_m[4]-U_m[3]-Aver_U_m, 2)+pow(U_m[5]-U_m[4]-Aver_U_m, 2))/5);
    U_U_m = sqrt( pow( S_U_m, 2) + pow( E_V, 2));

    Aver_K = Aver_U_m * 1000 / ( m*1000*g);
    U_K = U_U_m*1000 / ( m*1000*g);
    Ur_K = U_K / Aver_K;

    for( int i=0; i<6; i++){
        Mis_U[i] = U1[i] - U2[i];
        num += Mis_U[i];
    }
    Aver_Mis_U = num / 6;
    S_Mis_U = sqrt(( pow( Mis_U[0]-Aver_Mis_U, 2)+pow( Mis_U[1]-Mis_U[0]-Aver_Mis_U, 2)+pow(Mis_U[2]-Mis_U[1]-Aver_Mis_U, 2)+pow(Mis_U[3]-Mis_U[2]-Aver_Mis_U, 2)+pow(Mis_U[4]-Mis_U[3]-Aver_Mis_U, 2)+pow(Mis_U[5]-Mis_U[4]-Aver_Mis_U, 2))/5);
    U_Mis_U = sqrt( pow( S_Mis_U, 2) + pow( E_V, 2));

    Aver_a = Aver_Mis_U*1000 / ( Aver_K * PI * (D1 + D2) * 1000);
    Ur_a = sqrt( pow( U_K/Aver_K, 2) + pow( U_Mis_U/Aver_Mis_U, 2));
    U_a = Aver_a * Ur_a;

    printf("-----------------------输出部分--------------------------\n");

    printf("ΔU平\t=\t%.4lf\t\tmV\n", Aver_U_m);
    printf("SΔu\t=\t%.4lf\t\tmV\n", S_U_m);
    printf("k=k平±Uk=\t%.4lf±%.4lf\t(V/N)\n", Aver_K, U_K);
    printf("ɑ平\t=\t%.4lf\t\tN/m\n", Aver_a);
    printf("Uɑ\t=\t%.4lf\t\tN/m\n", U_a);
    printf("Ur(ɑ)\t=\t%.4lf\t\t%\n", Ur_a);
    printf("ɑ=ɑ平±Uɑ=\t%.4lf±%.4lf\t(N/m)\n", Aver_a, U_a);
    
    printf("-------------------------end-----------------------------\n\n");
    
    printf("感谢您对本程序的信任与支持！                 ————多吃韩66\n\n");
    printf("argc=%d\nargv=%s\t%s\n",argc,argv[0],argv[1]);
    system("pause");

    return 0;
}

void input( double U_m[], double U1[], double U2[])
{   
    printf("---------------------------------------------------------\n");
    printf("苏高封向您问好！\n");
    printf("---------------------------------------------------------\n");
    printf("请严格按照网站数据填写\n本程序数据仅供参考\n\n");
    printf("如数据有过大差距请联系QQ 3393831873\n捐助请+QQ 2140707839\n\n");
    printf("-----------------------输入部分--------------------------\n");
    for(int i=0; i<6; i++){   
        printf("请输入传感器灵敏度的测量部分的U[%d]：\t",i+1);
        scanf("%lf",&U_m[i]);
    }
    printf("\n---------------------------------------------------------\n");
    for( int i=0; i<6; i++){   
        printf("请输入电压U1的第%d个数据：\t",i+1);
        scanf("%lf",&U1[i]);
    }
    printf("\n---------------------------------------------------------\n");
    for( int i=0; i<6; i++){   
        printf("请输入电压U2的第%d个数据：\t",i+1);
        scanf("%lf",&U2[i]);
    }
    printf("-------------------------end-----------------------------\n\n");
}