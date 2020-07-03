#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 불!

typedef pair<int, int> point;
int R, C;
char map[1001][1001];
int fire_map[1001][1001];
bool visited[1001][1001];
point dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
point jihoon;

int main() {
    
    cin >> R >> C;
    queue <pair<point, int>> que;
    memset(fire_map, -1, sizeof(fire_map));
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'J')
                jihoon = {i, j};
            else if(map[i][j] == 'F')
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
    
    que.push({jihoon, 0});
    
    while(!que.empty()) {
        point p = que.front().first;
        int time = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= R || c < 0 || c >= C) {
                cout << time + 1 << endl;
                exit(0);
            }
            if(visited[r][c]) continue;
            
            if(map[r][c] == '.' && (fire_map[r][c] > time + 1 || fire_map[r][c] == -1)) {
                visited[r][c] = true;
                que.push({{r, c}, time + 1});
            }
        }
    }
    
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
