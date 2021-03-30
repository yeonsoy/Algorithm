#include <iostream>
using namespace std;

// 팰린드롬수 

int N;

bool check(int num) {

    string n = to_string(num);

    for (int i = 0; i < n.size() / 2; i++)
        if (n[i] != n[n.size() - i - 1])
            return false;

    return true;
}

int main() {

    while (true) {

        cin >> N;

        if (N == 0) break;

        if (check(N))
            cout << "yes\n";
        else
            cout << "no\n";

    }

    return 0;
}
