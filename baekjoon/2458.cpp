#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, M;
int comp[501][501];
int answer;

// 키 순서

int main() {
    
    fastio();
    
    cin >> N >> M;
    
    int a, b;
    for(int i = 0; i<M; i++) {
        cin >> a >> b;
        
        comp[a][b] = 1;
    }
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++)
                if(comp[j][i] + comp[i][k] == 2)
                    comp[j][k] = 1;
    
    
    for(int i = 1; i<=N; i++) {
        
        bool flag = true;
        for(int j = 1; j<=N; j++) {
            if(i == j) continue;
            if(comp[i][j] + comp[j][i] < 1) {
                flag = false;
                break;
            }
        }
        
        if(flag) answer++;
    }
    
    cout << answer << endl;
    
}


