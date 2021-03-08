#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 숨바꼭질 2

int N, K;

const int MAX_INT = 100000 + 1;
bool visited[MAX_INT];
int answer, cnt;

struct node
{
	int pos;
	int count;
};

int main()
{
	// 걷기 +1 -1
	// 순간이동 *2

	cin >> N >> K;

	queue <node> que;
	que.push({ N, 0 });
	visited[N] = true;

	while (!que.empty())
	{
		int X = que.front().pos;
		int cur = que.front().count;
		int dir[3] = { X + 1, X - 1, X * 2 };
		que.pop();

		visited[X] = true;

		if (answer != 0 && answer == cur && X == K)
			cnt++;

		if (answer == 0 && X == K)
		{
			answer = cur;
			cnt++;
		}

		for (int i = 0; i < 3; i++)
		{
			if (dir[i] < 0 || dir[i] > MAX_INT)
				continue;

			if (!visited[dir[i]])
				que.push({ dir[i], cur + 1 });
		}
	}

	cout << answer << "\n" << cnt << "\n";


	return 0;
}