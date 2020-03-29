#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 양
// . 빈 필드
// # 울타리
// o 양
// v 늑대
typedef pair<int, int> point;

int R, C;
char map[251][251];
bool visited[251][251];
vector <point> o;
vector <point> v;
point dir[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int o_ans, v_ans;


void solve() {
    
    
    
    queue <point> que;
    for(int i = 0; i<v.size(); i++) {
        que.push(v[i]);
        
        int o_count = 0, v_count = 1;
        
        while(!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            visited[r][c] = true;
            
            for(int i = 0; i<4; i++) {
                int rr = r + dir[i].first;
                int cc = c + dir[i].second;
                
                if(rr < 0 || rr >= R) continue;
                if(cc < 0 || cc >= C) continue;
                
                if(!visited[rr][cc]) {
                    if(map[rr][cc] == 'v')
                        v_count++;
                    else if(map[rr][cc] == 'o')
                        o_count++;
                    
                    visited[rr][cc] = true;
                    que.push({rr, cc});
                }
            }
        }
        
        if(v_count < o_count)
            v_ans -= v_count;
        else
            o_ans -= o_count;
    }
    
}

int main(){
    
    cin >> R >> C;
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'o') o.push_back({i, j});
            else if(map[i][j] == 'v') v.push_back({i, j});
            else if(map[i][j] == '#') visited[i][j] = true;
        }
    
    o_ans = o.size();
    v_ans = v.size();
    
    solve();
    
    cout << o_ans << " " << v_ans << endl;
    
    return 0;
}
