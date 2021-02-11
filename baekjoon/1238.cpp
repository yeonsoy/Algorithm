#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654

// 파티

typedef pair<int, int> node;
vector<vector<node>> adj;
int N, M, X;

vector<int> startX()
{
	priority_queue <node, vector<node>, greater<node>> p_que;
	vector<int> dist(N + 1, INF);

	dist[X] = 0;
	p_que.push({ dist[X], X });

	while (!p_que.empty()) // 모든 정점을 방문할 때까지
	{
		int d = p_que.top().first; // 거리
		int u = p_que.top().second; // 정점 
		p_que.pop();

		if (d > dist[u]) // 현재 정점의 최단 거리보다 d가 크면 (현재 루트로 (x,y)를 방문한 거리 d)
			continue;

		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			int w = adj[u][i].second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				p_que.push({ dist[v], v }); // 최단 거리 변경
			}
		}
	}

	return dist;
}


int startN(int n)
{
	priority_queue <node, vector<node>, greater<node>> p_que;
	vector<int> dist(N + 1, INF);

	dist[n] = 0;
	p_que.push({ dist[n], n });

	while (!p_que.empty()) // 모든 정점을 방문할 때까지
	{
		int d = p_que.top().first; // 거리
		int u = p_que.top().second; // 정점 
		p_que.pop();

		if (d > dist[u]) // 현재 정점의 최단 거리보다 d가 크면 (현재 루트로 (x,y)를 방문한 거리 d)
			continue;

		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			int w = adj[u][i].second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				p_que.push({ dist[v], v }); // 최단 거리 변경
			}
		}
	}

	return dist[X];
}

int main() {

	cin >> N >> M >> X;
	adj.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	int max = 0;

	for (int i = 1; i < startX().size(); i++)
	{
		int nowVal = startX()[i] + startN(i);
		if (max < nowVal)
			max = nowVal;
	}
	cout << max;
	return 0;
}
