#include <iostream>
#include <vector>
using namespace std;

// 퇴사

int N;
vector <pair<int, int>> dp;
int result[17];
bool isUsed[17];
int t, point;

void solve(int idx, int sum) {
    
    result[idx] = max(result[idx], sum);

    for(int i = idx; i<N; i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            solve(i + dp[i].first, sum + dp[i].second);
            isUsed[i] = false;
        }
    }
}

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        cin >> t >> point;
        dp.push_back({t, point});
    }
    
    solve(0, 0);
    
    int answer = 0;
    
    for(int i = 0; i<=N; i++)
        answer = max(result[i], answer);
    
    cout << answer << endl;
    
    return 0;
}
