#include <iostream>
#include <cstring>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 토끼가 정보섬에 올라온 이유

typedef pair<int, int> point;
int N, M;
char map[1001][1001];
int dp[1001][1001];
point rabbit;
int answer = -1;

point dir[3] = {{0, 1}, {1, 1}, {-1, 1}};

int main() {
    
    fastio();
    
    cin >> N >> M;
    
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'R') {
                rabbit = {i, j};
                dp[i][j] = 0;
            }
        }
    
    // 토끼가 오른쪽으로 가므로 토끼 오른쪽 칸부터 탐색
    for(int j = rabbit.second + 1; j < M; j++)
        for(int i = 0; i<N; i++) {
            if(map[i][j] == '#') continue;
            int temp = -1;
            
            for(int k = 0; k<3; k++) {
                int rr = i - dir[k].first;
                int cc = j - dir[k].second;
                
                if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
                // 기존에 갔던 길에서 가장 많은 당근을 얻을 수 있었던 경로
                temp = max(temp, dp[rr][cc]);
            }
            
            if(temp == -1) continue;
            
            // 현재 칸에 당근이 있었다면 카운팅
            if(map[i][j] == 'C') temp++;
            
            // 현재 위치에서 갖고 있던 가장 큰 당근의 개수
            if(map[i][j] == 'O') answer = max(answer, temp);
            
            dp[i][j] = temp;
        }
    
    cout << answer << endl;
    
    return 0;
}
