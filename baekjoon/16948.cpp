#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> point;
int N;
int map[201][201];
point st, ed;
point dir[6] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

int main() {
    
    cin >> N;
    cin >> st.first >> st.second;
    cin >> ed.first >> ed.second;
    
    for(int i = 0; i<N; i++)
          for(int j = 0; j<N; j++)
              map[i][j] = 0;
    
    queue <point> que;
    que.push(st);
    
    while(!que.empty()) {
        
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        for(int i = 0; i<6; i++) {
            int rr = r + dir[i].first;
            int cc = c + dir[i].second;
            
            if(rr < 0 || rr >= N) continue;
            if(cc < 0 || cc >= N) continue;
            
            if(map[rr][cc] == 0 || map[rr][cc] > map[r][c] + 1) {
                map[rr][cc] = map[r][c] + 1;
                que.push({rr, cc});
            }
        }
    }
    
    if(map[ed.first][ed.second] == 0)
        map[ed.first][ed.second] = -1;
    
    cout << map[ed.first][ed.second] << endl;
    
    return 0;
}
