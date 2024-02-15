#include <stdio.h>
#include <math.h>

int main() {
	int x;
	int i;
	int isPrime=1;
	int z=0;

	for( x=2; x<1000; x++,isPrime=1){
		if( x%2==0 && x!=2){
			continue;
		}
		for( i=3; i<sqrt(x); i+=2){
			if( x%i==0){
				isPrime=0;
				break;
			}
		}
		if( isPrime==1){
			printf("%d\t",x);
		}
	}
	return 0;
}
