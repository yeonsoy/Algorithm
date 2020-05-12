#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 파이프 옮기기 1

typedef pair<int, int> point;
typedef pair<pair<point, point>, int> pipe;

int N;
int house[17][17];
int ed_count[17][17][3];

bool isPossible(point pos) {
    
    if(pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= N) return false;
    
    if(house[pos.first][pos.second] == 1) return false;
    
    return true;
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> house[i][j];
    
    // memset(p, 0, sizeof(p));
    queue <pipe> que;
    
    // 0 : 오른쪽 1 : 아래 2 : 오른쪽 아래 대각선
    que.push({{{0,0}, {0,1}}, 0});
    ed_count[0][1][0] = 1;
    
    // 0일땐 0과 2만 가능
    // 1일땐 1과 2만 가능
    // 2일땐 0, 1, 2 가능
    
    while(!que.empty()) {
        point st = que.front().first.first;
        point ed = que.front().first.second;
        int dir = que.front().second;
        que.pop();
        
        point n_st;
        point n_ed;
        
        if(dir == 0 || dir == 2){
            
            // dir : 0
            if(dir == 0) {
                n_st = {st.first, st.second + 1};
                n_ed = {ed.first, ed.second + 1};
            }
            else {
                n_st = {st.first + 1, st.second + 1};
                n_ed = {ed.first, ed.second + 1};
            }
            
            if(isPossible(n_st) && isPossible(n_ed)) {
                que.push({{n_st, n_ed}, 0});
                ed_count[n_ed.first][n_ed.second][0]++;
            }
        }
        
        if(dir == 1 || dir == 2){
            
            // dir : 1
           if(dir == 1) {
                n_st = {st.first + 1, st.second};
                n_ed = {ed.first + 1, ed.second};
            }
            else {
                n_st = {st.first + 1, st.second + 1};
                n_ed = {ed.first + 1, ed.second};
            }
            
            if(isPossible(n_st) && isPossible(n_ed)) {
                que.push({{n_st, n_ed}, 1});
                ed_count[n_ed.first][n_ed.second][1]++;
            }
        }
        
        if(dir == 0 || dir == 1 || dir == 2){
            
            // dir : 2
            if(dir == 0) {
                n_st = {st.first, st.second + 1};
                n_ed = {ed.first + 1, ed.second + 1};
            }
            else if(dir == 1) {
                n_st = {st.first + 1, st.second };
                n_ed = {ed.first + 1, ed.second + 1};
            }
            else {
                n_st = {st.first + 1, st.second + 1};
                n_ed = {ed.first + 1, ed.second + 1};
            }
            
            if(isPossible(n_st) && isPossible(n_ed) && isPossible({n_st.first, n_st.second + 1}) && isPossible({n_ed.first, n_ed.second - 1})) {
                que.push({{n_st, n_ed}, 2});
                ed_count[n_ed.first][n_ed.second][2]++;
            }
        }
        
    }
    
     cout << ed_count[N - 1][N - 1][0] + ed_count[N - 1][N - 1][1] + ed_count[N - 1][N - 1][2] << endl;
    
    
    return 0;
}
