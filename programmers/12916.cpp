#include <string>
#include <iostream>
using namespace std;

// 문자열 내 p와 y의 개수

bool solution(string s)
{
    bool answer = true;

    int p_count = 0;
    int y_count = 0;
    
    int len = 0;
    
    for(int i = 0; s[i]; i++)
        len ++;
    
    for(int i = 0; i<len; i++)
    {
        if(s[i] == 'y' || s[i] == 'Y')
            y_count ++;
          if(s[i] == 'p' || s[i] == 'P')
            p_count ++;
    }
    
    answer = (p_count == y_count);

    return answer;
}
