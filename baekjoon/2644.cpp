#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 촌수계산

int n;
int a, b;
int m;
int family[101][101];
int answer[101];
bool visited[101];

void solve() {
    visited[a] = true;
    queue <int> que;
    que.push(a);
    
    while(!que.empty()) {
        int front = que.front();
        que.pop();
        
        for(int i = 1; i <=n; i++) {
            if(family[front][i] == 1 && !visited[i]) { // 방문하지 않았고, 두 가족이 1촌 관계라면
                visited[i] = true;
                answer[i] = answer[front] + 1; // 현재 촌수에 +1
                que.push(i);
            }
        }
    }
}

int main() {
    
    cin >> n;
    cin >> a >> b;
    cin >> m;
    
    for(int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        family[x][y] = 1;
        family[y][x] = 1;
    }
    
    solve();
    
    if(answer[b] == 0) answer[b] = -1;

    cout << answer[b];
    
    return 0;
}
