#include <stdio.h>
#include <math.h>

int main(){
    double k[4], ts[4]={自己填}, te[4]={自己填}, N[4]={自己填};
    double averOfK, a, a0 = 20 * 0.000001, z;
    for (int i = 0; i < 4; i++)
    {
        k[i] = N[i] / (te[i] - ts[i]);
        printf("k[%d] = %lf\n", i+1, k[i]);
    }
    averOfK = (k[0] + k[1] + k[2] + k[3]) / 4;
    printf("averOfK = %lf\n", averOfK);
    a = 632.8 * averOfK / 2 / 150 / 1000000;
    printf("a = %e\n", a);
    z = fabs(a - a0) / a0;
    printf("误差：%lf%",z*100);
    
    return 0;
}