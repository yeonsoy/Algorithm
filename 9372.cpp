#include <iostream>

using namespace std;
int T;

// 간선에 가중치 존재하지 않음.
// 모든 노드가 서로를 거쳐서 서로를 방문할 수 있다면,
// 가장 최소 방문 횟수는 당연하게도 (정점 개수 - 1)번이다.

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++)
    {
        int N, M;
        cin >> N >> M;
        
        for(int i=0; i<M; i++)
        {
            int a, b;
            cin>> a >> b;
        }
        
        cout << N - 1 << endl;
    }
    return 0;
}
