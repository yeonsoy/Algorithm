#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 문자판

typedef pair<int, int> point;

int N, M;
int K;
point dir[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
char map[100][100];
string word;
int dp[100][100][80];
int answer;

int solve(int r, int c, int idx) {
    
    if (dp[r][c][idx] != -1) return dp[r][c][idx];
    if (idx >= word.size()) return 1;
    
    dp[r][c][idx] = 0;
    
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= K; j++)
        {
            int rr = r + dir[i].first * j;
            int cc = c + dir[i].second * j;
            
            if(rr < 0 || rr >= N) continue;
            if(cc < 0 || cc >= M) continue;
            
            if (map[rr][cc] != word[idx]) continue;
            
            dp[r][c][idx] += solve(rr, cc, idx + 1);
        }
    
    return dp[r][c][idx];
}

int main() {
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    
    cin >> word;
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == word[0])
                answer += solve(i, j, 1);
    
    cout << answer << endl;
    
    return 0;
}
