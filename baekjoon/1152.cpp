#include <iostream>
using namespace std;

// 단어의 개수

string str;
int answer;

int main() {

    getline(cin, str);

    bool flag = false;
    for (int i = 0; i < str.size(); i++)
        if (!flag && str[i] != ' ') {
            answer++;
            flag = true;
        }
        else if (str[i] == ' ')
            flag = false;

    cout << answer << endl;

    return 0;
}

