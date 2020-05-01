#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 봄버맨 2

typedef pair<int, int> point;
int R, C;
int N;
char board[201][201];
int map[201][201];

point dir[4] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

int main() {
    
    // N이 매우 크므로 사이클이 있을 것
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C >> N;
    
    for(int i = 0; i<R; i++)
        for(int j = 0; j<C; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == '.')
                map[i][j] = 0;
            else
                map[i][j] = 3;
        }
    
   if(N > 5)
       N = (N - 1) % 4 + 5;
    
    queue <point> que;
    for (int time = 1; time <= N; time++) {
        if (time == 1) {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    map[i][j]--;
    
            continue;
        }
        if (time % 2) {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++) {
                    map[i][j]--;

                    if (map[i][j] == 0)
                        que.push({ i, j });
                }
        
            while (!que.empty()) {
                int r = que.front().first;
                int c = que.front().second;
                que.pop();
                
                board[r][c] = '.';
                map[r][c] = 0;
                
                // 폭탄 터뜨리기
                for (int k = 0; k < 4; k++)
                {
                    int rr = r + dir[k].first;
                    int cc = c + dir[k].second;
                    
                    if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
                        board[rr][cc] = '.';
                        map[rr][cc] = 0;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++) {
                    map[i][j]--;
                    
                    if (board[i][j] == '.') // 폭탄이 없던 자리에 폭탄 심기
                    {
                        board[i][j] = 'O';
                        map[i][j] = 3;
                    }
                }
        }
    }
    
    
    for(int i = 0; i<R; i++) {
        for(int j = 0; j<C; j++)
            cout << board[i][j];
        
        cout << endl;
    }
    
    return 0;
}
