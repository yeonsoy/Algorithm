#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

typedef pair<int, int> point;
int M, N;
int H;
int map[501][501];
int dp[501][501];
point dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int solve(int r, int c)
{
    if(r == 0 && c == 0) return 1; // 시작점
    
    if(dp[r][c] == -1) {
        dp[r][c] = 0; // 방문 처리
        
        for(int i = 0; i<4; i++)
        {
            int rr = r + dir[i].first;
            int cc = c + dir[i].second;
            
            if(rr < 0 || rr >= M) continue;
            if(cc < 0 || cc >= N) continue;
            
            if(map[r][c] < map[rr][cc]) { // 역순으로 올라가므로 기존보다 큰 값이 있는 경우
                dp[r][c] += solve(rr, cc);
            }
        }
    }
    
    return dp[r][c];
}

int main()
{
    cin >> M >> N;
    
    for(int i = 0; i<M; i++)
        for(int j = 0; j<N; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    
    cout << solve(M - 1, N - 1) << endl;
    
    return 0;
}
