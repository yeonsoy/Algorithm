#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 미세먼지 안녕!

typedef pair<int, int> point;
int R, C, T;
vector <point> air_clener;
queue <point> que;
int map[51][51];
int cur[51][51];
point dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    
    cin >> R >> C >> T;
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == -1)
                air_clener.push_back({i, j});
            else if(map[i][j] > 0)
                que.push({i, j});
            
        }
    
    for(int time = 0; time<T; time++) {
        
        while(!que.empty()) {
            point p = que.front();
            que.pop();
            int d = 0;
            
            for(int i = 0; i<4; i++) {
                int r = p.first + dir[i].first;
                int c = p.second + dir[i].second;
                
                if(r < 0 || r >= R || c < 0 || c >= C) continue;
                if(map[r][c] == -1) continue;
                
                cur[r][c] = (map[p.first][p.second] / 5) + cur[r][c];
                d++;
            }
            
            cur[p.first][p.second] += map[p.first][p.second] - (map[p.first][p.second] / 5) * d;
            if(cur[p.first][p.second] <= 0)
                cur[p.first][p.second] = 0;
        }
         
        point top = air_clener[0];
        int temp = cur[top.first][C - 1];
        
        // 위 - 오른쪽
        for(int i = C - 1; i > 0; i--)
            cur[top.first][i] = cur[top.first][i - 1];
        
        // 위 - 위쪽
        for(int i = top.first - 1; i >= 0; i--)
            swap(temp, cur[i][C - 1]);
        
        // 위 - 왼쪽
        for(int i = C - 2; i >= 0; i--)
            swap(temp, cur[0][i]);
        
        // 위 - 아래쪽
        for(int i = 1; i < top.first; i++)
            swap(temp, cur[i][0]);
        
        point bottom = air_clener[1];
        temp = cur[bottom.first][C - 1];
        
        // 아래 - 오른쪽
        for(int i = C - 1; i > 0; i--)
            cur[bottom.first][i] = cur[bottom.first][i - 1];
        
        // 아래 - 아래쪽
        for(int i = bottom.first + 1; i < R; i++)
            swap(temp, cur[i][C - 1]);
        
        // 아래 - 왼쪽
        for(int i = C - 2; i >= 0; i--)
            swap(temp, cur[R - 1][i]);
        
        // 아래 - 위쪽
        for(int i = R - 2; i > bottom.first; i--)
            swap(temp, cur[i][0]);
        
        memset(map, 0, sizeof(map));
        map[air_clener[0].first][air_clener[0].second] = -1;
        map[air_clener[1].first][air_clener[1].second] = -1;
        
        for(int i = 0; i<R; i++)
            for(int j = 0; j<C; j++)
                if(map[i][j] != -1) {
                    map[i][j] = cur[i][j];
                    if(map[i][j] > 0)
                        que.push({i, j});
                }
        
        memset(cur, 0, sizeof(cur));
    }
    
    int answer = 0;
    for(int i = 0; i<R; i++) {
        for(int j = 0; j<C; j++)
            if(map[i][j] != -1)
                answer += map[i][j];
    }
    
    cout << answer << endl;
    return 0;
}
