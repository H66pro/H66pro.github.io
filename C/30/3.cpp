#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int n,i,j;
    cin >> n;
    for( j=n; j>0; j--){  
        for( i=n-j; i>0; i--){
            printf(" ");
        } 
        for( i=j; i>0; i--){
            printf("*");
        }
        printf("#\n");
    }
    
    return 0;
}