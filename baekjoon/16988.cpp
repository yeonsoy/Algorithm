#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// Baaaaaaaaaduk2 (Easy)

typedef pair<int, int> point;
int N, M;
int map[31][31];
bool visited[31][31];
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int answer;
vector <int> temp;

int bfs(int r, int c) {
    
    visited[r][c] = true;
    queue <point> que;
    que.push({r, c});
    int count = 1;
    bool flag = false;
    while(!que.empty()) {
        point p = que.front();
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int rr = p.first + dir[i].first;
            int cc = p.second + dir[i].second;
            
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            if(visited[rr][cc]) continue;
            if(map[rr][cc] == 0)
                flag = true;
            
            if(map[rr][cc] != 2) continue;
            
            visited[rr][cc] = true;
            que.push({rr, cc});
            count++;
        }
    }
    
    if(flag) return 0;
    else return count;
}

int counting() {
    
    memset(visited, false, sizeof(visited));
    int count = 0;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(!visited[i][j] && map[i][j] == 2)
                count += bfs(i, j);
    
    return count;
}

void goWhite(int idx) {
    
    if(idx == 2) {
        answer = max(answer, counting());
        return ;
    }
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(map[i][j] == 0) {
                map[i][j] = 1;
                goWhite(idx + 1);
                map[i][j] = 0;
            }
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> map[i][j];
    
    goWhite(0);
    
    cout << answer << endl;
    
    return 0;
}
