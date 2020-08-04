#include <iostream>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 게리맨더링 2

int N;
int map[101][101];
int answer = 2e9;

bool isPossible(int n, int r, int c, int x, int y, int d1, int d2) {
    
    if(n == 1){
        if(r >= x && c >= y - (r - x))
            return false;
        else
            return true;
    }
    else if(n == 2) {
        if(r >= x && c <= y + (r - x))
            return false;
        else
            return true;
    }
    else if(n == 3) {
        if(r <= x + d1 + d2 && c >= y - d1 + d2 - (x + d1 + d2 - r))
            return false;
        else
            return true;
    }
    else if(n == 4) {
       if(r <= x + d1 + d2 && c <= y - d1 + d2 + (x + d1 + d2 - r))
            return false;
        else
            return true;
    }
    
    return true;
}

void solve(int x, int y, int d1, int d2) {
    
    int number[5] = {0,};
    
    for(int i = 1; i<=N; i++) {
        for(int j = 1; j<=N; j++) {
            if(1 <= i && i < x + d1 && 1 <= j && j <= y && isPossible(1, i, j, x, y, d1, d2))
                number[0] += map[i][j];
            else if(1 <= i && i <= x + d2 && y < j && j <= N && isPossible(2, i, j, x, y, d1, d2))
                 number[1] += map[i][j];
            else if(x + d1 <= i && i <= N && 1 <= j && j < y - d1 + d2 && isPossible(3, i, j, x, y, d1, d2))
                number[2] += map[i][j];
            else if(x + d2 < i && i <= N && y - d1 + d2 <= j && j <= N && isPossible(4, i, j, x, y, d1, d2))
                number[3] += map[i][j];
            else
                number[4] += map[i][j];
        }
    }
    sort(number, number + 5);
    
    answer = min(answer, number[4] - number[0]);
    
}

int main() {
    
    fastio();
    
    cin >> N;
    
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=N; j++)
            cin >> map[i][j];
    
    for(int x = 1; x<=N - 2; x++)
        for(int y = 2; y<=N - 1; y++)
            for(int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++)
                for(int d2 = 1; d2 <= N - y && x + d1 + d2 <= N; d2++)
                    solve(x, y, d1, d2);
    
    cout << answer << endl;
    
    return 0;
}
