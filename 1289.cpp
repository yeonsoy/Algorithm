#include <iostream>
using namespace std;

int T;

// 원재의 메모리 복구하기

int main() {
    
    cin >> T;
    
    for(int test_case = 0; test_case < T; test_case++) {
        
        string str;
        cin >> str;
        
        int answer = 0;
        
        if(str.size() == 1) {
            if(str[0] == '1')
                answer = 1;
            else answer = 0;
        }
        else
        {
            char pivot = '0';
            for(int i = 0; i<str.size(); i++) {
                if(pivot != str[i]) {
                    pivot = str[i];
                    answer++;
                }
            }
        }
        cout << "#" << test_case + 1 << " " << answer << endl;
        
    }
    
    return 0;
}
