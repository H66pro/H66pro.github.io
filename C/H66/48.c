#include <stdio.h>
#include <string.h>

void fun(char *str)
{
	int i;
	for( i=0; str[i]!='\0'; i++){
		if( str[i]==' '){
			str[i] = str[i+1];
			str[i+1] = ' ';
		}
	}



}

main()
{
  char str[81];void NONO ();

  printf("Input a string:") ;
  gets(str);
  puts(str);
  fun(str);
  printf("*** str: %s\n",str);
  NONO();
  getchar();
}

void NONO ()
{
/* 请在此函数内打开文件，输入调试数据，调用 fun 函数，
   输出数据，关闭文件。 */
  char str[81];
  int n = 0;
  FILE *rf, *wf ;

  rf = fopen("in.dat","r") ;
  wf = fopen("out.dat","w") ;
  while(n < 10) {
    fgets(str, 80, rf);
    fun(str);
    fprintf(wf, "%s", str) ;
    n++ ;
  }
  fclose(rf) ;
  fclose(wf) ;
}

