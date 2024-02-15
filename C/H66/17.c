#include<stdio.h>
#include<math.h>
void bijiao(int a, int b);
int jdz(int x);
void star(int n);
int isPrime(int x);

int main(){
    
    int m,ret;
    scanf("%d",&m);
    ret = isPrime(m);
    if(ret == 1){
        printf("%d是素数\n",m);
    }
    else{
        printf("%d不是素数\n",m);
    }
    return 0;
}

int isPrime(int x){
	int i;
	int isPrime=1;
	int z=0;

	
	if( x%2==0 && x!=2){
		return 0;
	}
	for( i=3; i<sqrt(x); i+=2){
		if( x%i==0){
			isPrime=0;
			break;
		}
	}

    return isPrime;
}

int jdz(int x){
    int ret;
    if( x>=0){
        ret = x;
    }
    else{
        ret = -x;
    }
    
    return ret;
}

void star(int n){
    for( int i=0; i<n; i++){
        printf("*");
    }
    printf("\n");
}

void bijiao(int a, int b){
    
    if(a==b){
        printf("%d与%d相等",a,b);
    }
    else{
        printf("%d与%d不相等",a,b);
    }
    
}