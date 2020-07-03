#include <iostream>
using namespace std;

// 알파벳

typedef pair<int, int> point;
int R, C;
int answer;
char map[21][21];
bool isUsed['Z' - 'A' + 1];
point dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(int r, int c, int step) {
    
    if(r < 0 || r >= R || c < 0 || c >= C) return;
    
    answer = max(answer, step);
    
    if(!isUsed[map[r][c] - 'A']) {
        isUsed[map[r][c] - 'A'] = true;
        for(int i = 0; i<4; i++)
            solve(r + dir[i].first, c + dir[i].second, step + 1);
        isUsed[map[r][c] - 'A'] = false;
    }
    else
        return;
    
}


int main() {
    
    cin >> R >> C;
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++)
            cin >> map[i][j];
    
    isUsed[map[0][0] - 'A'] = true;
    
    for(int i = 0; i<4; i++)
        solve(dir[i].first, dir[i].second, 1);
    
    cout << answer << endl;
    
    return 0;
}
