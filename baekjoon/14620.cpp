#include <iostream>
using namespace std;

// 꽃길

int N;
int road[11][11];
bool visited[11][11];
int answer = 2e9;

int getCost(int r, int c) {
	return road[r - 1][c] + road[r][c] + road[r][c - 1] + road[r][c + 1] + road[r + 1][c];
}

void check(int idx, int sum) {

	if (idx == 3) {
		answer = min(answer, sum);
		return;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i - 1 < 0 || i + 1 >= N || j - 1 < 0 || j + 1 >= N) continue;

			if (!visited[i - 1][j] && !visited[i][j] && !visited[i][j - 1] && !visited[i][j + 1] && !visited[i + 1][j])
			{
				visited[i - 1][j] = true;
				visited[i][j - 1] = true;
				visited[i][j] = true;
				visited[i][j + 1] = true;
				visited[i + 1][j] = true;

				check(idx + 1, sum + getCost(i, j));

				visited[i - 1][j] = false;
				visited[i][j - 1] = false;
				visited[i][j] = false;
				visited[i][j + 1] = false;
				visited[i + 1][j] = false;
			}
		}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> road[i][j];


	check(0, 0);

	cout << answer << "\n";

	return 0;
}