#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int M, N;
int farm[1001][1001];
int dp[1001][1001];
int answer;

void solve()
{
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            if (farm[i][j] == 0)
            {
                // 왼쪽, 왼쪽 위, 위 확인 후 최소값에 + 1
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                
                answer = max(answer, dp[i][j]);
            }
}

int main()
{
    cin >> M >> N;
    
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> farm[i][j];
    
    solve();
    
    cout << answer << endl;
    
    return 0;
    
}
