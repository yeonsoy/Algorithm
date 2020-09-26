#include <string>
#include <vector>
using namespace std;

// JadenCase 문자열 만들기

string solution(string s) {
    
    bool flag = true;
    for(int i = 0; i<s.size(); i++) {
        
        if(flag) {
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 'a' - 'A';
            flag = false;
        }
        else {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        
        if(s[i] == ' ') flag = true;
    }
    
    return s;
}
