#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
FILE *fp;
int i=0;
char str[100];
printf("�������ַ����������Ը�̾��!����:\n");
if((fp=fopen("test.txt","w"))==NULL){
   printf("�޷��򿪴��ļ�!\n");
   exit(0);
}
gets(str);
int count=0;
while(str[i]!='!')
{
   if(str[i]>='a'&&str[i]<='z')
    str[i]-=32;
   fputc(str[i],fp);
   i++;
   count++;
}
    printf("���ַ�%d��",count);
       printf("\n"); 
     fclose(fp);
if((fp=fopen("test.txt","r"))==NULL)
{
   printf("File open falied!\n");
   exit(0);
}
printf("ת������ַ�����:\n");
puts(fgets(str,strlen(str)+1,fp));
fclose(fp);
return 0;
}
