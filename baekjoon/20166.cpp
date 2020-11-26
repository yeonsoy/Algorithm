#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 문자열 지옥에 빠진 호석

typedef pair<int, int> point;
point dir[8] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

int N, M, K;
char hell[11][11];
vector <string> god;
map <string, int> m;
int answer;

void solve(int r, int c, int cur, int idx, string t)
{
	if (cur == god[idx].size())
	{
		answer++;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		int rr = r + dir[i].first;
		int cc = c + dir[i].second;

		if (rr < 0) rr = N - 1;
		if (cc < 0) cc = M - 1;
		if (rr >= N) rr = 0;
		if (cc >= M) cc = 0;

		if (hell[rr][cc] == god[idx][cur])
			solve(rr, cc, cur + 1, idx, t + god[idx][cur]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> hell[i][j];

	god.resize(K);

	for (int i = 0; i < K; i++)
		cin >> god[i];

	for (int i = 0; i < K; i++) {

		if (!m[god[i]]) {
			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++)
					if (hell[j][k] == god[i][0])
						solve(j, k, 1, i, god[i][0] + "");

			m[god[i]] = answer;
		}
		else
			answer = m[god[i]];

		cout << answer << "\n";
		answer = 0;
	}

	return 0;
}