#include <stdio.h>

struct date {
        int month;
        int day;
        int year;
    };

int main( int argc, char *argv[]){
    
    struct date today = { 2, 14, 2023};     //  �ṹ������ĳ�ʼ��

    // today  = { 2, 14, 2023};             //  �Ƿ������帳ֵ
    
    // today.year = 2023;                   //  �Ϸ��ĸ�ֵ
    // today.month = 2;
    // today.day = 14;

    printf("������%d��%d��%d��\n",today.year,today.month,today.day);

    return 0;
}