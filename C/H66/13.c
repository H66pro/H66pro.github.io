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
        printf("第%d组的平均C语言成绩为：%g\n",i+1,sum/6.0);
    }
    printf("每个学生的平均成绩为：%g",SUM/30.0);
    return 0;
}