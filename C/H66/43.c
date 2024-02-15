#include <stdio.h>
int main()
{
 double score[5] = { 0.0 };
 int i = 0;
 while(i<5)
 { 
  int j = 0;
  double sum = 0.0;
  while(j<5)
  {
   scanf("%lf", &score[j]);  //scanf不能确定精度，只能粗略表示。当输入%.1lf这样的小数点后一位的输入时，程序将报错，必须用%lf
   sum += score[j];
   j++;
  }
    while(j<5)
  {
   printf("%.1lf", score[j]);//printf打印时可以确定精度，必须用%.1lf
   j++;
  }
  printf("%.1lf", sum);
  i++;
 }
 return 0;
}