#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 문자열 잘라내기

int R, C;
int answer;
string strs[1002];

bool check(int count) {
    
    map <string, int> m;
    
    for(int i = 0; i<C; i++) {
        string s = "";
        
        for(int j = count; j<R; j++)
            s += strs[j][i];
        
        m[s]++;
        if(m[s] > 1) return false;
    }
    
    return true;
}

void solve() {
    
    int start = 0;
    int end = R - 1;
    int mid = 0;
    
    bool isRight = false;
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if (!check(mid)) {
            end = mid - 1;
            isRight = false;
        }
        else {
            start = mid + 1;
            isRight = true;
        }
    }
    
    if(isRight)
        answer = mid;
    else
        answer = mid - 1;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    
    for(int i = 0; i<R; i++)
        cin >> strs[i];
    
    solve();
    
    cout << answer;
    
    return 0;
}
