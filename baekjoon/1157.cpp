#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 단어 공부

string str;
int number['Z' - 'A' + 1];
int max_count;

int main() {

    fastio();

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            number[str[i] - 'a']++;
            max_count = max(max_count, number[str[i] - 'a']);
        }
        else {
            number[str[i] - 'A']++;
            max_count = max(max_count, number[str[i] - 'A']);
        }
    }

    int res = 0;
    char answer;
    for (int i = 0; i < 'Z' - 'A' + 1; i++)
        if (max_count == number[i]) {
            res++;
            answer = i + 'A';

            if (res > 1) {
                cout << "?";

                exit(0);
            }
        }

    cout << answer;

    return 0;
}