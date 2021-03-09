#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 숨바꼭질 3

int N, K;

const int MAX_INT = 100000 + 1;
bool visited[MAX_INT];
int answer = MAX_INT;

int main()
{
	// 걷기 +1 -1
	// 순간이동 *2

	cin >> N >> K;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });
	visited[N] = true;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int X = pq.top().second;
		int dir[3] = { X * 2, X - 1, X + 1 }; // 순간 이동 시에는 0초가 걸리기 때문에 가장 우선적으로 큐에 넣어준다.
		pq.pop();

		if (X == K)
		{
			answer = cur;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			if (dir[i] < 0 || dir[i] >= MAX_INT)
				continue;

			if (!visited[dir[i]])
			{
				if (i != 0)
					pq.push({ cur + 1, dir[i] });
				else
					pq.push({ cur, dir[i] });

				visited[dir[i]] = true;
			}
		}
	}

	cout << answer;

	return 0;
}