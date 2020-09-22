#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 이상한 문자 만들기

string solution(string s) {
    string answer = "";
    int count = 0;
    for(int i =0; i<s.size(); i++)
    {

        if(count % 2 == 0)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - ('a' - 'A');
        }
        else
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + ('a' - 'A');
        }
        
        if(s[i] != ' ')
            count ++;
        else
           count = 0;
            
    }
    answer = s;
    
    return answer;
}
