#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Gaaaaaaaaaarden
// BFS + 조합 백트래킹 (DFS)
// 흰색은 배양액 불가. 배양액이 퍼져나갈 수만 있음
// 황토색칸에 배양액을 뿌릴 수 있음
// 초록 + 빨간 배양액이 만나면 꽃이 피어난다
// 모든 배양액은 서로 다른 곳에 뿌려져야 한다 (조합)

typedef pair<int, int> point;

int N, M;
int G, R;
int map[51][51];
vector <point> possible;
vector <point> temp;
vector <point> green;
vector <point> red;
bool isUsed[11], isUsed2[11];
point dir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int answer;

int bfs() {
    queue <point> que;
    point visited[51][51];
    
    for (int i = 0; i < green.size(); i++) {
        visited[green[i].first][green[i].second].first = 0;
        visited[green[i].first][green[i].second].second = 1;
        que.push(green[i]);
    }
    for (int i = 0; i < red.size(); i++) {
        visited[red[i].first][red[i].second].first = 0;
        visited[red[i].first][red[i].second].second = 2;
        que.push(red[i]);
    }
    
    int flower = 0;
    
    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        if (visited[r][c].second == 3) continue;
        
        for (int i = 0; i < 4; i++) {
            int rr = r + dir[i].first;
            int cc = c + dir[i].second;
            
            if (rr < 0 || rr >= N) continue;
            if (cc < 0 || cc >= M) continue;
            if (map[rr][cc] == 0) continue; // 호수이면
            
            if (visited[rr][cc].second == 1) {
                if (visited[rr][cc].first == visited[r][c].first + 1 && visited[r][c].second == 2) {
                    visited[rr][cc].second = 3;
                    flower++;
                }
            }
            else if (visited[rr][cc].second == 2) {
                if (visited[rr][cc].first == visited[r][c].first + 1 && visited[r][c].second == 1) {
                    visited[rr][cc].second = 3;
                    flower++;
                }
            }
            else if (visited[rr][cc].second == 0) {
                visited[rr][cc].first = visited[r][c].first + 1;
                visited[rr][cc].second = visited[r][c].second;
                que.push({rr, cc});
            }
        }
    }
    return flower;
}

void solve(int idx, int g, int r) {
    if (r == 0 && g == 0) {
        if (red.size() > 0 && green.size() > 0)
            answer = max(answer, bfs());
        
        return;
    }
    if (idx >= possible.size()) return;
    
    for (int i = idx; i < possible.size(); i++) {
        if (r > 0) {
            red.push_back(possible[i]);
            solve(i + 1, g, r - 1);
            red.pop_back();
        }
        if (g > 0) {
            green.push_back(possible[i]);
            solve(i + 1, g - 1, r);
            green.pop_back();
        }
    }
}

int main() {
    
    cin >> N >> M >> G >> R;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2)
                possible.push_back({i, j});
        }
    
    solve(0, G, R);
    
    cout << answer;
    
    return 0;
}
