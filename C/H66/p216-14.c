#include <stdio.h>

void max(int num[][10]);
void stu_aver(int num[][10],double x[10]);
void cla_aver(int num[][10]);
void var(double x[10]);

int main(){
    int i,z;
    double x[10];
    int num[5][10] = {0};
    printf("������ɼ�:");
    for( i=0; i<5; i++){
        for( z=0;z<10;z++){
            scanf("%d,",&num[i][z]);
        }
    }
    stu_aver(num,x);
    printf("\n");
    cla_aver(num);
    printf("\n");
    max(num);
    var(x);

    return 0;
}

void stu_aver(int num[][10],double x[]){
    int stu_a[10]={0},i,z;
    for( z=0; z<10; z++){
        for( i=0;i<5;i++){
            stu_a[z] += num[i][z];
        }
        x[z] = stu_a[z]/5.0;
        printf("ͬѧ%d��ƽ����Ϊ%.1f\n",z+1,x[z]);
    }
    
}

void cla_aver(int num[][10]){
    int cla_a[10]={0},i,z;
    for( i=0;i<5;i++){
        for( z=0; z<10; z++){
            cla_a[i] += num[i][z];
        }
        printf("�γ�%d��ƽ����Ϊ%.1f\n",i+1,cla_a[i]/10.0);
    }
    
}

void max(int num[][10]){
    int i,z,m=num[0][0],stu,cla;
    for( i=0;i<5;i++){
        for( z=0; z<10; z++){
            if(m<num[i][z]){
                m = num[i][z];
                stu = z+1;
                cla = i+1;
            }
        }
    }
    printf("������ߵ���ѧ��%d,�γ�%d\n",stu,cla);
}

void var(double x[10]){
    int i,z,sum1=0,sum2=0;
    double n = 10.0,ret;
    for( i=0; i<10; i++){
        sum1 = sum1 + x[i]*x[i];
        sum2 += x[i];
    }
    ret = sum1 / n - (sum2 / n) * (sum2 / n);
    printf("ƽ���ַ���Ϊ%.1f\n",ret);
}