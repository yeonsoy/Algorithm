#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 소문난 칠공주

typedef pair<int, int> point;
char princess[5][5];
bool visited[5][5];
bool isUsed[5 * 5];
int answer;
point dir[4] = {{1,0}, {0,1}, {0, -1}, {-1, 0}};

bool isPossible() {

    memset(visited, false, sizeof(visited));
    queue <point> que;
    int s = 0;
    bool flag = false;
    for(int i = 0; i<25; i++)
        if(isUsed[i]) {
            if(princess[i / 5][i % 5] == 'S') s++;
            if(!flag) {
                que.push({i / 5, i % 5});
                visited[i / 5][i % 5] = true;
                flag = true;
            }
        }
    if(s < 4) return false;

    int count = 1;
    while(!que.empty()) {
    
        point p = que.front();
        que.pop();
        
        if(count == 7) return true;
        
        for(int i = 0; i<4; i++) {
            int r = p.first + dir[i].first;
            int c = p.second + dir[i].second;
            
            if(r < 0 || r >= 5 || c < 0 || c >= 5) continue;
            
            if(isUsed[r * 5 + c] && !visited[r][c])
            {
                visited[r][c] = true;
                que.push({r, c});
                count++;
            }
        }
        
    }

    return false;
}

void solve(int idx, int count) {
    
    if(count == 7) {
           if(isPossible()) answer++;
           return;
       }
    
    for(int i = idx; i<25; i++) {
        
        if(!isUsed[i]) {
            isUsed[i] = true;
            solve(i, count + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    
    for(int i = 0; i<5; i++)
        for(int j = 0; j<5; j++)
            cin >> princess[i][j];
    
    solve(0, 0);
    
    cout << answer << endl;
    
    return 0;
}
