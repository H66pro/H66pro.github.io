#include <stdio.h>

int main(){
    int stu[5][6];
    int sum,SUM=0;

    for( int i=0; i<5; i++){
        sum = 0;
        for( int z=0; z<6; z++){
            stu[i][z] = (i+z)*9;
            sum += stu[i][z];
        }
        SUM += sum;
        printf("��%d���ƽ��C���Գɼ�Ϊ��%g\n",i+1,sum/6.0);
    }
    printf("ÿ��ѧ����ƽ���ɼ�Ϊ��%g",SUM/30.0);
    return 0;
}