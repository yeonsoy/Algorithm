#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 견우와 직녀

typedef pair<int, int> point;
int N, M;
int map[11][11];

vector <point> p;
point dir[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int answer = 2e9;

void getMinTime() {
    
    bool visited[11][11];
    memset(visited, false, sizeof(visited));
    
    queue <pair<point, int>> que;
    que.push({{0, 0}, 0});
    visited[0][0] = true;
    
    while(!que.empty()) {
        
        point front = que.front().first;
        int t = que.front().second;
        que.pop();
        
        if(front.first == N - 1 && front.second == N - 1) {
            answer = min(answer, t);
            break;
        }
        
        for(int i = 0; i<4; i++) {
            int r = front.first + dir[i].first;
            int c = front.second + dir[i].second;
            
            if(r < 0 || r >= N || c < 0 || c >= N) continue;
            if(map[r][c] == 0) continue;
            if(visited[r][c]) continue;
            
            // 그냥 땅인 경우
            if(map[r][c] == 1) {
                visited[r][c] = true;
                que.push({{r, c}, t + 1});
            }
      
            // 다음 땅이 절벽이고 현재가 땅인 경우 = 두 번 연속 다리를 건널 수 없다
            if(map[r][c] >= 2 && map[front.first][front.second] == 1) {
                // 다리를 건널 수 있는 시간인 경우
                if((t + 1) % map[r][c] == 0) {
                    visited[r][c] = true;
                    que.push({{r, c}, t + 1});
                }
                else {
                    que.push({front, t + 1});
                }
            }
        }
        
    }
}

bool check(point pt) {
    
    bool cliff[4] = {false, false, false, false};
    
    for(int i = 0; i<4; i++) {
        int r = pt.first + dir[i].first;
        int c = pt.second + dir[i].second;
        
        if(r < 0 || r >= N || c < 0 || c >= N) continue;
        
        if(map[r][c] == 0) {
            cliff[i] = true;
        }
    }
    
    if((cliff[0] && cliff[3]) || (cliff[1] && cliff[2]) ||
       (cliff[0] && cliff[2]) || (cliff[1] && cliff[3]))
        return false;
    else
        return true;
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 0)
                p.push_back({i, j});
        }

    for(int i = 0; i<p.size(); i++) {
        // 오작교를 놓을 수 있는 위치인지 검사
        if(check(p[i])) {
            map[p[i].first][p[i].second] = M;
            getMinTime();
            map[p[i].first][p[i].second] = 0;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
