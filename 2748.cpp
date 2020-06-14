#include <iostream>
using namespace std;

// 피보나치 수 2

int n;
long long dp[91];

int main() {
    
    cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    
    return 0;
}
