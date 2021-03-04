#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 이항 계수 1

int N, K;

int main() {

    fastio();

    cin >> N >> K;

    int a = 1, b = 1;

    for (int i = 0; i < K; i++) {
        a *= N - i;
        b *= K - i;
    }

    cout << a / b;

    return 0;
}
