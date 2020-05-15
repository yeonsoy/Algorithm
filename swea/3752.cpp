#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int N;
vector <int> score;
int dp[10001];

// 가능한 시험 점수

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        
        cin >> N;
        
        for(int i = 0; i<N; i++) {
            int s;
            cin >> s;
            score.push_back(s);
        }
        
        int answer = 0;
        dp[0] = 1;
        for(int i = 0; i<score.size(); i++)
            dp[score[i]] = 1;
        
        for(int i = 0; i<100; i++) {
            if(dp[i] > 0) {
                for(int j = 0; j<score.size(); j++)
                    dp[i + score[j]]++;
                }
        }
        
        for(int i = 0; i<100; i++)
                   if(dp[i] > 0)
                       answer++;
        
        cout << "#" << test_case + 1 << " " << answer << endl;
        
    }
    
    return 0;
}
