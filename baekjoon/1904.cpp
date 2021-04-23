#include <iostream>
using namespace std;

// 01타일

long long N;
long long dp[1000001];

int main() {

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= 15746;
	}

	cout << dp[N];

	return 0;
}