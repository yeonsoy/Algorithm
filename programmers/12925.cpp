#include <string>
#include <vector>
using namespace std;

// 문자열을 정수로 바꾸기

int solution(string s) {
    int answer = 0;
    int idx = 1;
    bool isMinus = false;
    
    for(int i = s.size() - 1; i>=0; i--)
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += (s[i] - '0') * idx;
            idx *= 10;
        }
        else if(s[i] == '-') isMinus = true;
    
    if(isMinus) answer = -answer;
    
    return answer;
}
