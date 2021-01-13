#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int M, N;
int** box;
int** visited;

// 토마토

struct tomato {
	int x;
	int y;
};

int main()
{
	cin >> M >> N;
	queue <tomato> q;
	box = new int* [1001];
	visited = new int* [1001];

	for (int i = 0; i < 1001; i++)
	{
		box[i] = new int[1001];
		visited[i] = new int[1001];
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = -1;
			cin >> box[i][j];
			if (box[i][j] == 1) // 만약 상자에 토마토가 있다면
			{
				q.push({ i, j }); // 주변 토마토가 익을 수 있으므로 push
				visited[i][j] = 0; // 토마토가 있는 영역 방문 표시
			}
		}


	tomato dir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	while (!q.empty())
	{
		tomato now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = now.x + dir[i].x;
			int ty = now.y + dir[i].y;

			if (tx < 0 || tx >= N)
				continue;

			if (ty < 0 || ty >= M)
				continue;

			if (box[tx][ty] == 0 && visited[tx][ty] == -1) // 토마토가 익지 않았고 방문하지 않았을 때
			{
				visited[tx][ty] = visited[now.x][now.y] + 1; // 이동한 횟수 더하기
				q.push({ tx,ty });
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (answer < visited[i][j])
				answer = visited[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
				if (visited[i][j] == -1) // 만약 익지 않은 토마토가 하나라도 존재한다면
				{
					cout << -1;
					return 0;
				}
		}

	cout << answer;

	return 0;
}