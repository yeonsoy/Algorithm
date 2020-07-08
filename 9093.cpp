#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 단어 뒤집기

int N;
string str;

int main() {
    
    fastio();
    
    cin >> N;
    cin.ignore();
    
    for(int test_case = 0; test_case < N; test_case++) {
        getline(cin, str);
        string temp;
        for(int i = 0; i<str.size(); i++) {
            if(str[i] == ' ') {
                for(int j = temp.size() - 1; j>= 0; j--)
                    cout << temp[j];
                cout << ' ';
                temp.clear();
            }
            else
                temp += str[i];
        }
        
        for(int j = temp.size() - 1; j>= 0; j--)
            cout << temp[j];
        
        cout << "\n";
        
    }
    
    return 0;
}
