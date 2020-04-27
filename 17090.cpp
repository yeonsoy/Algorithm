#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 미로 탈출하기

typedef pair<int, int> point;
int N, M;
char maze[501][501];
bool visited[501][501];
point dir[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int answer;
queue <point> que;

void solve() {
    
    while(!que.empty()) {
        
        point cur = que.front();
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int r = cur.first + dir[i].first;
            int c = cur.second + dir[i].second;
            if(r < 0 || r >= N) continue;
            if(c < 0. | c >= M) continue;
            if(visited[r][c]) continue;
            
            if((maze[r][c] == 'L' && i == 0) || (maze[r][c] == 'U' && i == 1)
               || (maze[r][c] == 'D' && i == 2) || (maze[r][c] == 'R' && i == 3))
            {
                visited[r][c] = true;
                que.push({r, c});
                answer++;
            }
        }
    }
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++) {
            cin >> maze[i][j];
            
            int r = i;
            int c = j;
            
            switch (maze[i][j])
            {
                case 'U':
                    r--;
                    break;
                case 'R':
                    c++;
                    break;
                case 'D':
                    r++;
                    break;
                case 'L':
                    c--;
                    break;
                default:
                    break;
            }
            
            if(r < 0 || r >= N || c < 0 || c >= M) {
                answer++;
                visited[i][j] = true;
                que.push({i, j});
            }
            
        }
    
    solve();
    
    cout << answer;
    
    return 0;
}
