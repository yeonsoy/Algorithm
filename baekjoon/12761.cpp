#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 돌다리

const int MAX_INT = 100000 + 1;

int A, B, N, M;
bool visited[MAX_INT];

struct node {
	int pos;
	int count;
};

int BFS()
{
	queue <node> que;

	int start = N;
	que.push({ start, 0 });
	visited[start] = true;

	while (!que.empty())
	{
		int nowPos = que.front().pos;
		int nowCount = que.front().count;
		int dir[] = { nowPos + A, nowPos + B, nowPos - A, nowPos - B, nowPos * A, nowPos * B, nowPos + 1, nowPos - 1 };
		que.pop();

		if (nowPos == M)
			return nowCount;

		for (int i = 0; i < 8; i++)
		{
			if (dir[i] < 0 || dir[i] > MAX_INT || visited[dir[i]])
				continue;
			else
			{
				visited[dir[i]] = true;
				que.push({ dir[i], nowCount + 1 });
			}
		}
	}

	return 0;

}

int main() {


	cin >> A >> B >> N >> M;

	cout << BFS();

	return 0;
}
