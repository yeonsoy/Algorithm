#include <iostream>
#include <vector>
using namespace std;

// 근손실

// 500 K * Day만큼씩 감소

int N, K;
vector <int> fit;
vector <int> muscle;
bool isUsed[9];
int answer;

void solve(int count) {
    
    if(count == N) {
        
        bool flag = false;
        int start = 500;
        for(int i = 0; i<muscle.size(); i++) {
            start = start - K + fit[muscle[i]];
            if(start < 500) {
                flag = true;
                break;
            }
        }
        
        if(!flag) answer++;
        
        return;
    }
    
    for(int i = 0; i<N; i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            muscle.push_back(i);
            solve(count + 1);
            muscle.pop_back();
            isUsed[i] = false;
        }
    }
    
}


int main() {
    cin >> N >> K;
    
    for(int i = 0; i<N; i++)
    {
        int temp;
        cin >> temp;
        fit.push_back(temp);
    }
    
    solve(0);
    
    cout << answer;
    
    return 0;
}
