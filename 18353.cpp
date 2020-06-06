#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 병사 배치하기

int N;
int answer;
vector <pair<int, int>> person;
int dp[2001];

int main() {
    
    cin >> N;
    
    for(int i = 0; i<N; i++) {
        int power;
        cin >> power;
        person.push_back({power, i + 1});
    }
    
    dp[N - 1] = 1;
    
    for(int i = N - 2; i>=0; i--) {
        int num = 1;
        for(int j = i + 1; j<N; j++) {
            if(person[i].first > person[j].first)
                num = max(num, dp[j] + 1);
        }
        dp[i] = num;
    }
    
    for(int i = 0; i<N; i++)
        answer = max(answer, dp[i]);
    
    cout << N - answer;
    
    return 0;
}
