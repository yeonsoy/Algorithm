#include <iostream>
using namespace std;

// 문자열 반복

int T;

int main() {

    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        string str;

        cin >> N >> str;

        for (int j = 0; j < str.size(); j++)
            for (int k = 0; k < N; k++)
                cout << str[j];

        cout << endl;
    }

    return 0;
}
