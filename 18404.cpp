#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> point;

int N, M;
int map[501][1001];
point K;
vector <point> others;
point dir[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void solve() {
   
    memset(map, -1, sizeof(map));
    queue<point> que;
    que.push(K);
    map[K.first][K.second] = 0;
    
    while(!que.empty()) {
        int r= que.front().first;
        int c= que.front().second;
        que.pop();
        
        for(int i = 0; i<8; i++) {
            int rr = r + dir[i].first;
            int cc = c + dir[i].second;
            
            if(rr < 1 || rr > N) continue;
            if(cc < 1 || cc > N) continue;
            
            if(map[rr][cc] == -1) {
                map[rr][cc] = map[r][c] + 1;
                que.push({rr, cc});
            }
        }
        
    }
    
}

int main() {
    
    cin >> N >> M;
    
    cin >> K.first >> K.second;
    
    for(int i = 0; i<M; i++) {
        point p;
        cin >> p.first >> p.second;
        others.push_back(p);
    }
    
    solve();

    for(int i = 0; i<others.size(); i++)
        cout << map[others[i].first][others[i].second] << " ";
    
    return 0;
}
