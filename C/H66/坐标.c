#include <stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if( x>0 && y>0){
        printf("������λ�ڵ�һ����\n");
    }
    else if ( x<0 && y>0) {
        printf("������λ�ڵڶ�����\n");
    }
    else if ( x<0 && y<0){
        printf("������λ�ڵ�������\n");
    }
    else if ( x>0 && y<0){
        printf("������λ�ڵ�������\n");
    }
    else if ( x==0 && y==0){
        printf("������λ��ԭ��\n");
    }
    else if ( x==0 && y!=0){
        printf("������λ��x��\n");
    }
    else{
        printf("������λ��y��\n");
    }
    return 0;
}