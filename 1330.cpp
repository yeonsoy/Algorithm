#include <iostream>
using namespace std;

// 두 수 비교하기

int a, b;

int main() {
    
    cin >> a >> b;
    
    if(a < b)
        cout << "<" << endl;
    else if(a > b)
        cout << ">" << endl;
    else
        cout << "==" << endl;
    
    return 0;
}
