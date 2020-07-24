#include <iostream>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 문자열 동화

int T;

int main() {
    
    fastio();
    
    cin >> T;
    
    int n;
    string A, B, C;
    
    for(int test_case = 0; test_case<T; test_case++) {
        
        cin >> n;
        cin >> A >> B >> C;
        int answer = 0;
        for(int i = 0; i<n; i++) {
            if(A[i] == B[i] && B[i] == C[i]) continue;
            
            if(A[i] == B[i] || B[i] == C[i] || A[i] == C[i])
                answer++;
            else
                answer += 2;
        }
        
        
        cout << "#" << test_case + 1 << " " << answer << endl;
    }
    
    
    return 0;
}
