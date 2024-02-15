#include <stdio.h>
int main(){
    const int size = 3;
    int board[size][size];
    int i,j;
    int num_ofX;
    int num_ofO;
    int result = -1;    //  -1��ƽ�֣�1��XӮ��0��OӮ

    for ( i=0; i<size; i++){     //�������
        for ( j=0; j<size;j++){
            scanf("%d",&board[i][j]);
        }
    }

    for ( i=0; i < size && result == -1; i++){   //  �����
        num_ofO = num_ofX = 0;
        for ( j=0; j<size; j++){
            if( board[i][j] == 1){
                num_ofX ++;
            }
            else{
                num_ofO ++;
            }
        }
        if (num_ofX == size){
            result = 1;
        }
        else if (num_ofO == size){
            result = 0;
        }
    }

    for ( i=0; i < size && result == -1; i++){   //  �����
        num_ofO = num_ofX = 0;
        for ( j=0; j<size; j++){
            if( board[j][i] == 1){
                num_ofX ++;
            }
            else{
                num_ofO ++;
            }
        }
        if (num_ofX == size){
            result = 1;
        }
        else if (num_ofO == size){
            result = 0;
        }
    } 

    for ( i=0; i<size; i++){    //  ���Խ���__1
        num_ofO = num_ofX = 0;
        if( board[i][i] == 1){
                num_ofX ++;
            }
            else{
                num_ofO ++;
            }
        if (num_ofX == size){
            result = 1;
        }
        else if (num_ofO == size){
            result = 0;
        }
    }

    for ( i=2; i>-1; i--){
        num_ofO = num_ofX = 0;
        for ( j=0; j<size; j++){
            if( board[i][j] == 1){
                num_ofX ++;
            }
            else{
                num_ofO ++;
            }
        }
        if (num_ofX == size){
            result = 1;
        }
        else if (num_ofO == size){
            result = 0;
        }
    }
    
    if ( result == 1)   //������
        printf("XӮ����ʤ��");
    else if ( result == 0)
        printf("OӮ����ʤ��");
    else 
        printf("ƽ��");
    
    return 0;
}