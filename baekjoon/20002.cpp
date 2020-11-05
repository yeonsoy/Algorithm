#include <iostream>
using namespace std;

// 사과나무

int N;
int answer = -1001;
int map[301][301];
int sum[301][301];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			sum[i][j] = map[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			answer = max(answer, map[i][j]);
		}

	for (int i = 2; i <= N; i++)
		for (int j = i; j <= N; j++)
			for (int k = i; k <= N; k++)
				answer = max(answer, sum[j][k] - sum[j - i][k] - sum[j][k - i] + sum[j - i][k - i]);

	cout << answer;
}