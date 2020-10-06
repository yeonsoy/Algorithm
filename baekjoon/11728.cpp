#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 배열 합치기

int N, M;
vector <int> answer;

int main() {
    
    fastio();
    
    cin >> N >> M;
    answer.resize(N + M);
    
    for(int i = 0; i<N + M; i++)
        cin >> answer[i];
    
    sort(answer.begin(), answer.end());
    
    for(int i = 0; i<answer.size(); i++)
        cout << answer[i] << " ";
    
    return 0;
}
