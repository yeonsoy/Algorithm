#include <iostream>
#include <queue>
using namespace std;

// 주난의 난

typedef pair<int, int> point;
int N, M;
char map[501][501];
bool visited[501][501];
point junan, target;
int answer;
point dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue <point> que;

void solve(int r, int c) {
    for(int i = 0; i<4; i++) {
        int rr = r + dir[i].first;
        int cc = c + dir[i].second;
        
        if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
        if(!visited[rr][cc] && map[rr][cc] == '0')
        {
            visited[rr][cc] = true;
            que.push({rr, cc});
            solve(rr, cc);
        }
    }
}

int main() {
    
    cin >> N >> M;
    
    cin >> junan.first >> junan.second >> target.first >> target.second;
    
    junan.first--;
    junan.second--;
    
    target.first--;
    target.second--;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> map[i][j];
    
    que.push(junan);
    visited[junan.first][junan.second] = true;
    
    while(!que.empty()) {
        
        auto size = que.size();
        for(int i = 0; i<que.size(); i++) {
            auto front = que.front();
            que.pop();
            solve(front.first, front.second);
            que.push(front);
        }
        
        size = que.size();
        
        while(size--) {
            auto front = que.front();
            if(front.first == target.first && front.second == target.second) {
                cout << answer << endl;
                exit(0);
            }
            que.pop();
            
            for(int i = 0; i<4; i++) {
                int r = front.first + dir[i].first;
                int c = front.second + dir[i].second;
                
                if(r < 0 || r >= N || c < 0 || c >= M) continue;
                if(!visited[r][c])
                {
                    visited[r][c] = true;
                    map[r][c] = 0;
                    que.push({r, c});
                }
            }
        }
        
        answer++;
    }
    
    cout << answer << endl;

    return 0;
}
