#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int i,j,k,n;
    char a = 'a';
    cin >> n;
    for( i=n,k=1; i>0; i--,k+=2){
        for( j=i; j>0; j--){
            printf(" ");
        }
        for( j=k; j>0; j--){   
            printf("%c",a+i-1);
        }
        printf("\n");
    }
    return 0;
}