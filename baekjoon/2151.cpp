#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 거울 설치

typedef pair<int, int> point;
int N;
char map[51][51];
int visited[51][51][4];
vector <point> door;
int answer = 2e9;
point dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == '#')
                door.push_back({i, j});
            
            visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = visited[i][j][3] = 2e9;
        }
    
    queue <pair<point, int>> que;
    
    for(int i = 0; i<4; i++) {
        visited[door[0].first][door[0].second][i] = 0;
        que.push({door[0], i});
    }
    
    while(!que.empty()) {
        
        point p = que.front().first;
        int d = que.front().second;
        que.pop();
        
        int r = p.first + dir[d].first;
        int c = p.second + dir[d].second;
        
        if(r < 0 || r >= N || c < 0 || c >= N) continue;
        if(map[r][c] == '*') continue;
        
        // 거울 설치할 수 있는 지점
        if(map[r][c] == '!') {
            // 거울 설치 없이 통과
            if(visited[r][c][d] > visited[p.first][p.second][d]) {
                visited[r][c][d] = visited[p.first][p.second][d];
                que.push({{r, c}, d});
            }
            
            int dir1, dir2;
            if(d == 0 || d == 1) {
                dir1 = 2;
                dir2 = 3;
            }
            else {
                dir1 = 0;
                dir2 = 1;
            }
            
            // 거울 설치 방향 변경 1
            if(visited[r][c][dir1] > visited[p.first][p.second][d] + 1) {
                visited[r][c][dir1] = visited[p.first][p.second][d] + 1;
                que.push({{r, c}, dir1});
            }
            // 거울 설치 방향 변경 2
            if(visited[r][c][dir2] > visited[p.first][p.second][d] + 1) {
                visited[r][c][dir2] = visited[p.first][p.second][d] + 1;
                que.push({{r, c}, dir2});
            }
        }
        // 빛이 통과할 수 있는 지점
        else if(map[r][c] == '.') {
            if(visited[r][c][d] > visited[p.first][p.second][d]) {
                visited[r][c][d] = visited[p.first][p.second][d];
                que.push({{r, c}, d});
            }
        }
        
        // 문에 도착
        else if(map[r][c] == '#') {
            if(visited[r][c][d] > visited[p.first][p.second][d])
                visited[r][c][d] = visited[p.first][p.second][d];
        }
        
    }
    
    for(int i = 0; i<4; i++)
        answer = min(answer, visited[door[1].first][door[1].second][i]);
    
    cout << answer << endl;
    
    return 0;
}
