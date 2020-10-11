#include <iostream>
using namespace std;

// 한국이 그리울 땐 서버에 접속하지

int N;
string pattern;

int main() {
    
    cin >> N >> pattern;

    string st;
    string ed;
    
    bool flag = true;
    for(int i = 0; i<pattern.size(); i++) {
        if(flag) {
            if(pattern[i] != '*')
            st += pattern[i];
            else
                flag = false;
        }
        else
            ed += pattern[i];
    }

    string str;

    for(int i = 0; i<N; i++) {
        cin >> str;

        flag = true;
        for(int j = 0; j<st.size(); j++) {
            if(st[j] != str[j])
            {
                flag = false;
                break;
            }
        }

        if(!flag) cout << "NE\n";
        else {
            int check_ed = ed.size() - 1;
            for(int j = str.size() - 1; j>=0; j--) {
                if(j < st.size() || check_ed < 0)
                    break;
                
                if(ed[check_ed] != str[j])
                    break;
                else
                    check_ed--;
            }
        
            if(check_ed < 0) cout << "DA\n";
            else cout << "NE\n";
        }
    }
    
    return 0;
}
