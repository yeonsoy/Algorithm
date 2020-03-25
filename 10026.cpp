#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 적록색약

typedef pair<int, int> point;
int N;
char map[101][101];
bool visited[101][101];
vector<point> G;
int answer;
point dir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void check(int r, int c) {
    
    if(visited[r][c]) return;
    
    answer++;
    
    char pivot = map[r][c];
    visited[r][c] = true;
    queue <point> que;
    que.push({r, c});
    
    while(!que.empty()) {
        int rr = que.front().first;
        int cc = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int tr = rr + dir[i].first;
            int tc = cc + dir[i].second;
            
            if(tr < 0 || tr >= N) continue;
            if(tc < 0 || tc >= N) continue;
            
            if(!visited[tr][tc] && pivot == map[tr][tc]) {
                visited[tr][tc] = true;
                que.push({tr, tc});
            }
        }
    }
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<N; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'G')
                G.push_back({i, j});
        }
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<N; j++)
            check(i, j);
    
    
    cout << answer << " ";
    
    answer = 0;
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i<G.size(); i++)
        map[G[i].first][G[i].second] = 'R';
    
    for(int i = 0; i<N; i++)
        for(int j =0; j<N; j++)
            check(i, j);
    
    cout << answer;
    
    return 0;
}
