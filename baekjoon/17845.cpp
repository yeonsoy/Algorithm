#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct study_time {
    int important;
    int time;
};

// 수강 과목

int N, K;
int I, T;
vector<study_time> study;
int dp[2][10001];

int main() {
    
    cin >> N >> K;
    
    study.resize(K + 1);
    for(int i = 1; i<=K; i++)
        cin >> study[i].important >> study[i].time;
    
    for (int i = 1; i <= K; i++)
        // j시간만큼 얻을 수 있는 최대 중요도
        for (int j = 0; j <= N; j++) {
            // i번째 과목을 사용했을 때와 사용하지 않았을 때
            dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j]);
            
            // j시간보다 해당 과목의 공부 시간이 같거나 작다면
            if (j >= study[i].time)
                // 해당 과목을 공부할 수 있으므로 사용했을 때와 하지 않았을 때 비교
                dp[i % 2][j] = max(dp[(i - 1) % 2][j - study[i].time] + study[i].important, dp[i % 2][j]);
        }
    
    int answer = 0;
    for (int i = 0; i <= N; i++)
        answer = max(answer, dp[K % 2][i]);
    
    cout << answer;
    
    return 0;
}
