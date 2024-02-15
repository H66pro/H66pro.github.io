#include <stdio.h>

int main(void){
    int number;
    char *a[]={ 
        "January\n","February\n",
        "March\n","April\n",
        "May\n","June\n",
        "july\n","August\n",
        "September\n","Octorber\n",
        "November\n","December\n"};
    printf("输入0以终止\n");
    
    do{
        printf("请输入数字：");
        scanf("%d",&number);
        if(number > 0 && number < 13){
            printf("%s",a[number-1]);
        }
        else if (number != 0){
            printf("输入有误，请重新输入\n");
        }
    }while(number != 0);
    printf("欢迎下次光临！\n");
    
    return 0;
}
