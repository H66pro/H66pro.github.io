#include <stdio.h>

enum COLOR { RED, YELLOW, GREEN,NumCOLORS};

void f ( enum COLOR c);

int main( int argc, char const *argv[])
{
    enum COLOR color = -1;
    printf("%d\n",color);
    // int color = -1;
    char *colorName = NULL;

    printf("请输入你喜欢的颜色的代码：");
    scanf("%d",&color);
    f ( color );
    switch ( color ){
        case RED    :   colorName = "red";
                        break;
        case YELLOW :   colorName = "yellow";
                        break;
        case GREEN  :   colorName = "green";
                        break;
        default     :   colorName = "unknown";
                        break;
    }

    printf("你最喜欢的颜色是：%s\n",colorName);

    return 0;
}

void f ( enum COLOR c)
{
    printf("你输入的代码为%d\n",c);
}