#include <iostream>
#include <vector>
using namespace std;

// 포도주 시식

int n;
vector <int> wines;
int dp[10003];
int answer;

int main() {
    
    cin >> n;
    
    wines.resize(n + 3);
    
    for(int i = 3; i<n + 3; i++)
        cin >> wines[i];
    
    for(int i = 3; i<n+3; i++) {
        dp[i] = max(dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]);
        dp[i] = max(dp[i - 1], dp[i]);
        answer = max(answer, dp[i]);
    }
    
    cout << answer << endl;
    
    return 0;
}
