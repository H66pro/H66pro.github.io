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
   scanf("%lf", &score[j]);  //scanf����ȷ�����ȣ�ֻ�ܴ��Ա�ʾ��������%.1lf������С�����һλ������ʱ�����򽫱���������%lf
   sum += score[j];
   j++;
  }
    while(j<5)
  {
   printf("%.1lf", score[j]);//printf��ӡʱ����ȷ�����ȣ�������%.1lf
   j++;
  }
  printf("%.1lf", sum);
  i++;
 }
 return 0;
}