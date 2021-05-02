#include <iostream>
using namespace std;

// 석찬이의 받아쓰기

int T;

int main() {

    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        int N;
        int answer = 0;
        cin >> N;
        string a, b;
        cin >> a >> b;

        for (int i = 0; i < N; i++)
            if (a[i] == b[i])
                answer++;

        cout << "#" << test_case + 1 << " " << answer << endl;
    }

    return 0;
}