#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 불

typedef pair<int, int> point;
int T;
int R, C;
char map[1001][1001];
int fire_map[1001][1001];
bool visited[1001][1001];
point dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
point sangeun;

int main() {
    
    fastio();
    
    cin >> T;
    
    while(true) {
        cin >> C >> R;
        queue <pair<point, int>> que;
        memset(visited, false, sizeof(visited));
        memset(fire_map, -1, sizeof(fire_map));
        for(int i = 0; i<R; i++)
            for(int j = 0; j<C; j++) {
                cin >> map[i][j];
                
                if(map[i][j] == '@')
                    sangeun = {i, j};
                else if(map[i][j] == '*')
                {
                    que.push({{i, j}, 0});
                    fire_map[i][j] = 0;
                }
            }
        
        while(!que.empty()) {
            point p = que.front().first;
            int time = que.front().second;
            que.pop();
            
            for(int i = 0; i<4; i++) {
                int r = p.first + dir[i].first;
                int c = p.second + dir[i].second;
                
                if(r < 0 || r >= R || c < 0 || c >= C) continue;
                if(visited[r][c]) continue;
                
                if(map[r][c] == '.' && fire_map[r][c] == -1) {
                    visited[r][c] = true;
                    fire_map[r][c] = time + 1;
                    que.push({{r, c}, fire_map[r][c]});
                }
            }
        }
        
        memset(visited, false, sizeof(visited));
        
        que.push({sangeun, 0});
        
        
        bool flag = false;
        while(!que.empty()) {
            point p = que.front().first;
            int time = que.front().second;
            que.pop();
            
            for(int i = 0; i<4; i++) {
                int r = p.first + dir[i].first;
                int c = p.second + dir[i].second;
                
                if(r < 0 || r >= R || c < 0 || c >= C) {
                    cout << time + 1 << endl;
                    flag = true;
                    break;
                }
                if(visited[r][c]) continue;
                
                if(map[r][c] == '.' && (fire_map[r][c] > time + 1 || fire_map[r][c] == -1)) {
                    visited[r][c] = true;
                    que.push({{r, c}, time + 1});
                }
            }
            if(flag) break;
        }
        
        if(!flag)
            cout << "IMPOSSIBLE" << "\n";
        
        T--;
        
        if(T == 0) break;
    }
    
    return 0;
}
