#include <string>
#include <vector>
using namespace std;

// 가운데 글자 가져오기

string solution(string s) {
    string answer = "";
    
    int len = 0;
    
    for(int i = 0; s[i] ; i++)
        len++;
    
    if(len % 2 == 1)
        answer += s[len/2];
    else
    {
        answer += s[len/2 - 1];
        answer += s[len/2];
    }
    
    return answer;
}
