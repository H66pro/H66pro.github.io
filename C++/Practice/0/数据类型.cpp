#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "type: \t\t" <<"size" << endl;
    
    cout << "bool: \t\t" << (numeric_limits<bool>::min)();
    cout << "\t\t" << (numeric_limits<bool>::max)() << endl;
    
    cout << "char: \t\t" << (numeric_limits<char>::min)();
    cout << "\t\t" << (numeric_limits<char>::max)() << endl;
    
    cout << "wchar_t: \t\t" << (numeric_limits<wchar_t>::min)();
    cout << "\t\t" << (numeric_limits<wchar_t>::max)() << endl;
    
    cout << "short: \t\t" << (numeric_limits<short>::min)();
    cout << "\t\t" << (numeric_limits<short>::max)() << endl;
    
    cout << "int: \t\t" << (numeric_limits<int>::min)();
    cout << "\t\t" << (numeric_limits<int>::max)() << endl;

    cout << "long: \t\t" << (numeric_limits<long>::min)();
    cout << "\t\t" << (numeric_limits<long>::max)() << endl;
    
    cout << "float: \t\t" << (numeric_limits<float>::min)();
    cout << "\t\t" << (numeric_limits<float>::max)() << endl;
    
    cout << "double: \t\t" << (numeric_limits<double>::min)();
    cout << "\t\t" << (numeric_limits<double>::max)() << endl;
    
    cout << "long double: \t\t" << (numeric_limits<long double>::min)();
    cout << "\t\t" << (numeric_limits<long double>::max)() << endl;
    
    cout << "long long: \t\t" << (numeric_limits<long long>::min)();
    cout << "\t\t" << (numeric_limits<long long>::max)() << endl;
    
    return 0;
}