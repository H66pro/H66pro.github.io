#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
FILE *fp;
int i=0;
char str[100];
printf("请输入字符串，并且以感叹号!结束:\n");
if((fp=fopen("test.txt","w"))==NULL){
   printf("无法打开此文件!\n");
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
    printf("有字符%d个",count);
       printf("\n"); 
     fclose(fp);
if((fp=fopen("test.txt","r"))==NULL)
{
   printf("File open falied!\n");
   exit(0);
}
printf("转换后的字符串是:\n");
puts(fgets(str,strlen(str)+1,fp));
fclose(fp);
return 0;
}
