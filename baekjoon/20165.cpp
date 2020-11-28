#include <iostream>
#include <queue>
using namespace std;

// 인내의 도미노 장인 호석

typedef pair<int, int> point;
int N, M, R;
int map[101][101];
bool falldown[101][101];
int answer;

void go(int a, int b, int dir)
{

	queue <point> que;
	que.push({ a, b });
	falldown[a][b] = true;
	answer++;

	while (!que.empty())
	{
		point p = que.front();
		que.pop();

		int r = p.first;
		int c = p.second;

		if (dir == 'E')
		{
			for (int i = c + 1; i < M && i < c + map[r][c]; i++)
			{
				if (!falldown[r][i])
				{
					falldown[r][i] = true;
					answer++;
					que.push({ r, i });
				}
			}
		}
		else if (dir == 'W')
		{
			for (int i = c - 1; i >= 0 && i > c - map[r][c]; i--)
			{
				if (!falldown[r][i])
				{
					falldown[r][i] = true;
					answer++;
					que.push({ r, i });
				}
			}
		}
		else if (dir == 'S')
		{
			for (int i = r + 1; i < N && i < r + map[r][c]; i++)
				if (!falldown[i][c])
				{
					falldown[i][c] = true;
					answer++;
					que.push({ i, c });
				}
		}
		else
		{
			for (int i = r - 1; i >= 0 && i > r - map[r][c]; i--)
				if (!falldown[i][c])
				{
					falldown[i][c] = true;
					answer++;
					que.push({ i, c });
				}
		}
	}
}

void print()
{
	cout << answer << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << (falldown[i][j] ? 'F' : 'S') << ' ';

		cout << "\n";
	}
}

int main() {

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
	{
		int r, c;
		char dir;

		cin >> r >> c >> dir;

		if (!falldown[r - 1][c - 1])
			go(r - 1, c - 1, dir);

		cin >> r >> c;

		if (falldown[r - 1][c - 1])
			falldown[r - 1][c - 1] = false;
	}

	print();

	return 0;
}