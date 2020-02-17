#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321;

typedef pair<int, int> point;

int N, M;
vector <point> graph[1001];
int dist[1001];
int parent[1001];

// 완전쌍방향 방식 (양방향 그래프)
// 직접 연결되어 있는 회선이 오히려 더 느려서, 다른 컴퓨터를 통해서 통신을 하는 것이 더 유리할 수도 있다
// 다익스트라 + 최소 스패닝 트리
// 최소한의 경로 개수로 최소 거리를 가지는 경로

void dijkstra() {
    
    priority_queue<point, vector<point>, greater<point>> que;
    
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=N; j++)
            dist[i] = INF;

    dist[1] = 0;
    que.push({dist[1], 1});
    
    while(!que.empty()) {
        
        auto top = que.top();
        int d = top.first;
        int from = top.second;
        que.pop();
        
        if(dist[from] < d) continue; // 현재 최단 경로보다 크다면
        
        for(int i = 0; i<graph[from].size(); i++) // 현재 정점에 연결된 모든 경로
        {
            int to = graph[from][i].first; // 연결된 정점 번호
            int to_d = graph[from][i].second; // 간선 거리
            
            if(dist[to] > to_d + d) // 직접 연결되어 있는 회선보다 거쳐가는 길이 빠르다면
            {
                dist[to] = to_d + d;
                que.push({dist[to], to});
                
                parent[to] = from;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i<M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    dijkstra();
    
    cout << N - 1 << endl; // MST의 간선개수
    for(int i = 2; i<=N; i++)
        cout << parent[i] << " " << i << endl;
    
    return 0;
}
