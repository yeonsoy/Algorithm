#include <iostream>
#include <map>
using namespace std;

// 문자 해독

int g, s;
map <char, int> W;
map <char, int> S;
string origin, str;
int answer;

bool check() {
    
    for(int i = 0; i<g; i++)
        if(W[origin[i]] != S[origin[i]])
            return false;
    
    return true;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> g >> s;
    
    cin >> origin;
    
    for(int i = 0; i<g; i++)
        W[origin[i]]++;
    
    int length = 0;
    int idx = 0;
    
    cin >> str;
    
    for(int i =0; i<s; i++) {
        S[str[i]]++;
        length++;
        
        if(length == g) {
            
            if(check()) answer++;
            
            S[str[idx]]--;
            length--;
            idx++;
        }
    }
    
    cout << answer <<endl;
    
    return 0;
}
