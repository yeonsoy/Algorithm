#include <iostream>
using namespace std;

// 극장 좌석

int N, M;
int answer = 1;
int dp[41];

int main() {

    cin >> N >> M;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= N; i++)
        // 좌석을 옮기지 않는 경우 dp[i - 1]
        // 좌석을 옮기는 경우 dp[i - 2]
        dp[i] = dp[i - 1] + dp[i - 2]; // 좌석이 N개 있을 때 앉을 수 있는 경우의 수

    int st = 0;
    int ed = 0;
    for (int i = 0; i < M; i++) {
        cin >> ed;
        answer *= dp[ed - st - 1];
        st = ed;
    }

    answer *= dp[N - st];

    cout << answer << "\n";

	return 0;
}