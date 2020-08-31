#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 명령 프롬프트

int N;
vector <string> st;

bool checkSame(int n)
{
    char ch = st[0][n];
    for (int i = 1; i < st.size(); i++)
    {
        if (ch == st[i][n])
            continue;
        else
            return false;
    }

    return true;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        st.push_back(s);

        if (N == 1)
        {
            cout << s;
            return 0;
        }
    }

    for (int i = 0; i < st[0].size(); i++)
    {
        if (checkSame(i))
            cout << st[0][i];
        else
            cout << "?";
    }

    return 0;
}
