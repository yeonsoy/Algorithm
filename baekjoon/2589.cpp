#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 보물섬
// 상하좌우 이웃한 육지로만 이동 가능
// 보물은 서로 간에 최단 거리로 이동하는데 있어 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다

typedef pair<int, int> point;
int N, M;
char maps[51][51];
int dist[51][51];
point dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int answer;

int main()
{
    queue <point> land;
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++)
        {
            cin >> maps[i][j];
            if(maps[i][j] == 'L')
                land.push({i, j});
        }
    }
    
    while(!land.empty()){
        auto st = land.front();
        land.pop();
        
        queue <point> que;
        que.push(st);
        
        while(!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            
            for(int i = 0; i<4; i++) {
                int rr = r + dir[i].first;
                int cc = c + dir[i].second;
                
                if(rr < 0 || rr >= N) continue;
                if(cc < 0 || cc >= M) continue;
                if(rr == st.first && cc == st.second) continue;
                
                if(maps[rr][cc] == 'L')
                    if(!dist[rr][cc] || dist[rr][cc] > dist[r][c] + 1) {
                        dist[rr][cc] = dist[r][c] + 1;
                        que.push({rr, cc});
                    }
            }
        }
        
        for(int i = 0; i<N; i++)
            for(int j = 0; j<M; j++)
                if(dist[i][j])
                    answer = max(answer, dist[i][j]);
        
        memset(dist, 0, sizeof(dist));
    }
    
    cout << answer;
    
    return 0;
}
