#include <iostream>
#include <queue>
using namespace std;

// 화살표 미로 (Easy)

typedef pair<int, int> point;
int R, C;
int K;
string answer = "No";
char map[51][51];
int dirMap[51][51];
point dir[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
bool visited[51][51][151][151];

struct sheet {
	point p;
	int remain_left;
	int remain_right;
};

enum dirOrder {
	UP, RIGHT, DOWN, LEFT
};

dirOrder converToDirection(char ch) {

	switch (ch)
	{
	case 'U':
		return UP;
		break;
	case 'D':
		return DOWN;
		break;
	case 'L':
		return LEFT;
		break;
	case 'R':
		return RIGHT;
		break;
	}
}

void go() {
	queue <sheet> que;
	que.push({ {0,0}, K, K });
	visited[0][0][K][K] = true;

	for (int i = 0; i <= K; i++)
		for (int j = 0; j <= K; j++)
			visited[0][0][i][j] = true;

	while (!que.empty()) {
		point p = que.front().p;
		int cur = dirMap[p.first][p.second];
		int left = que.front().remain_left;
		int right = que.front().remain_right;
		que.pop();

		if (p.first == R - 1 && p.second == C - 1)
		{
			cout << "Yes";
			exit(0);
		}

		int r = p.first + dir[cur].first;
		int c = p.second + dir[cur].second;

		if (r >= 0 && r < R && c >= 0 && c < C)
			if (!visited[r][c][left][right]) {
				visited[r][c][left][right] = true;
				que.push({ {r, c}, left, right });
			}

		if (left == 0 && right == 0)
			continue;

		int temp = cur;
		for (int i = 0; i < 3 && i < left; i++)
		{
			temp--;
			if (temp < 0) temp = 3;

			int r = p.first + dir[temp].first;
			int c = p.second + dir[temp].second;

			if (r >= 0 && r < R && c >= 0 && c < C)
				if (!visited[r][c][left - i - 1][right])
				{
					visited[r][c][left - i - 1][right] = true;
					que.push({ {r, c}, left - i - 1, right });
				}
		}

		temp = cur;
		for (int i = 0; i < 3 && i < right; i++)
		{
			temp++;
			if (temp > 3) temp = 0;

			int r = p.first + dir[temp].first;
			int c = p.second + dir[temp].second;

			if (r >= 0 && r < R && c >= 0 && c < C)
				if (!visited[r][c][left][right - i - 1])
				{
					visited[r][c][left][right - i - 1] = true;
					que.push({ {r, c}, left, right - i - 1 });
				}
		}
	}

}

int main() {
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			dirMap[i][j] = converToDirection(map[i][j]);
		}

	go();

	cout << "No";

	return 0;
}