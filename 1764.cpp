#include <iostream>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 듣보잡

int N, M;
map <string, int> m;
string str;
int answer;

int main() {
    
    fastio();
    
    cin >> N >> M;
    
    for(int i = 0; i<N+M; i++)
    {
        cin >> str;
        m[str]++;
        if(m[str] == 2) answer++;
    }
    
    cout << answer << "\n";
    
    map <string, int>::iterator iter;
    
    for(iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second > 1)
            cout << iter->first << "\n";
    }
    
    return 0;
}
