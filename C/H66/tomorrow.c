#include <stdio.h>

struct DAY {
    int year;
    int month;
    int day;
};

int isLeapYear ( struct DAY t);
int numberOfday ( struct DAY t);

int main(){
    
    struct DAY today, tomorrow;
    printf("请输入日期：\n");

    today = (struct DAY){ 2022, 5 ,19};
    // scanf("%i %i %i", &today.year, &today.month, &today.day);
    tomorrow = today;
    struct DAY *p;
    p = &tomorrow;

    if( today.day >= 1 && today.day < numberOfday( today)){
        tomorrow.day ++;
    }else if( today.month == 12){
        tomorrow.year ++;
        tomorrow.month = 1;
        tomorrow.day = 1;
    }else{
        tomorrow.month ++;
        tomorrow.day = 1;
    }
    printf("明天是%i年%i月%i日", tomorrow.year, tomorrow.month, tomorrow.day);
    printf("p->day = %i",p->day);
    printf("结构%d\nint%d\n",sizeof(today),sizeof(today.day));

    return 0;
}

int isLeapYear ( struct DAY t){
    int ret = 0;
    if( t.year % 400 ==0){
        ret = 1;
    }else if( t.year % 100 != 0 && t.year % 4 == 0){
        ret = 1;
    }
    return ret;
}

int numberOfday ( struct DAY t){
    int ret = 31;
    
    if( t.month == 2){
        if( isLeapYear( t)){
            ret = 29;
        }else{
            ret = 28;
        }
    }else if( t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11){
        ret = 30;
    }

    return ret;
}