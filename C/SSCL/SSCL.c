#include <stdio.h>
#include <math.h>
#include <windows.h>

struct VF
{
    /* data */
    double f[6];
    double V[6];
} vf;


int main() {
    // 程序输入
        // scanf("%lf %lf", &vf.V[0], &vf.f[0]);
        // printf("%lf %lf", vf.V[0], vf.f[0]);
    int i=0, I=0, t=20, f0;
    double A=0.0, B=0.0, C=0.0, D=0.0, K=0.0, U=0.0;
    FILE *pfr = fopen( "Data.txt", "r");
    fscanf( pfr, "%d", &f0);
    for( i=0; i<6; i++){
        fscanf( pfr, "%lf %lf", &vf.V[i], &vf.f[i]);
    }
    
        // printf("f = (f+ - f-) / 2\nV = (Vr+ + Vr-) / 2\n");
        // for( int i=0; i<6; i++){
        //     printf("请输入V%d；\n", i+1);
        //     scanf("%lf", vf.f[i]);
        //     printf("请输入f%d；\n", i+1);
        //     scamf("%lf", vf.V[i]);
        // }
    // 处理结果1-计算与输出
    
    printf("vi·fi\t");
    for( i=0; i<6; i++){
        printf("| %g ", vf.V[i]*vf.f[i]);
    }
    
    printf("\n\nvi*vi\t");
    for( i=0; i<6; i++){
        printf("| %g ", vf.V[i]*vf.V[i]);
    }
    printf("\n");
    
        //  A
    for( i=0; i<6; i++){
        A += vf.V[i];
    }
    A = A / 6; 
    printf("A = %g m/s\n", A);
     
        //  B
    for( i=0; i<6; i++){
        B += vf.f[i];
    }
    B = B / 6;
    printf("B = %g Hz\n", B);

        //  C
    for( C=0, i=0; i<6; i++){
        C += vf.V[i] * vf.V[i];
    }
    C = C / 6;
    printf("C = %g 	(m/s)²\n", C);
    
        //  D
    for( D=0, i=0; i<6; i++){
        D += vf.V[i] * vf.f[i];
    }
    D = D / 6;
    printf("D = %g 	(m/s²)\n", D);
    
    K = (D - A*B) / (C - A*A);
    printf("K = %g × 10²\n", K/100);
    
    //  计算声速 
    double vt = 331.45 * sqrt(1 + t/273.15);
    double ve = f0 / K;
    U = fabs(ve - vt) / vt;
    printf("vts = %g × 10²\nves = %g × 10²\n", vt/100, ve/100);
    printf("U = %g %\n", U * 100);

    system("pause");
    return 0;
}