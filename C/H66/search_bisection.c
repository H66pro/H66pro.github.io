#include <stdio.h>
int search_bisection( int k, int num[], int);

int main(){
    int num[] = { 5,8,9,88,777,6354,9999,10000};
    int k,len=sizeof(num)/sizeof(num[0]);
    scanf("%d",&k);
    int r = search_bisection( k, num, len);
    
    if( r==-1){
        printf("Œ¥’“µΩ");
    }
    else{
        printf("num[%d] = %d",r,num[r]);
    }
    return 0;
}

int search_bisection( int k, int num[], int len){
    int left = 0;
    int right = len;
    int mid;
    int ret = -1;

    while( left<=right){
        mid = ( left + right)/2;
        
        if( k==num[mid]){
            ret = mid;
            break;
        }
        else if( k<num[mid]){
            right = mid - 1;
            
        }
        else if( k>num[mid]){
            left = mid + 1;
            
        }
    }
    return ret;
}