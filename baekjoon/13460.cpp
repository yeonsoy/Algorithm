#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 구슬 탈출 2

// 빨간 구슬과 파란 구슬 1개씩 넣고 빨간 구슬을 빼내는 게임
// 왼쪽, 오른쪽, 위쪽, 아래쪽 움직이기 가능
// 각각의 동작에서 공은 동시에 움직임 (둘은 겹쳐질 수 없다)
// 파란 구슬이 구멍에 빠지면 실패
// N * M

int N, M;
char board[12][12];
int answer, escape_count;
bool visited[12][12][12][12];

struct point {
	int r;
	int c;
};

point dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
point blue, red;
point next_red, next_blue;

void bfs()
{
	queue <pair<point, point>> que;
	visited[red.r][red.c][blue.r][blue.c] = true;
	que.push({ red, blue });

	while (!que.empty()) {
		int len = que.size();

		while (len--)
		{
			auto front = que.front();
			point front_red = { front.first.r, front.first.c };
			point front_blue = { front.second.r, front.second.c };
			que.pop();

			if (board[front_red.r][front_red.c] == 'O' && board[front_blue.r][front_blue.c] != 'O') // 도착점에 빨간 공이 도달한다면 종료
			{
				answer = escape_count;
				return;
			}

			for (int i = 0; i < 4; i++) {

				red = { front_red.r, front_red.c };
				blue = { front_blue.r, front_blue.c };

				while (true) { // 빨간 구슬
					next_red = { red.r + dir[i].r, red.c + dir[i].c };
					if (board[next_red.r][next_red.c] == '#' || board[red.r][red.c] == 'O') break; // 벽이나 구멍을 만나면
					red.r = next_red.r;
					red.c = next_red.c; // 같은 방향으로 계속 이동
				}

				while (true) { // 파란 구슬
					next_blue = { blue.r + dir[i].r, blue.c + dir[i].c };
					if (board[next_blue.r][next_blue.c] == '#' || board[blue.r][blue.c] == 'O') break; // 벽이나 구멍을 만나면
					blue.r = next_blue.r;
					blue.c = next_blue.c; // 같은 방향으로 계속 이동
				}

				if (red.r == blue.r && red.c == blue.c) { // 빨간 구슬과 파란 구슬의 위치가 같을 때
					if (board[blue.r][blue.c] == 'O') continue; // 파란 구슬이 구멍에 빠진 경우

					int diff_red = abs(front_red.r - red.r) + abs(front_red.c - red.c); // 빨간 구슬 변경된 양
					int diff_blue = abs(front_blue.r - blue.r) + abs(front_blue.c - blue.c); // 파란 구슬 변경된 양

					if (diff_red > diff_blue) // 빨간색 공이 더 많이 움직였다면
						red = { red.r - dir[i].r, red.c - dir[i].c };
					else
						blue = { blue.r - dir[i].r, blue.c - dir[i].c };
				}

				if (visited[red.r][red.c][blue.r][blue.c])
					continue;

				visited[red.r][red.c][blue.r][blue.c] = true;

				que.push({ red, blue });
			}

		}
		if (escape_count == 10)
		{
			answer = -1;
			return;
		}
		escape_count++;
	}

	answer = -1;
	return;

}

int main()
{
	cin >> N >> M;


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'B')
				blue = { i, j };
			if (board[i][j] == 'R')
				red = { i, j };
		}

	board[blue.r][blue.c] = '.';
	board[red.r][red.c] = '.';

	bfs();

	cout << answer;

	return 0;
}