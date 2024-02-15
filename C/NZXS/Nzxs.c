#include <stdio.h>
#include <math.h>
#include <Windows.h>

void input( double *A, double *B, double *D, double *h, double* t);
// void core();
void output( double, double, double, double, double, double);

int main(){
    double A, B, D, h, t[6], averOft=0, s, Ut, Urt, allOft, n, Un, Urn;
    // int ret=0;
    // do{
        input( &A, &B, &D, &h, t);
        for( int i = 0; i<6; i++){
            averOft += t[i];
        }
        averOft /=6;
        allOft = (t[0]-averOft)*(t[0]-averOft)+(t[1]-averOft)*(t[1]-averOft)+(t[2]-averOft)*(t[2]-averOft)+(t[3]-averOft)*(t[3]-averOft)+(t[4]-averOft)*(t[4]-averOft)+(t[5]-averOft)*(t[5]-averOft);
        s = sqrt( allOft/5);
        Ut = sqrt( s*s + 0.02*0.02);
        Urt = Ut / averOft;
        n = (0.01 * 9.8 * D * ( B - A) * averOft *1000000) / ( 2*3.1415*3.1415 * A * A * A * h * 5 );
        
        Urn = sqrt( (Ut / averOft)*(Ut / averOft) + (0.02/D)*(0.02/D) + (0.02/(B-A))*(0.02/(B-A)) + (0.02/h)*(0.02/h) + ((3*B-2*A)/A)*((3*B-2*A)/A)*0.02*0.02);
        Un = n * Urn;

        output( s, Ut, Urt, n, Un, Urn);
    // }while( ret);


    return 0;
}

void input( double *A, double *B, double *D, double *h, double t[])
{
    printf("---------------------------------------------------------\n");
    printf("欢迎使用本程序！\n");
    printf("---------------------------------------------------------\n");
    printf("请严格按照网站数据填写\n本程序数据仅供参考\n\n");
    printf("如数据有过大差距请联系QQ 3393831873\n捐助请+QQ 2140707839\n\n");
    printf("-----------------------输入部分--------------------------\n");
    
    // printf("请输入A(mm)：");
    // scanf("%lf", A);
    // printf("请输入B(mm)：");
    // scanf("%lf", B);
    // printf("请输入D(mm)：");
    // scanf("%lf", D);
    // printf("请输入h(mm)：");
    // scanf("%lf", h);

    // for(int i=0; i<6; i++){   
    //     printf("请输入t%d：\t", i+1);
    //     scanf("%lf",&t[i]);
    // }
    t[1] =    36.94;
    t[2] =   36.25;
    t[3]   = 35.72;
    t[4]   =  35.57;
    t[5]   =   34.97;
    t[0]   =   34.43;
    *A = 50.0;
    *B = 61.56;
    *D = 35.24;
    *h = 74.74;
    // t[1] =    34.77;
    // t[2] =   34.58;
    // t[3]   = 35.09;
    // t[4]   =  36.01;
    // t[5]   =   34.06;
    // t[0]   =   33.53;
    // *A = 49.9;
    // *B = 61.64;
    // *D = 35.18;
    // *h = 75.20;
    printf("-------------------------end-----------------------------\n\n");
}



void output( double s, double Ut, double Urt, double n, double Un, double Urn)
{
    printf("-----------------------输出部分--------------------------\n");

    printf("s\t=\t%.2lf\n", s);
    printf("Ut\t=\t%.2lf\n", Ut);
    printf("Urt\t=\t%.2lf%\n", Urt*100);
    printf("n\t=\t%.2lf\n", n);
    printf("Un\t=\t%.2lf\n", Un);
    printf("Urn\t=\t%.2lf%\n", Urn*100);
    
    printf("-------------------------end-----------------------------\n\n");
    
    printf("感谢您对本程序的信任与支持！                 ————多吃韩66\n\n");
    // system("pause");
}