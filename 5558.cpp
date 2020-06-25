#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// チーズ

typedef pair<int, int> point;
int H, W;
int N;
char map[1001][1001];
int visited[1001][1001];
point st;
point dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
point cheese[10];
int cheese_count = 0;
int answer = 0;

int main() {
    
    fastio();
    
    cin >> H >> W >> N;
    
    for(int i = 0; i<H; i++)
        for(int j = 0; j<W; j++) {
            cin >> map[i][j];
            
            if(map[i][j] >= '1' && map[i][j] <= '9') {
                cheese[map[i][j] - '0' - 1] = {i, j};
                cheese_count++;
            }
            
            if(map[i][j] == 'S') st = {i, j};
        }
    
    for(int ch = 0; ch < cheese_count; ch++) {
        
        memset(visited, false, sizeof(visited));
        queue <pair<point, int>> que;
        visited[st.first][st.second] = true;
        que.push({st, 0});
        
        while(!que.empty()) {
            point p = que.front().first;
            int d = que.front().second;
            que.pop();
            
            if(p.first == cheese[ch].first && p.second == cheese[ch].second)
            {
                st = p;
                answer += d;
                break;
            }
            
            for(int i = 0; i<4; i++) {
                int r = p.first + dir[i].first;
                int c = p.second + dir[i].second;
                
                if(r < 0 || r >= H || c < 0 || c >= W) continue;
                if(map[r][c] == 'X') continue;
                if(visited[r][c]) continue;
                
                que.push({{r, c}, d + 1});
                visited[r][c] = true;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
