#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
string str;

// 비밀번호

int main() {
    
    for(int test_case = 0; test_case < 10; test_case++) {
        cin >> N;
        cin >> str;
        
        string result = "";
        
        auto length = str.size();
        bool flag = false;
        while(true) {
            for(int i = 0; str[i]; i++) {
                if(flag) {
                    flag = false;
                    continue;
                }
                
                if(str[i] == str[i+1] && !flag) {
                    flag = true;
                    continue;
                }
                else
                    result += str[i];
            }
            str = result;
            result = "";
            if(length == str.size())
                break;
            else
                length = str.size();
            
        }
        
        cout << "#" << test_case + 1 << " " << str << endl;
        
    }
    
    return 0;
}
