#include <stdio.h>

int aver(int b[], int len){
    int sum=0;
    for(int i=0; i<10; i++){
        sum += b[i]; 
    }
    return (sum / len);
}

int main(){
    int sco[10]={55,61,94,84,0,58,66,12,32,159},m=sco[0];
   
        
    printf("%d",aver(sco, sizeof(sco)/sizeof(sco[0])));
    return 0;
}