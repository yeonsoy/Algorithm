#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// 반도체 설계

int N;
vector <int> connected;
int dp[40001];
int answer = 1;

int main() {
	fastio();

	cin >> N;

	connected.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> connected[i];

	dp[answer] = connected[1];

	for (int i = 2; i <= N; i++) {
		if (dp[answer] < connected[i])
			dp[++answer] = connected[i];
		else {
			int idx = lower_bound(dp + 1, dp + answer + 1, connected[i]) - dp;
			dp[idx] = connected[i];
		}
	}

	cout << answer;

	return 0;
}