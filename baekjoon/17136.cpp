#include <iostream>
using namespace std;

// 색종이 붙이기

int map[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int result, answer = 2e9;

void solve(int r, int c)
{
    if(c == 10) {
        solve(r + 1, 0);
        return;
    }
    
    if(r == 10) {
        answer = min(result, answer);
        return;
    }
    
    if(map[r][c] == 0) {
        solve(r, c + 1);
        return;
    }
    
    // 큰 색종이부터 붙여보기
    for(int i = 5; i>=1; i--) {
        
        // 현재 색종이가 존재하지 않는 경우 or 범위를 벗어나는 경우
        if(paper[i] == 0 || r + i > 10 || c + i > 10)
            continue;
        
        bool flag = true;
        
        for(int j = 0; j<i; j++)
            for(int k = 0; k<i; k++) {
                if(map[r + j][c + k] == 0) {
                    flag = false;
                    break;
                }
                
                if(!flag) break;
            }
        
        if(!flag) continue; // 1이 아닌 수가 범위에 존재한 경우
        
        for(int j = 0; j<i; j++)
            for(int k = 0; k<i; k++)
                map[r + j][c + k] = 0;
        
        paper[i]--;
        result++;
        
        solve(r, c + i);
        
        for(int j = 0; j<i; j++)
            for(int k = 0; k<i; k++)
                map[r + j][c + k] = 1;
        
        paper[i]++;
        result--;
        
    }
}

int main() {
    
    for(int i = 0; i<10; i++)
        for(int j = 0; j<10; j++)
            cin >> map[i][j];
    
    solve(0, 0);
    
    if(answer == 2e9)
        answer = -1;
    
    cout << answer << endl;
    
    return 0;
}
