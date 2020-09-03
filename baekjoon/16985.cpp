#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// Maaaaaaaaaze

struct point {
    int x;
    int y;
    int z;
};

const int N = 5;
int map[N][N][N];
int temp_map[N][N][N];
bool visited[N][N][N];
int floor_order[N], rotate_info[N];
int answer = 2e9;
point dir[6] = {{0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

int bfs() {
    
    memset(visited, false, sizeof(visited));
    
    queue <pair<point, int>> que;
    que.push({{0, 0, 0}, 0});
    visited[0][0][0] = true;
    
    while(!que.empty()) {
        point p = que.front().first;
        int d = que.front().second;
        que.pop();
        
        if(p.x == N - 1 && p.y == N - 1 && p.z == N - 1) return d;
        
        for(int i = 0; i<6; i++) {
            int xx = p.x + dir[i].x;
            int yy = p.y + dir[i].y;
            int zz = p.z + dir[i].z;
            
            if(xx < 0 || xx >= N || yy < 0 || yy >= N || zz < 0 || zz >= N) continue;
            if(visited[xx][yy][zz]) continue;
            
            if(temp_map[xx][yy][zz] == 1) {
                visited[xx][yy][zz] = true;
                que.push({{xx, yy, zz}, d + 1});
            }
        }
        
    }
    
    return -1;
}

void setTempMap() {
    
    for(int i = 0; i<N; i++)
    {
        int idx = floor_order[i];
        int rotation = rotate_info[i];
        
        for(int j = 0; j<N; j++)
            for(int k = 0; k<N; k++) {
                
                int r = 0;
                int c = 0;
                
                // 0도 회전
                if(rotation == 0) {
                    r = j;
                    c = k;
                }
                // 90도 회전
                else if(rotation == 1) {
                    r = k;
                    c = N - j - 1;
                }
                // 180도 회전
                else if(rotation == 2) {
                    r = N - j - 1;
                    c = N - k - 1;
                }
                else {
                    r = N - k - 1;
                    c = j;
                }
                
                temp_map[idx][r][c] = map[i][j][k];
            }
    }
}

void setRotate(int idx) {
    
    if(idx == N) {
        setTempMap();
        // 입구와 출구가 모두 이동할 수 있다면
        if(temp_map[0][0][0] == 1 && temp_map[N - 1][N - 1][N - 1] == 1)
        {
            int res = bfs();
            if(res != -1)
                answer = min(answer, res);
        }
        
        return;
    }
    
    for(int i = 0; i<4; i++)
    {
        rotate_info[idx] = i;
        setRotate(idx + 1);
    }
}

void setFloorOrder(int idx) {
    
    if(idx == N) {
        setRotate(0);
        return;
    }
    
    for(int i = 0; i<N; i++) {
        if(floor_order[i] == -1) {
            floor_order[i] = idx;
            setFloorOrder(idx + 1);
            floor_order[i] = -1;
        }
    }
    
}

int main() {
    
    fastio();
    
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                cin >> map[i][j][k];
    
    memset(floor_order, -1, sizeof(floor_order));
    memset(rotate_info, -1, sizeof(rotate_info));
    
    setFloorOrder(0);
    
    if(answer == 2e9) answer = -1;
    
    cout << answer << endl;
    
    return 0;
}
