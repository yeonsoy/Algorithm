#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전깃줄

int N;
vector <pair<int, int>> connected;
int dp[501];
int answer;

int main() {
	cin >> N;

	connected.resize(N);
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		connected[i] = { a, b };
	}

	sort(connected.begin(), connected.end());

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (connected[i].second > connected[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		answer = max(answer, dp[i]);
	}

	cout << N - answer;

	return 0;
}