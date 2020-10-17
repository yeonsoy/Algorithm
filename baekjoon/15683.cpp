#include <iostream>
#include <vector>
using namespace std;

// 감시

typedef pair<int, int> point;
int N, M;
int answer = 64;
int map[9][9];
bool visit[9][9];
vector <point> cctv;

void check(point p, int number, int dir, bool visited[9][9]) {
    
    if(number == 1) {
        if(dir == 0) {
            // 아래
            for(int i = 1; i<=N - p.first; i++) {
                if(map[p.first + i][p.second] == 6) break;
                visited[p.first + i][p.second] = true;
            }
        }
        else if(dir == 1) {
            // 오른쪽
            for(int i = 1; i<=M - p.second; i++) {
                if(map[p.first][p.second + i] == 6) break;
                visited[p.first][p.second + i] = true;
            }
        }
        else if(dir == 2) {
            // 위
            for(int i = 1; i<=p.first; i++) {
                if(map[p.first - i][p.second] == 6) break;
                visited[p.first - i][p.second] = true;
            }
        }
        else {
            // 왼쪽
            for(int i = 1; i<=p.second; i++) {
                if(map[p.first][p.second - i] == 6) break;
                visited[p.first][p.second - i] = true;
            }
        }
    }
    else if(number == 2) {
        
        if(dir == 0) {
            // 위 아래
            check(p, 1, 0, visited);
            check(p, 1, 2, visited);
        }
        else if(dir == 1) {
            // 왼쪽 오른쪽
            check(p, 1, 1, visited);
            check(p, 1, 3, visited);
        }
    }
    else if(number == 3) {
        if(dir == 0) {
            // 아래 왼쪽
            check(p, 1, 0, visited);
            check(p, 1, 3, visited);
        }
        else if(dir == 1) {
            // 위 오른쪽
            check(p, 1, 2, visited);
            check(p, 1, 1, visited);
        }
        else if(dir == 2) {
            // 아래 오른쪽
            check(p, 1, 0, visited);
            check(p, 1, 1, visited);
        }
        else {
            // 위 왼쪽
            check(p, 1, 2, visited);
            check(p, 1, 3, visited);
        }
    }
    else if(number == 4) {
        if(dir == 0) {
            // 아래 왼쪽 오른쪽
            check(p, 3, 0, visited);
            check(p, 1, 1, visited);
        }
        else if(dir == 1) {
            // 위 오른쪽 왼쪽
            check(p, 3, 1, visited);
            check(p, 1, 3, visited);
        }
        else if(dir == 2) {
            // 아래 위 오른쪽
            check(p, 2, 0, visited);
            check(p, 1, 1, visited);
        }
        else {
            // 아래 위 왼쪽
            check(p, 2, 0, visited);
            check(p, 1, 3, visited);
        }
    }
    else {
        // 위 아래 왼쪽 오른쪽
        check(p, 4, 0, visited);
        check(p, 1, 2, visited);
    }
    
}

void copy(bool a[9][9], bool b[9][9]) {
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            a[i][j] = b[i][j];
}

void solve(int idx, bool visited[9][9]) {
    
    if(idx >= cctv.size()) {
        int res = 0;
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++)
                if(map[i][j] == 0 && !visited[i][j])
                    res++;
        }
        
        answer = min(answer, res);
        return ;
    }
    
    for(int i = idx; i<cctv.size(); i++) {
        
        int cur = map[cctv[i].first][cctv[i].second];
        bool temp[9][9];
        
        if(cur == 2) {
            for(int j = 0; j<2; j++) {
                copy(temp, visited);
                check(cctv[i], cur, j, temp);
                solve(i + 1, temp);
            }
        }
        else {
            for(int j = 0; j<4; j++) {
                copy(temp, visited);
                check(cctv[i], cur, j, temp);
                solve(i + 1, temp);
            }
        }
    }
    
}


int main(){
    
    cin >> N >> M;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] != 6)
                cctv.push_back({i, j});
        }
    
    solve(0, visit);
    
    cout << answer << endl;
    
    return 0;
}
