#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int T;
int a, b;

int fastPow(int c, int d) {
    
    if(c == 1) return 1;
    
    int res = c;
    
    for(int i = 1; i<d; i++) {
        res *= c;
        res %= 10;
    }
    
    return res;
}

int main() {
    
    fastio();
    
    cin >> T;
    
    for(int i = 0; i<T; i++) {
        
        cin >> a >> b;
        
        int answer = fastPow(a, b) % 10;
        if(answer == 0) answer = 10;
        
        cout << answer << '\n';
        
    }
    
    return 0;
}
