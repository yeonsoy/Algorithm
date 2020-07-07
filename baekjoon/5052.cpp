#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 전화번호 목록

int t;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    
    int n;
    for(int test_case = 0; test_case < t; test_case++) {
        cin >> n;
        
        map <string, int> m;
        vector <string> strs;
        string str;
        bool isPossible = false;
        for(int i = 0; i<n; i++) {
            cin >> str;
            m[str]++;
            strs.push_back(str);
            
            if(!isPossible) {
                string temp = "";
                for(int j = 0; j<str.size() - 1; j++) {
                    temp += str[j];
                    if(m[temp] > 0) {
                        isPossible = true;
                        break;
                    }
                }
            }
        }
        
        if(!isPossible) {
            for(int i = 0; i<n; i++) {
                string temp = "";
                for(int j = 0; j<strs[i].size() - 1; j++) {
                    temp += strs[i][j];
                    if(m[temp] > 0) {
                        isPossible = true;
                        break;
                    }
                }
            }
        }
        
        if(isPossible)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    
    
    return 0;
}
