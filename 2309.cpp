#include <iostream>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 일곱난장이

int height[9];
bool isUsed[9];

void solve(int idx, int sum, int num) {
    
    if(sum == 100 && num == 7) {
        
        for(int i = 0; i<9; i++)
            if(isUsed[i])
                cout << height[i] << '\n';
        
        exit(0);
    }
    
    if(sum > 100) return;
    if(num > 7) return;
    
    
    for(int i = idx; i < 9; i++)
    {
        if(!isUsed[i]) {
            isUsed[i] = true;
            solve(i, sum + height[i], num + 1);
            isUsed[i] = false;
        }
        
    }
    
}

int main() {
    
    fastio();
    
    for(int i = 0; i<9; i++)
        cin >> height[i];
    
    sort(height, height + 9);
    
    solve(0, 0, 0);
    
    return 0;
}
