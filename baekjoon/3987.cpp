#include <iostream>
#include <cstring>
using namespace std;

// 보이저 1호

typedef pair<int, int> point;
int N, M;
char map[502][502];
int visited[502][502];
point dir[4] = {{-1,  0}, {0, 1}, {1, 0}, {0, -1}};
point sig;

int solve(int now_dir) {
    
    int time = 1;
    
    point pos = make_pair(sig.first, sig.second);
    visited[pos.first][pos.second] = now_dir;
    
    while(true) {
        pos.first += dir[now_dir].first;
        pos.second += dir[now_dir].second;
        
        if(pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M
           || map[pos.first][pos.second] == 'C') return time;
        
        if(visited[pos.first][pos.second] == now_dir) // 동일한 방향으로 방문한 적 있는 경우
            return 0;
        
        if(map[pos.first][pos.second] == '/')
            now_dir = 1 ^ now_dir;
        else if(map[pos.first][pos.second] == '\\')
            now_dir = 3 - now_dir;
        
        time++;
        
        visited[pos.first][pos.second] = now_dir;
    }
    
    return time;
}

void printDir(int ans_dir) {
    if(ans_dir == 0) cout << "U" << endl;
    else if(ans_dir == 1) cout << "R" << endl;
    else if(ans_dir == 2) cout << "D" << endl;
    else cout << "L" << endl;
}

int main() {
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            cin >> map[i][j];
    
    cin >> sig.first >> sig.second;
    sig.first --;
    sig.second--;
    
    int answer = 0;
    int ans_dir = 1;
    
    for(int i = 0; i<4; i++) {
        memset(visited, -1, sizeof(visited));
        int count = solve(i);
        if(count == 0) {
            printDir(i);
            cout << "Voyager" << endl;
            return 0;
        }
        
        if(answer < count) {
            answer = count;
            ans_dir = i;
        }
    }
    
    printDir(ans_dir);
    cout << answer << endl;
    
    return 0;
}
