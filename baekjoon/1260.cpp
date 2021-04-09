#include <iostream>
#include <queue>

using namespace std;

// DFS와 BFS

int N, M, V;
int A, B;
int** graph;
bool* visited;

void dfs(int v)
{
	cout << v << " ";
	visited[v] = true;

	for (int i = 1; i <= N; i++)
	{
		if (graph[v][i] == 1 && !visited[i])
			dfs(i);
	}
}

void bfs(int v)
{
	queue <int> que;
	que.push(v);
	visited[v] = true;

	while (!que.empty())
	{
		int front = que.front();
		que.pop();
		cout << front << " ";

		for (int i = 1; i <= N; i++)
		{
			if (graph[front][i] == 1 && !visited[i])
			{
				visited[i] = true;
				que.push(i);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	graph = new int* [N + 1];
	visited = new bool[N + 1];

	for (int i = 0; i < N + 1; i++)
		graph[i] = new int[N + 1];

	for (int x = 0; x < N + 1; x++)
		for (int y = 0; y < N + 1; y++)
			graph[x][y] = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		graph[A][B] = 1;
		graph[B][A] = 1;
	}

	for (int i = 0; i < N + 1; i++)
		visited[i] = false;

	dfs(V);
	cout << endl;

	for (int i = 0; i < N + 1; i++)
		visited[i] = false;
	bfs(V);


	return 0;
}