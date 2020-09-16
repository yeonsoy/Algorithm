#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문자열 내림차순으로 배치하기

bool desc(int a, int b){ return a > b; }

string solution(string s) {
    string answer = "";
    int len = 0;
    for(int i = 0; s[i]; i++)
        len++;
    
    vector <int> str;
    for(int i = 0; i<len; i++)
        str.push_back(s[i]);
    
    sort(str.begin(), str.end(), desc);
    
    for(int i = 0; i<str.size(); i++)
        answer += str[i];
    
    return answer;
}
