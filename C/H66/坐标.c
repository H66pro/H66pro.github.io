#include <stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if( x>0 && y>0){
        printf("该坐标位于第一象限\n");
    }
    else if ( x<0 && y>0) {
        printf("该坐标位于第二象限\n");
    }
    else if ( x<0 && y<0){
        printf("该坐标位于第三象限\n");
    }
    else if ( x>0 && y<0){
        printf("该坐标位于第四象限\n");
    }
    else if ( x==0 && y==0){
        printf("该坐标位于原点\n");
    }
    else if ( x==0 && y!=0){
        printf("该坐标位于x轴\n");
    }
    else{
        printf("该坐标位于y轴\n");
    }
    return 0;
}