#include <iostream>
#include <vector>
using namespace std;

// 1, 2, 3 더하기

int N;
int dp[1001];

int solve(int n) {
    
    if (n < 0) return 0;
    if (n <= 1) return 1;
    if (dp[n]) return dp[n];
    return dp[n] = solve(n - 3) + solve(n - 2) + solve(n - 1);
    
}

int main() {
    
    cin >> N;
    for(int i =0; i<N; i++) {
        int num;
        cin >> num;
        cout << solve(num) << endl;
    }
    
    return 0;
}
