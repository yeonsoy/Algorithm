#include <iostream>
#include <vector>
using namespace std;

// 평범한 배낭

struct stuff {
	int W;
	int V;
};

int N, K;
vector <stuff> knapsack;
int dp[101][100001];
int answer;

int main() {

	cin >> N >> K;
	knapsack.resize(N);

	for (int i = 0; i < N; i++)
		cin >> knapsack[i].W >> knapsack[i].V;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
		{
			if (knapsack[i - 1].W <= j)
				dp[i][j] = max(knapsack[i - 1].V + dp[i - 1][j - knapsack[i - 1].W], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];

			answer = max(dp[i][j], answer);
		}

	cout << answer << "\n";
	return 0;
}