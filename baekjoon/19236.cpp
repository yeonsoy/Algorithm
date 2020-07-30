#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 청소년 상어

struct fish {
    int r;
    int c;
    int direction;
    bool isAlive;
};

typedef pair<int, int> point;
int answer;
int map[4][4];
fish fishs[17];
point dir[9] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

bool isPossible(point p) {
    
    // 칸을 넘어가면 이동할 수 없다
    if(p.first < 0 || p.first >= 4 || p.second < 0 || p.second >= 4)
        return false;

    // 상어가 있는 위치는 이동할 수 없다
    if(map[p.first][p.second] == -1) return false;
    
    return true;
}

void moveFishs() {
    
    for(int i = 1; i<=16; i++) {
        fish &cur = fishs[i];
        if(!cur.isAlive) continue;
        int d = cur.direction;
        point next = {cur.r + dir[d].first, cur.c + dir[d].second};
        
        int check = d;
        bool flag = false;

        while(!isPossible(next)) {
            d++;

            // 만약 360도를 돌았는데도 이동할 수 없다면
            if(d == check) {
                flag = true;
                break;
            }
            if(d > 8) d = 1;
            
            next = {cur.r + dir[d].first, cur.c + dir[d].second};
            cur.direction = d;
        }
        
        if(flag) continue;
        
        if(map[next.first][next.second] == 0) {
            map[next.first][next.second] = map[cur.r][cur.c];
            map[cur.r][cur.c] = 0;
            cur.r = next.first;
            cur.c = next.second;
            continue;
        }
        
        fish &temp = fishs[map[next.first][next.second]];
        swap(cur.r, temp.r);
        swap(cur.c, temp.c);
        swap(map[cur.r][cur.c], map[temp.r][temp.c]);
    }
    
}

void copy_map(int a[4][4], int b[4][4], fish c[17], fish d[17]) {
    
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
            a[i][j] = b[i][j];
    
    for(int i = 1; i<=16; i++)
        c[i] = d[i];
}

void solve(int r, int c, int d, int sum) {

    answer = max(answer, sum);
   
    int temp_map[4][4];
    fish temp_fishs[17];
    copy_map(temp_map, map, temp_fishs, fishs);
    
    moveFishs();

    for(int i = 1; i<=3; i++) {
        int rr = r + dir[d].first * i;
        int cc = c + dir[d].second * i;
        
        if(!(rr < 0 || rr >= 4 || cc < 0 || cc >= 4))
        {
            if(map[rr][cc] == 0) continue;
            
            fish &f = fishs[map[rr][cc]];
            int n = map[rr][cc];
            map[r][c] = 0;
            map[rr][cc] = -1;
            f.isAlive = false;
            
            solve(rr, cc, f.direction, sum + n);
            
            map[r][c] = -1;
            map[rr][cc] = n;
            f.isAlive = true;
        }
        else break;
    }
    
    copy_map(map, temp_map, fishs, temp_fishs);
    
}

int main() {
    
    fastio();
    
    int idx, d;
    
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++) {
            cin >> idx >> d;
            fishs[idx] = {i, j, d, true};
            map[i][j] = idx;
        }

    idx = map[0][0];
    d = fishs[map[0][0]].direction;
    fishs[map[0][0]].isAlive = false;
    map[0][0] = -1;
    
    solve(0, 0, d, idx);
    
    cout << answer << endl;
    
    return 0;
}
