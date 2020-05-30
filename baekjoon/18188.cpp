#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 다오의 데이트

typedef pair<int, int> point;
int H, W;
int N;
char map[21][21];
vector <pair<char, char>> marid;

point dao;
point dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve(int r, int c, int idx, string cur) {
    
    if(idx >= N) return;
    
    for(int i = 0; i<2; i++) {
        
        char ch;
        int op = 0;
        
        if(i == 0) ch = marid[idx].first;
        else ch = marid[idx].second;
        
        if(ch == 'W') op = 0;
        else if(ch == 'A') op = 1;
        else if(ch == 'S') op = 2;
        else if(ch == 'D') op = 3;
        
        int rr = r + dir[op].first;
        int cc = c + dir[op].second;
        
        if(rr < 0 || rr >= H || cc < 0 || cc >= W) continue;
        if(map[rr][cc] == '@') continue;
        
        if(map[rr][cc] == 'Z') {
            cout << "YES" << endl << (cur + ch) << endl;
            exit(0);
        }
        else solve(rr, cc, idx + 1, cur + ch);
        
    }
}

int main() {
    
    cin >> H >> W;
    
    for(int i = 0; i<H; i++)
        for(int j = 0; j<W; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'D') dao = {i, j};
        }
    
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        char a, b;
        cin >> a >> b;
        
        marid.push_back({a, b});
    }
    
    solve(dao.first, dao.second, 0, "");
    
    cout << "NO" << endl;
    
    return 0;
}
