#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 섬의 개수

typedef pair<int, int> point;
int w, h;
int map[51][51];
bool visited[51][51];
point dir[8] = {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void indexing(int r, int c) {
    queue <point> que;
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty()) {
        
        point p = que.front();
        que.pop();
        
        for(int i = 0; i<8; i++) {
            int rr = p.first + dir[i].first;
            int cc = p.second +dir[i].second;
            
            if(rr < 0 || rr >= h || cc < 0 || cc >= w)
                continue;
            
            if(visited[rr][cc]) continue;
            if(map[rr][cc] == 1)
            {
                visited[rr][cc] = true;
                que.push({rr, cc});
            }
        }
        
    }
}


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        int answer = 0;
        
        cin >> w >> h;
        
        if(w == 0 && h == 0) break;
        
        for(int i = 0; i<h; i++)
            for(int j = 0; j<w; j++)
                cin >> map[i][j];
        
        for(int i = 0; i<h; i++)
            for(int j = 0; j<w; j++)
                if(map[i][j] == 1 && !visited[i][j]) {
                    indexing(i, j);
                    answer++;
                }
        
        cout << answer << "\n";
    }
    
    return 0;
}
