#include <stdio.h>

struct date {
        int month;
        int day;
        int year;
    };

int main( int argc, char *argv[]){
    
    struct date today = { 2, 14, 2023};     //  结构体变量的初始化

    // today  = { 2, 14, 2023};             //  非法的整体赋值
    
    // today.year = 2023;                   //  合法的赋值
    // today.month = 2;
    // today.day = 14;

    printf("今天是%d年%d月%d日\n",today.year,today.month,today.day);

    return 0;
}