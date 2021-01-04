#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 치즈

typedef pair<int, int> point;
int N, M;
int map[101][101];
int air[101][101];
int answer;
point dir[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void checkAir()
{
	memset(air, 0, sizeof(air));
	queue <point> que;
	que.push({ 0, 0 });
	air[0][0] = 1;

	while (!que.empty())
	{
		point p = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int r = dir[i].first + p.first;
			int c = dir[i].second + p.second;

			if (r < 0 || r >= N || c < 0 || c >= M)
				continue;

			if (map[r][c] == 0 && air[r][c] != 1) {
				que.push({ r, c });
				air[r][c] = 1;
			}
		}
	}
}

bool isMelt(int r, int c)
{
	int air_count = 0;
	for (int i = 0; i < 4; i++)
	{
		int rr = dir[i].first + r;
		int cc = dir[i].second + c;
		if (air[rr][cc] == 1)
			air_count++;
	}

	return (air_count >= 2);
}

bool isEnd()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
				return false;

	return true;
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	while (true)
	{
		answer++;
		checkAir();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 1)
					if (isMelt(i, j))
						map[i][j] = 0;

		if (isEnd())
			break;
	}

	cout << answer << "\n";

	return 0;
}