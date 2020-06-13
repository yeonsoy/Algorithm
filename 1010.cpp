#include <iostream>
#include <cstring>
using namespace std;

// 다리 놓기

int T;
int N, M;
int dp[31][31];

int main() {
    
    cin >> T;
    
    for(int i = 0; i<T; i++) {
        cin >> N >> M;
        if(N == M)
            cout << 1 << endl;
        else {
            memset(dp, 0, sizeof(dp));
            
            // N = 1 일때는 M과 같은 만큼 연결 가능
            for (int j = 0; j <= M; j++) dp[1][j] = j;
            
            // N >= 2 일 때
            // j번째에서 k번째로 다리를 건설할 수 있는 경우의 수
            for (int j = 2; j <= N; j++)
                for (int k = j; k <= M; k++)
                    for (int l = k; l >= j; l--)
                        dp[j][k] += dp[j - 1][l - 1];
            
            cout << dp[N][M] << endl;
        }
    }
    
    return 0;
}
