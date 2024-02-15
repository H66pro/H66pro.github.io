#include <stdio.h>
#include <string.h>

int main( int argc, char const *argv[]) {
	int i;
	char a[]="hello,world";
	char *p;
	char C;
	C = 'l';
	p = strchr( a, C);
	
	if( p != NULL){
		for( i=1; i<2147483647; i++){
			p = strchr( p+1, C);
			if( p != NULL){
				continue;
			}
			else{
				break;
			}
		}
	}
	printf("%s 中共有 %d个%c\n", a, i, C);
	
	return 0;
}