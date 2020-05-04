#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 3루수는 몰라

int N;
char ground[501][501];
int dp[501][501];
string str = "MOLA";

int solve(int r, int c, int idx) {
    
    if (r == 0 || c == 0)
        return 0;
    
    if (ground[r][c] == str[idx])
    {
        if (idx == 0) return dp[r][c] + 1;
        return max(solve(r - 1, c, idx - 1), solve(r, c - 1, idx - 1));
    }
    
    return 0;
}

int main() {
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> ground[i][j];
  
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], solve(i, j, 3)));
        
    cout << dp[N][N];
    
    return 0;
}
