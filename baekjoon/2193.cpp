#include <iostream>
using namespace std;

// 이친수

int N;
long long dp[91][2];

int main() {

    cin >> N;

    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
 
    cout << dp[N - 1][0] + dp[N - 1][1];

	return 0;
}