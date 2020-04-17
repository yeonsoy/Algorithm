
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 미로 탈출

typedef pair<int, int> point;
int N, M;
int Hx, Hy;
int Ex, Ey;
int maze[1001][1001];
int length[1001][1001][2];
point dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int solve(int r, int c) {

    queue <pair<point, int>> que;
    que.push({{r, c}, 1});
    length[r][c][1] = 1;
    
    while(!que.empty()) {
        
        point front = que.front().first;
        int isBreak = que.front().second;
        que.pop();
        
        if(front.first == Ex - 1 && front.second == Ey - 1)
            return length[Ex - 1][Ey - 1][isBreak] - 1;
        
        for(int i = 0; i<4; i++)
        {
            int rr = front.first + dir[i].first;
            int cc = front.second + dir[i].second;
            
            if(rr < 0 || rr >= N) continue;
            if(cc < 0 || cc >= M) continue;

            // 벽이 없고 방문하지 않았을 때
            if(maze[rr][cc] == 0 && length[rr][cc][isBreak] == 0) {
                length[rr][cc][isBreak] = length[front.first][front.second][isBreak] + 1;
                que.push({{rr, cc}, isBreak});
            }
            // 벽을 부수지 않았을 때 벽을 만났다면
            else if(maze[rr][cc] == 1 && length[rr][cc][isBreak - 1] == 0 && isBreak == 1) {
                length[rr][cc][isBreak - 1] = length[front.first][front.second][isBreak] + 1;
                que.push({{rr, cc}, isBreak - 1});
            }
        }
        
    }
    
    return -1;
}

int main() {
    
    cin >> N >> M;
    cin >> Hx >> Hy;
    cin >> Ex >> Ey;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> maze[i][j];
    
    cout << solve(Hx - 1, Hy - 1);
    
    return 0;
}
