#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 미로만들기

typedef pair<int, int> point;
int n;
int map[51][51];
int visited[51][51];
point dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    
    cin >> n;
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%1d", &map[i][j]);
    
    queue <pair<point, int>> que;
    que.push({{0, 0}, 0});
    memset(visited, -1, sizeof(visited));
    visited[0][0] = 0;
    
    while(!que.empty()) {
        
        point p = que.front().first;
        int d = que.front().second;
        que.pop();
        
        for(int i = 0; i<4; i++)
        {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= n || c < 0 || c >= n) continue;
            if(visited[r][c] == -1)
            {
                if(map[r][c] == 0)
                    visited[r][c] = d + 1;
                else
                    visited[r][c] = d;
                
                que.push({{r, c},  visited[r][c]});
            }
            else {
                if(map[r][c] == 0 && visited[r][c] > d + 1) {
                    visited[r][c] = d + 1;
                    que.push({{r, c},  visited[r][c]});
                }
                else if(map[r][c] == 1 && visited[r][c] > d) {
                    visited[r][c] = min(visited[r][c], d);
                    que.push({{r, c},  visited[r][c]});
                }
            }
        }
    }
    
    cout << visited[n - 1][n - 1] << endl;
    
    return 0;
}
