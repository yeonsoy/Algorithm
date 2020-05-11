#include <iostream>
#include <stack>
using namespace std;

// 문자열 폭발

string str;
string bomb;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str >> bomb;
    
    string answer = "";
    
    for (int i = 0; i < str.size(); i++)
    {
        answer += str[i];
        
        bool flag = false;
        // bomb 글자 이상의 글자를 보았을 때 마지막 bomb와 일치하면
        if (str[i] == bomb[bomb.size() - 1] && i >= bomb.size() - 1)
        {
            flag = true;
            for (int j = 0; j < bomb.size(); j++)
                if (answer[answer.size() - 1 - j] != bomb[bomb.size() - 1 - j])
                    flag = false;

            if (flag)
                // answer에 남아있는 글자 폭발
                for (int j = 0; j < bomb.size(); j++)
                    answer.pop_back();
        }
    }

    if (!answer.empty())
        cout << answer << endl;
    else
        cout << "FRULA" << endl;
    
    return 0;
}
