#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

// 소가 정보섬에 올라온 이유

int N;
int Q;
int cows[200001];
int grade[200001];
int sum[200001];
long long answer;

int main() {
    
    fastio();
    
    cin >> N >> Q;
    
    for(int i = 0; i<N; i++)
        cin >> cows[i];
    
    for(int i = 0; i<Q; i++)
        cin >> grade[i];
    
    for(int i = 0; i<N; i++)
    {
        int n = 1;
        
        for(int j = 0; j<4; j++) {
            int idx = i + j;
            if(idx >= N) idx -= N;
            
            n *= cows[idx];
        }
        
        sum[i] = n;
        answer += sum[i];
    }
    
    for(int i = 0; i<Q; i++) {
        int idx = grade[i] - 1;
        
        for(int j = 0; j<4; j++)
        {
            answer -= sum[idx];
            sum[idx] *= -1;
            answer += sum[idx];
            idx--;
            if(idx < 0) idx = N - 1;
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
