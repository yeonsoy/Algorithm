#include <iostream>
using namespace std;

// 사수빈탕

int candy[302][302];
long long dp[302][302];
int N, M;

int main() {

	cin >> N >> M;

	int r, c;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		candy[r + 1][c + 1] = M - r - c;

		if (candy[r + 1][c + 1] < 0)
			candy[r + 1][c + 1] = 0;
	}

	for (int i = 1; i <= 301; i++)
		for (int j = 1; j <= 301; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + candy[i][j];
		}

	cout << dp[301][301];

	return 0;
}