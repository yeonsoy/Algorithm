#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 짝지어 제거하기

int solution(string s)
{
    stack <char> st;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (st.size() > 0)
        {
            char top = st.top();
            
            if (top == s[i])
            {
                st.pop();
                continue;
            }
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
    }
    
    if (st.size() == 0)
        return 1;
    else
        return 0;
}
