#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int m,n;

    cin >> m;
    cin >> n;

    for( int i=m; i<=n; i++){
        if( i%3==2 && i%5 == 3 && i%7 == 4){
            cout << i << " ";
        }
    }

    return 0;
}