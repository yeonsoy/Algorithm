#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// ACM 호텔

int T;

int main() {

    fastio();

    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {

        int H, W, N;
        cin >> H >> W >> N;

        int height = (N - 1) % H + 1, width = (N - 1) / H + 1;
        if (width < 10)
            cout << height << "0" << width << endl;
        else
            cout << height << width << endl;
    }

    return 0;
}
