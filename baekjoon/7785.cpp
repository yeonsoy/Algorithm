#include <iostream>
#include <map>
using namespace std;

// 회사에 있는 사람

int n;
map<string, int> m;

int main() {
    cin >> n;

    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (b == "enter")
            m[a]++;
        else
            m[a]--;
    }

    for (auto it = m.rbegin(); it != m.rend(); it++) {
        if (it->second > 0)
            cout << (it->first) << "\n";
    }


    return 0;
}
