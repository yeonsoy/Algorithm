#include <iostream>
using namespace std;

int T;
int L, U, X;

// 준환이의 운동관리

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        
        cin >> L >> U >> X;
        
        cout << "#" << test_case + 1 << " ";
        if(L <= X && X <= U) cout << 0 << endl;
        else if (X > U) cout << -1 << endl;
        else cout << L - X << endl;
    }
    
    
    return 0;
}
