#include <iostream>
using namespace std;

int T;
int a, b, c;

// 직사각형 길이 찾기

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> a >> b >> c;
        
        cout << "#" << test_case + 1 << " ";
        if(a == b) cout << c << endl;
        else if(a == c) cout << b << endl;
        else cout << a << endl;
    }
    
    
    return 0;
}
