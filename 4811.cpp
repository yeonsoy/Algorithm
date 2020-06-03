#include <iostream>
using namespace std;

// 알약

int N; // 병에 들어있는 약의 개수
long long dp[31][31];

long long solve(int whole, int half) {
    
    if(whole == 0 && half == 0) return 1;
    
    // 이미 계산해놓은 값이 존재하는 경우
    if(dp[whole][half] > 0) return dp[whole][half];
    
    long long &
    ret = dp[whole][half];
    
    if(whole > 0) ret += solve(whole - 1, half + 1);
    if(half > 0) ret += solve(whole, half - 1);
    
    return ret;
}

int main() {

    while(cin >> N) {
        if(N == 0) break;
        cout << solve(N, 0) << endl;
    }

    return 0;
}
