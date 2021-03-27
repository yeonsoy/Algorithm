#include <iostream>
#include <queue>
using namespace std;

// 아기 상어 2

typedef pair<int, int> point;
int N, M;
int shark[51][51];
int visited[51][51];
queue <pair<point, int>> que;
point dir[8] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
int answer = -1;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> shark[i][j];
			visited[i][j] = -1 + shark[i][j];

			if (shark[i][j] == 1)
				que.push({ { i, j }, 0 });
		}

	while (!que.empty()) {
		point p = que.front().first;
		int d = que.front().second;
		que.pop();

		for (int i = 0; i < 8; i++) {
			int r = p.first + dir[i].first;
			int c = p.second + dir[i].second;

			if (r < 0 || r >= N || c < 0 || c >= M) continue;
			if (shark[r][c] == 1) continue;

			if (visited[r][c] == -1 || visited[r][c] > d + 1) {
				visited[r][c] = d + 1;
				que.push({ {r, c}, d + 1 });
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			answer = max(answer, visited[i][j]);

	cout << answer << "\n";

	return 0;
}