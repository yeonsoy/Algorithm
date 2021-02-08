#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 양치기 꿍

typedef pair<int, int> point;
int sheep;
int wolf;
vector <point> sheeps;
char map[251][251];
bool visited[251][251];
int R, C;
point dir[4] = { {0,1}, {1,0}, {0, -1}, {-1,0} };

void go(point p) {
	int s = 1;
	int w = 0;

	visited[p.first][p.second] = true;
	queue <point> que;
	que.push(p);

	while (!que.empty()) {
		point front = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int r = front.first + dir[i].first;
			int c = front.second + dir[i].second;

			if (r < 0 || r >= R || c < 0 || c >= C) continue;
			if (!visited[r][c] && map[r][c] != '#') {
				visited[r][c] = true;
				que.push({ r,c });
				if (map[r][c] == 'v')
					w++;
				else if (map[r][c] == 'k')
					s++;
			}
		}
	}

	if (s > w) {
		wolf -= w;
	}
	else
		sheep -= s;
}

int main() {

	cin >> R >> C;

	for(int i = 0; i< R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'v')
				wolf++;
			else if (map[i][j] == 'k') {
				sheep++;
				sheeps.push_back({ i, j });
			}
		}

	for (int i = 0; i < sheeps.size(); i++) {
		if (!visited[sheeps[i].first][sheeps[i].second])
			go(sheeps[i]);
	}

	cout << sheep << " " << wolf << "\n";

	return 0;
}