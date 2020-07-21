#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 불켜기

typedef pair<int, int> point;
int N, M;
int answer;
int room[101][101];
bool visited[101][101];
bool checked[101][101];
vector <point> sw[101][101];
point dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    
    fastio();
    
    cin >> N >> M;
    
    room[0][0] = 1;
    
    int x, y, a, b;
    for(int i = 0; i<M; i++) {
        cin >> x >> y >> a >> b;
        sw[x - 1][y - 1].push_back({a - 1, b - 1});
    }
    
    queue <point> que;
    que.push({0, 0});
    visited[0][0] = true;
    
    while(!que.empty()) {
        point p = que.front();
        que.pop();
        // 현재 점에서 갈 수 있는 모든 방을 체크했는가
        checked[p.first][p.second] = true;
        
        for(int i = 0; i<sw[p.first][p.second].size(); i++) {
            int r = sw[p.first][p.second][i].first;
            int c = sw[p.first][p.second][i].second;
            room[r][c] = 1;
            
            for(int j = 0; j<4; j++) {
                int rr = r + dir[j].first;
                int cc = c + dir[j].second;
                
                if(rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
                
                // 현재 점에서 갈 수 있는 모든 방이 이미 갔던 곳에서 이동할 수 있는 방이라면
                if(visited[rr][cc] && !checked[r][c]) {
                    visited[r][c] = true;
                    que.push({r, c});
                    break;
                }
            }
        }
        
        for(int i = 0; i<4; i++) {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= N || c < 0 || c >= N) continue;
            // 이미 갔던 방 제외
            if(visited[r][c]) continue;
            
            // 불이 켜져있는 방은 방문할 수 있다
            if(room[r][c] == 1) {
                visited[r][c] = true;
                que.push({r, c});
            }
        }
    }
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            if(room[i][j] == 1)
                answer++;
    
    cout << answer << "\n";
    
    return 0;
}
