#include <iostream>
using namespace std;

// 음식 평론가

int N, M;

int gcd(int a, int b) {
    
    if(a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main() {
    
    cin >> N >> M;
    
    // 자르지 않고 나눠줄 수 있는 경우 0번의 칼질 (N % M == 0)
    cout << M - gcd(N, M) << endl;
    
    return 0;
}
