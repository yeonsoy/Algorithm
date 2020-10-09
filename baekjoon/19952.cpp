#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 인성 문제 있어??

typedef pair<int, int> point;
int T;
int H, W, O, F;
point S, E;
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int map[101][101];
int visited[101][101];

bool isPossible() {
    
    queue <pair<point, int>> que;
    
    que.push({S, F});
    visited[S.first][S.second] = F;
    
    while(!que.empty()) {
        point p = que.front().first;
        int force = que.front().second;
        que.pop();
        
        if(force < 0) continue;
        
        if(p.first == E.first && p.second == E.second)
            return true;
        
        for(int i = 0; i<4; i++) {
            
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= H || c < 0 || c >= W) continue;

            if(map[r][c] - map[p.first][p.second] <= force)
            {
                if(force - 1 >= 0 && visited[r][c] < force - 1) {
                    visited[r][c] = force - 1;
                    que.push({{r, c}, force - 1});
                }
            }
        }
    }
    
    return false;
}

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> H >> W >> O >> F >> S.first >> S.second >> E.first >> E.second;
        
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        
        S.first--; S.second--;
        E.first--; E.second--;
        
        int r, c, f;
        
        for(int i = 0; i<O; i++)
        {
            cin >> r >> c >> f;
            map[r - 1][c - 1] = f;
        }
        
        if(isPossible()) cout << "잘했어!!" << endl;
        else cout << "인성 문제있어??" << endl;
        
    }
    
    return 0;
}
