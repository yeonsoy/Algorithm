#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 최솟값 찾기

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int N, L;
deque <pair<int, int>> dq;
vector <int> number;

int main() {
    
    fastio();
    
    cin >> N >> L;
    
    number.resize(N);
    
    for(int i = 0; i<N; i++)
        cin >> number[i];
    
    for(int i = 0; i<N; i++) {
        
        // dq에 L 길이 이하의 값이 저장
        if(!dq.empty() && dq.front().second <= i - L)
            dq.pop_front();
        
        // 뒤에 있는 수가 지금 수보다 크면 pop (현재 수보다 작은 수만 남기기)
        while(!dq.empty() && dq.back().first > number[i])
            dq.pop_back();
        
        dq.push_back({number[i], i});
        cout << dq.front().first << " ";
    }
    
    return 0;
}
