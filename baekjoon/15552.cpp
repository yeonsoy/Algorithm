#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 빠른 A+B

int main()
{
    fastio();
    
    int T;
    int a, b;
    
    cin >> T;
    
    while(T--) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
    return 0;
}
