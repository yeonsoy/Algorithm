#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 컨베이어 벨트 위의 로봇

int N, K;
int cb[201];
int robot[201];

int main() {
    
    fastio();
    
    cin >> N >> K;
    
    int pivot = N - 1;
    int cur_first = 0;
    int answer = 1;
    int zero_cnt = 0;
    
    for(int i = 0; i<2 * N; i++)
        cin >> cb[i];
    
    queue <int> que;
    
    while(true) {
        
        bool flag = false;
        pivot--;
        if(pivot < 0)
            pivot = 2 * N - 1;
        
        cur_first--;
        if(cur_first < 0)
            cur_first = 2 * N - 1;
        
        // N번 칸에 있는 위치에 있으면 내린다
        robot[pivot] = 0;
        
        auto size = que.size();
        while(size--) {
            int pos = que.front();
            que.pop();
            if(pos == pivot)
                continue;
            
            int next_idx = (pos + 1) % (2 * N);
            if(robot[next_idx] == 1 || cb[next_idx] == 0) {
                que.push(pos);
                continue;
            }
            
            cb[next_idx]--;
            if(cb[next_idx] == 0)
                zero_cnt++;
            
            if(zero_cnt >= K) {
                flag = true;
                break;
            }
            
            robot[next_idx] = 1;
            robot[pos] = 0;
            
            if(next_idx == pivot) continue;
            que.push(next_idx);
        }
        
        if(flag)
            break;
        
        // N번 칸에 있는 위치에 있으면 내린다
        robot[pivot] = 0;
        
        if(cb[cur_first] > 0 && robot[cur_first] == 0) {
            robot[cur_first] = 1;
            cb[cur_first]--;
            que.push(cur_first);
            if(cb[cur_first] == 0)
                zero_cnt++;
        }
        
        if(zero_cnt >= K)
            break;
        
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}
