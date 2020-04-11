#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 이동하기

typedef pair<int, int> point;
int N, M;
int maze[1001][1001];
int answer[1001][1001];
point dir[2] = {{0,1}, {1,0}};
int sum = 0;

void solve(int r, int c) {
    
    queue <point> que;
    que.push({r, c});
    answer[r][c] = maze[r][c];
    
    while(!que.empty()) {
        int rr = que.front().first;
        int cc = que.front().second;
        que.pop();
        
        for(int i = 0; i<2; i++) {
            int nr = rr + dir[i].first;
            int nc = cc + dir[i].second;
            
            if(nr < 0 || nr >= N) continue;
            if(nc < 0 || nc >= M) continue;
            
            if(answer[nr][nc] == -1 || maze[nr][nc] + answer[rr][cc] > answer[nr][nc]) {
                answer[nr][nc] = maze[nr][nc] + answer[rr][cc];
                que.push({nr, nc});
            }
        }
    }
    
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++) {
            cin >> maze[i][j];
            answer[i][j] = -1;
        }
    
    solve(0, 0);
    
    cout << answer[N - 1][M - 1];
    
    return 0;
}
