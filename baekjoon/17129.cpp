#include <iostream>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

// 윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유

typedef pair<int, int> point;
int n, m;
string map[3001];
bool visited[3001][3001];
point pos[6];
point dir[4] = {{-1, 0}, {0,1}, {1,0}, {0,-1}};

int main() {
    
    fastio();
    
    cin >> n >> m;
    
    for(int i = 0; i<n; i++) {
        cin >> map[i];
        for(int j = 0; j<map[i].size(); j++)
            if(map[i][j] > '1')
                pos[map[i][j] - '0'] = {i, j};
    }
    
    queue <pair<point, int>> que;
    que.push({pos[2], 0});
    visited[pos[2].first][pos[2].second] = true;
    
    while(!que.empty()) {
        point front = que.front().first;
        int d = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++) {
            int r = front.first + dir[i].first;
            int c = front.second + dir[i].second;
            
            if(r < 0 || r >= n || c < 0 || c >= m) continue;
            if(visited[r][c]) continue;
            if(map[r][c] == '1') continue;
            
            if(map[r][c] == '0') {
                que.push({{r, c}, d + 1});
                visited[r][c] = true;
            }
            else
            {
                cout << "TAK" << '\n';
                cout << d + 1 << '\n';
                exit(0);
            }
        }
        
    }
    
    cout << "NIE" << '\n';
    
    return 0;
}
