#include <iostream>
#include <stack>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 균형잡힌 세상

string str;

int main() {

    while (true) {

        getline(cin, str);

        if (str == ".")
            break;

        stack <char> st;
        bool flag = true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
            {
                if (st.empty()) {
                    if (str[i] == '(' || str[i] == '[')
                        st.push(str[i]);
                    else
                    {
                        cout << "no" << endl;
                        flag = false;
                        break;
                    }
                }
                else {
                    char check = st.top();
                    if (check == '(')
                    {
                        if (str[i] == '(' || str[i] == '[')
                            st.push(str[i]);
                        else if (str[i] == ')')
                            st.pop();
                        else
                        {
                            cout << "no" << endl;
                            flag = false;
                            break;
                        }
                    }
                    else if (check == '[')
                    {
                        if (str[i] == '(' || str[i] == '[')
                            st.push(str[i]);
                        else if (str[i] == ']')
                            st.pop();
                        else
                        {
                            cout << "no" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        if (flag && !st.empty()) {
            cout << "no" << endl;
            flag = false;
        }


        if (!flag) continue;
        else cout << "yes" << endl;
    }

    return 0;
}
