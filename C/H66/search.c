#include <stdio.h>
int search( int key, int a[],int length);
int main(){
    int a[]={1,8,99,47,65,44,11,257,66,44,77,74,};
    int key;
    int length,ret;
    printf("请输入要查找的数：");
    scanf("%d",&key);
    length = sizeof(a)/sizeof(a[0]);
    ret = search( key, a, length);
    if ( ret!=-1 ){
        printf("a[%d]=%d",ret,key);
    }
    else{
        printf("未找到%d",key);
    }
    return 0;
}

int search( int key,int a[],int length){
    int i,ret=-1;
    for( i=0; i<length; i++){
        if(a[i] == key){
            ret = i;
            break;
        }
    }
    return ret;
}