#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 경쟁적 전염

typedef pair<int, int> point;
int N, K;
int S, X, Y;
point dir[4] = {{1,0}, {-1,0}, {0,1}, {0, -1}};
int map[201][201];
vector<point> virus[1001];
int max_virus;

bool check() {
    for(int i = 0; i<N; i++)
    for(int j = 0; j<N; j++)
        if(map[i][j] == 0) return true;
    
    return false;
}

void solve() {
    
    for(int i = 1; i<=max_virus; i++) {
    
        queue <point> que;
        for(int j=0; j<virus[i].size(); j++)
            que.push(virus[i][j]);
    
        while(!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            
            for(int j = 0; j<4; j++) {
                int rr = r + dir[j].first;
                int cc = c + dir[j].second;
                
                if(rr < 0 || rr >= N) continue;
                if(cc < 0 || cc >= N) continue;
                
                if(map[rr][cc] != 0) continue;
                
                map[rr][cc] = i;
                virus[i].push_back({rr, cc});
            }
            
        }
    }
    
}

int main() {
    
    cin >> N >> K;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) {
                virus[map[i][j]].push_back({i, j});
                max_virus = max(max_virus, map[i][j]);
            }
        }
    
    cin >> S >> X >> Y;
    
    for(int i =0; i<S; i++) {
        solve();
        if(!check()) break;
    }
    
    cout << map[X - 1][Y - 1];
    
    return 0;
}
