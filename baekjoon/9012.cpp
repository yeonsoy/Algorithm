#include <iostream>
#include <stack>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 괄호

int N;
string str;

int main() {
    
    fastio();
    
    cin >> N;
    
    for(int test_case = 0; test_case < N; test_case++) {
        cin >> str;
        stack <char> st;
        
        bool flag = true;
        for(int i = 0; i<str.size(); i++) {
            if(str[i] == '(') {
                st.push('(');
            }
            else {
                if(!st.empty())
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag && st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}
