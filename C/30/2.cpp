#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    double s=0.0;
    int n;
    cin >> n;
    for( int i=2; i<n+2; i++){
        s += 1.0/(2*i+1);
    }
    printf("%.1f",s);

    return 0;
}