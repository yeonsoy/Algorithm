#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 숨바꼭질 

int N, K;

const int MAX_INT = 100000 + 1;
bool visited[MAX_INT];

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
		int nowPos = que.front().pos;
		int nowCount = que.front().count;
		int dir[3] = { nowPos + 1, nowPos - 1, nowPos * 2 };
		que.pop();

		if (nowPos == K)
		{
			cout << nowCount;
			return 0;
		}

		for (int i = 0; i < 3; i++)
		{
			if (dir[i] < 0 || dir[i] > MAX_INT)
				continue;

			if (!visited[dir[i]])
			{
				visited[dir[i]] = true;
				que.push({ dir[i], nowCount + 1 });
			}
		}

	}
	return 0;
}