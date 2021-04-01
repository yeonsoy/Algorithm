#include <iostream>
#include <map>
using namespace std;

// 나머지

int N;
map <int, int> m;

int main() {

    for (int i = 0; i < 10; i++) {
        cin >> N;

        m[N % 42]++;
    }

    cout << m.size();

    return 0;
}
