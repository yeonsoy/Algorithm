#include <iostream>
using namespace std;

// 줄어들지 않아

int T;
int n;
long long dp[65][10];

int main() {
    
    cin >> T;
    
    for(int i = 0; i<10; i++)
        dp[1][i] = i + 1;
    
    for(int i = 2; i<65; i++) {
        dp[i][0] = 1;
        for(int j = 1; j<10; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    
    for(int i = 0; i<T; i++) {
        cin >> n;
        cout << dp[n][9] << endl;
    }
    
    return 0;
}
