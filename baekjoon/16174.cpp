#include <iostream>
using namespace std;

// 점프왕 쩰리 (Large)

typedef pair<int, int> point;
int N;
int map[65][65];
bool visited[65][65];
point dir[2] = {{0, 1}, {1, 0}};

void solve(int r, int c) {
    
    if(r == N - 1 && c == N - 1) {
        cout << "HaruHaru" << endl;
        exit(0);
    }
    
    for(int i = 0; i<2; i++) {
        int rr = r + dir[i].first * map[r][c];
        int cc = c + dir[i].second * map[r][c];
        
        if(rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
        if(visited[rr][cc]) continue;
        
        visited[rr][cc] = true;
        solve(rr, cc);
    }
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> map[i][j];
    
    visited[0][0] = true;
    solve(0, 0);
    
    cout << "Hing" << endl;
    
    return 0;
}
