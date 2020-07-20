#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 섬
// 모든 가장자리는 바다이다
// 4방향 bfs 탐색으로 이어져있는 섬은 한 섬이다.

typedef pair<int, int> point;
int N, M;
string input[2001];
vector <char> answer;
int index_map[2001][2001];
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
point diagonal[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

void bfs(int r, int c, int idx) {
    
    queue <point> que;
    que.push({r, c});
    index_map[r][c] = idx;
    
    while(!que.empty()) {
        point p = que.front();
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int rr = p.first + dir[i].first;
            int cc = p.second + dir[i].second;
            
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            if(index_map[rr][cc] != 0) continue;
            if(input[rr][cc] == '.') continue;
            
            index_map[rr][cc] = idx;
            que.push({rr, cc});
        }
    }
}

int indexing() {
    int count = 0;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(input[i][j] == '#' && index_map[i][j] == 0) {
                bfs(i, j, count + 1);
                count++;
            }
    
    return count;
}

void checkSafety(int r, int c) {
    
    index_map[r][c] = -1;
    queue <point> que;
    que.push({r, c});
    
    while(!que.empty()) {
        point p = que.front();
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int rr = p.first + dir[i].first;
            int cc = p.second + dir[i].second;
            
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            
            if(index_map[rr][cc] > 0) {
                answer[index_map[rr][cc] - 1] = 'O';
                continue;
            }
            
            if(index_map[rr][cc] == 0 && input[rr][cc] == '.') {
                index_map[rr][cc] = -1;
                que.push({rr, cc});
            }
        }
        
        for(int i = 0; i<4; i++) {
            // 대각선 영역
            int rr = p.first + diagonal[i].first;
            int cc = p.second + diagonal[i].second;
      
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            if(input[rr][cc] == '#') continue;
            
            // 대각선에 바다가 있을 때
            // 엇갈려있는 섬이 서로 다른 섬이라면
            if(index_map[rr][cc] != -1 && index_map[rr][p.second] > 0
               && index_map[p.first][cc] > 0 && index_map[rr][p.second] != index_map[p.first][cc]) {
                index_map[rr][cc] = -1;
                que.push({rr, cc});
            }
        }
    }
}


int main() {
    
    fastio();
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        cin >> input[i];
    
    int island = indexing();
    answer.resize(island, 'X');
    
    checkSafety(0, 0);
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++)
        {
            if(input[i][j] == '.') cout << '.';
            else cout << answer[index_map[i][j] - 1];
        }
        cout << '\n';
    }
    
    return 0;
}

