#include <iostream>
#include <vector>
using namespace std;

// 퇴사 2

int N;
vector <pair<int, int>> arr;
int dp[1500001];
int answer;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    arr.resize(N);
    
    for(int i = 0; i<N; i++)
        cin >> arr[i].first >> arr[i].second;
    
    
    for(int i = 0; i<=N; i++)
    {
        answer = max(dp[i], answer);
        
        if(i + arr[i].first > N)
            continue;
        
        dp[i + arr[i].first] = max(dp[i + arr[i].first], answer + arr[i].second);
    }
  
    
    cout << answer << "\n";
    
    return 0;
}
