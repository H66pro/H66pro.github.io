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
    printf("����0����ֹ\n");
    
    do{
        printf("���������֣�");
        scanf("%d",&number);
        if(number > 0 && number < 13){
            printf("%s",a[number-1]);
        }
        else if (number != 0){
            printf("������������������\n");
        }
    }while(number != 0);
    printf("��ӭ�´ι��٣�\n");
    
    return 0;
}
