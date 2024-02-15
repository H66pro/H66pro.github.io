#include <stdio.h>
#include <string.h>

struct student {
    int number;     //  学号
    char name[10];
    float sum[3];   //  三门成绩
    float aver;     //  平均分
};
struct student *p;
void out( struct student *stu);
int max(struct student *p);
void input(struct student *p);

int main( ){
    struct student stu[5];
    int ret;
    for( int i=0;i<5;i++){
        stu[5] = (){221+i, "axc",78-i,59-i,46+i*i};
    }
    input(stu);
    ret = max(stu);
    printf("%d",ret);
    // out( stu);

    return 0;
}


void input(struct student *p){
    int i;
    for( i=0; i<5 ;i++){
        // scanf("%d %s %f %f %f",&p->number,&p->name,&p->sum[0],&p->sum[1],&p->sum[2]);
        p->aver = (p->sum[0] + p->sum[1] + p->sum[2])/3;
        p++;
    }
}

int max(struct student *p){
    int m = p->aver;
    
    return m;
}

void out( struct student *stu){
    int i;
    for( i=0; i<5 ;i++){
        printf("%d %s %.1f %.1f %.1f",stu[i].number,stu[i].name,stu[i].sum[0],stu[i].sum[1],stu[i].sum[2]);
    }
}