#include <iostream>
#include <queue>
using namespace std;

// 로봇 청소기

typedef pair<int, int> point;
int N, M;
point dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
point back[4] = {{1,0}, {0,-1}, {-1,0}, {0,1}};

int house[51][51];
int answer;
int R, C, D;

void solve(int r, int c, int d) {
    
    if(house[r][c] == 1) return;
    
    if(house[r][c] == 0) {
        house[r][c] = 2;
        answer++;
    }
    
    int cur = d;
    for(int i = 0; i<4; i++) {
        int next = (cur - 1);
        if(next < 0) next = 3;
        
        int rr = r + dir[next].first;
        int cc = c + dir[next].second;
        
        if(house[rr][cc] == 0) {
            solve(rr, cc, next);
            return;
        }
        else
            cur = next;
    }
    
    int br = r + back[d].first;
    int bc = c + back[d].second;
    
    solve(br, bc, d);
}

int main() {
    
    cin >> N >> M;
    cin >> R >> C >> D;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> house[i][j];
   
    solve(R, C, D);

    cout << answer << endl;
    return 0;
}
