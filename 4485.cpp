#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321;
typedef pair<int, int> point;

int N;
int cave[126][126];
int dist[126][126];
vector <int> answer;
point dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

// 녹색 옷 입은 애가 젤다지?
// 현 위치는 0, 0
// N-1, N-1 까지 이동해야 함.
// 이동할 때마다 특정 크기의 소지금을 잃게 됨 (가중치)
// 최소 가중치로 이동하기 위해서 다익스트라 알고리즘 사용

void dijkstra(int r, int c) {
    priority_queue<pair<int, point>, vector<pair<int, point>>, greater<>> que;
    
    for(int i =0; i<N; i++)
        for(int j = 0; j<N; j++)
            dist[i][j] = INF;
    
    dist[r][c] = cave[r][c]; // 시작점의 가중치를 초기화
    que.push({dist[r][c], {r,c}});
    
    while(!que.empty()) {
        
        auto top = que.top();
        int d = top.first;
        int r = top.second.first;
        int c = top.second.second;
        que.pop();
        
        if(d > dist[r][c]) continue; // 현재 정점에 적혀있는 최소 거리보다 크다면
        
        for(int i = 0; i<4; i++) {
            
            int tr = r + dir[i].first;
            int tc = c + dir[i].second;
            
            if(tr < 0 || tr >= N) continue;
            if(tc < 0 || tc >= N) continue;
            
            if(dist[tr][tc] > dist[r][c] + cave[tr][tc])
            {
                dist[tr][tc] = dist[r][c] + cave[tr][tc];
                // tr tc정점으로 바로 가는 경로보다 r c정점을 거쳐 tr tc로 가는 거리가 짧다면
                que.push({dist[tr][tc], {tr, tc}});
            }
        }
    }
    
    answer.push_back (dist[N - 1][N - 1]);
    
}


int main()
{
    while(true) {
        cin >> N;
        
        if(N == 0) break;
        for(int i =0; i<N; i++)
            for(int j = 0; j<N; j++)
                cin >> cave[i][j];
        
        dijkstra(0, 0);
        
    }
    
    for(int i = 0; i<answer.size(); i++)
        cout << "Problem " << i + 1 <<": " << answer[i] << endl;
    
    return 0;
}
