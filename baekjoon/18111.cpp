#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 마인크래프트

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef pair<int, int> point;
int N, M;
long long B;
long long block_count;
int minecraft[501][501];
int mc[501][501];
long long ans_time = 2e9, height;


bool check() {
    
    int ch = mc[0][0];
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(mc[i][j] != ch) return false;
    
    return true;
}

long long isPossible(int n, long long b) {
    
    memset(mc, 0, sizeof(mc));
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            mc[i][j] = minecraft[i][j];
    
    long long t = 0;
    
    while(true) {
        
        if(check()) break;
        for(int i = 0; i<N; i++)
            for(int j = 0; j<M; j++)
            {
                if(mc[i][j] == n) continue;
                // 목표 높이보다 큰 경우
                else if(mc[i][j] > n){
                    
                    // 블록을 퍼낸다
                    t += (mc[i][j] - n) * 2;
                    b += (mc[i][j] - n);
                    mc[i][j] = n;
                }
            }
        
        for(int i = 0; i<N; i++)
            for(int j = 0; j<M; j++)
            {
                if(mc[i][j] == n) continue;
                // 목표 높이보다 작은 경우
                else if(mc[i][j] < n){
                    // 인벤토리 블록을 사용한다
                    b -= n - mc[i][j];
                    t += n - mc[i][j];
                    mc[i][j] = n;
                }
            }
    }
    
    return t;
}


int main() {
    
    fastio();
    
    cin >> N >> M >> B;
    
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++) {
            cin >> minecraft[i][j];
            block_count += minecraft[i][j];
        }
    
    block_count += B;
    
    for(int i = 256; i >= 0; i--) {
        // 전체 블록이 목표 높이만큼 존재하지 않는 경우
        if(block_count < i * N * M) continue;
        long long temp = isPossible(i, B);
        
        if(temp < ans_time)
        {
            ans_time = temp;
            height = i;
        }
    }
    
    cout << ans_time << " " << height << endl;
    
    
    return 0;
}
