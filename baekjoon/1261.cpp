#include <iostream>
#include <queue>
#define INF 987654
using namespace std;
int N, M;

// 알고스팟

struct point {
	int x;
	int y;
};

typedef pair<int, pair<int, int>> node;

int main()
{
	cin >> N >> M;
	int** maze = new int* [N + 1];

	for (int i = 0; i <= N; i++)
		maze[i] = new int[M + 1];

	for (int y = 0; y <= M; y++)
		for (int x = 0; x <= N; x++)
			maze[x][y] = 0;

	for (int y = 1; y <= M; y++)
		for (int x = 1; x <= N; x++)
			scanf("%1d", &maze[x][y]);

	point dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

	priority_queue <node, vector<node>, greater<node>> pq;

	int** count = new int* [N + 1];

	for (int i = 0; i <= N; i++)
		count[i] = new int[M + 1];

	for (int y = 0; y <= M; y++)
		for (int x = 0; x <= N; x++)
			count[x][y] = INF;

	count[1][1] = 0;
	pq.push({ count[1][1], { 1, 1 } });


	while (!pq.empty())
	{
		point nowPos = { pq.top().second.first, pq.top().second.second };
		pq.pop();

		if (nowPos.x == N && nowPos.y == M) break;

		for (int i = 0; i < 4; i++)
		{
			int tx = nowPos.x + dir[i].x;
			int ty = nowPos.y + dir[i].y;

			if (tx < 1 || ty < 1)
				continue;

			if (tx > N || ty > M)
				continue;

			if (maze[tx][ty])
			{
				if (count[tx][ty] > count[nowPos.x][nowPos.y] + 1)
				{
					count[tx][ty] = count[nowPos.x][nowPos.y] + 1;
					pq.push({ count[tx][ty], { tx, ty } });
				}
			}
			else
			{
				if (count[tx][ty] > count[nowPos.x][nowPos.y])
				{
					count[tx][ty] = count[nowPos.x][nowPos.y];
					pq.push({ count[tx][ty], { tx, ty } });
				}
			}
		}
	}

	cout << count[N][M];

	return 0;
}