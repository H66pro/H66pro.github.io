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

    printf("-----------------------�������--------------------------\n");

    printf("K\t=\t%lf\nKH\t=\t%lf\n", K, KH);
    
    printf("-------------------------end-----------------------------\n\n");
    
    printf("��л���Ա������������֧�֣�                 ����������Ժ�66\n\n");
    system("pause");

    return 0;
}

void input( double VH[])
{   
    printf("---------------------------------------------------------\n");
    printf("�ո߷������ʺã�\n");
    printf("---------------------------------------------------------\n");
    printf("���ϸ�����վ������д\n���������ݽ����ο�\n\n");
    printf("�������й���������ϵQQ 3393831873\n������+QQ 2140707839\n\n");
    printf("-----------------------���벿��--------------------------\n");
    for(int i=0; i<6; i++){   
        printf("�������%d��VH��\t",i+1);
        scanf("%lf",&VH[i]);
    }
    printf("-------------------------end-----------------------------\n\n");
}