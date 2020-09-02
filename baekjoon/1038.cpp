#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 감소하는 수

int N;
vector <long> answer;
bool isUsed[10];

void solve(int idx) {
    string num = "";
    
    for(int i = 9; i>= 0; i--)
        if(isUsed[i])
            num += ('0' + i);
  
    if(num.size() > 0)
        answer.push_back(stol(num));
    
    for(int i = idx; i < 10; i ++)
        if(!isUsed[i]) {
            isUsed[i] = true;
            solve(i + 1);
            isUsed[i] = false;
        }
}


int main() {
    
    cin >> N;
    
    if(N > 1022) cout << -1 << endl;
    else {
        solve(0);
        sort(answer.begin(), answer.end());
        cout << answer[N];
    }
    
    return 0;
}
