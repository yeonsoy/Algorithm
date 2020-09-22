#include <string>
#include <vector>
using namespace std;

// 시저 암호

char setPassword(char ch, int n) {
    
    if(ch >= 'a' && ch <= 'z') {
        if(ch + n <= 'z')
            return ch + n;
        else
             return 'a' + (ch + n -'z' - 1);
    }
    else {
        if(ch + n <= 'Z')
            return ch + n;
        else
            return 'A' + (ch + n -'Z' - 1);
    }
    
}

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i<s.size(); i++) {
        if(s[i] != ' ')
            answer += setPassword(s[i], n);
        else answer += s[i];
    }
    
    return answer;
}
