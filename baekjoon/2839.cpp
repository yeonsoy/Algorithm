#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 설탕 배달

int N;

int main() {

    fastio();

    cin >> N;

    int answer = 2e9;
    for (int i = 0; i <= N / 5; i++)
        for (int j = 0; j <= N / 3; j++)
            if (i * 5 + j * 3 == N)
                answer = min(answer, i + j);

    if (answer == 2e9)
        answer = -1;

    cout << answer << endl;

    return 0;
}
