#include <iostream>

using namespace std;

int main()
{
    enum color { red, green, blue} c;
    c = green;
    cout << c;
    cout << red;
    int a = blue;
    cout << a;

    return 0;
}