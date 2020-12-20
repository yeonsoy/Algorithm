#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 줄세우기
// LIS 알고리즘 사용

int N;
vector<int> dp;
vector<int> child;

int main() {

	cin >> N;

	dp.resize(N);
	child.resize(N);

	for (int i = 0; i < N; i++)
		cin >> child[i];

	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (child[j] < child[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
	}

	int answer = N - *max_element(dp.begin(), dp.end());
	cout << answer;

	return 0;
}