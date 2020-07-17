#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
// 계산기1

int n;
stack <char> st;
 
int main()
{
    for (int t = 0; t < 10; t++)
    {
        cin >> n;
        int sum = 0;
        string postfix = "";
 
        char ch;
        scanf(" %1c", &ch);
        postfix += ch;
 
        for (int i = 1; i < n; i++)
        {
            scanf("%1c", &ch);
            if (ch == '+' || ch == '*')
            {
                st.push(ch);
            }
            else
            {
                postfix += ch;
                postfix += st.top();
                st.pop();
            }
        }
 
        int flag = 1;
        for (int i = 0; postfix[i]; i++)
        {
            int a;
            int b;
            if (postfix[i] == '+')
            {
                if (flag)
                {
                    a = st.top() - '0'; st.pop();
                    b = st.top() - '0'; st.pop();
                    sum = a + b;
                    flag = 0;
                }
                else
                {
                    a = st.top() - '0'; st.pop();
                    sum = sum + a;
                }
            }
            else
            {
                st.push(postfix[i]);
            }
        }
 
        cout << "#" << t + 1 << " " << sum << endl;
    }
 
}
