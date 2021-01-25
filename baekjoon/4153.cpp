#include <iostream>
using namespace std;

// 직각삼각형

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int a, b, c;

int main() {

    fastio();

    while (true) {

        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
            break;

        if (a >= b && a >= c) {
            if (a * a == b * b + c * c)
                cout << "right\n";
            else
                cout << "wrong\n";
        }
        if (b >= a && b >= c) {
            if (b * b == a * a + c * c)
                cout << "right\n";
            else
                cout << "wrong\n";
        }
        if (c >= a && c >= b) {
            if (c * c == a * a + b * b)
                cout << "right\n";
            else
                cout << "wrong\n";
        }

    }

    return 0;
}
