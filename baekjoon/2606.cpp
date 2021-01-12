#include <iostream>
#include <queue>
using namespace std;

// 바이러스

int N, M;
int** graph;
bool visited[1001];
void bfs(int start) {
	queue<int> q;
	int count = 0;

	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			int next = graph[front][i];
			if (!visited[i] && next == 1) {
				visited[i] = true;
				count++;
				q.push(i);
			}
		}
	}

	cout << count;
}

int main() {

	cin >> N >> M;
	graph = new int* [N + 1];

	for (int i = 0; i <= N; i++)
		graph[i] = new int[N + 1];

	for (int x = 0; x <= N; x++)
	{
		for (int y = 0; y <= N; y++)
			graph[x][y] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	bfs(1);

	return 0;
}
