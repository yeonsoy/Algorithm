#include <iostream>
using namespace std;

// 피보나치 함수

int T;
pair<int, int> fibo[41];

pair<int, int> fibonacci(int n) {

    fibo[0] = { 1, 0 };
    fibo[1] = { 0, 1 };
    if (n == 0 || n == 1)
        return fibo[n];
    else if (fibo[n].first > 0 || fibo[n].second > 0)
        return fibo[n];
    else {
        auto a = fibonacci(n - 1);
        auto b = fibonacci(n - 2);
        return fibo[n] = { a.first + b.first, a.second + b.second };
    }
}

int main() {

    cin >> T;

    int n;
    for (int test_case = 0; test_case < T; test_case++) {

        cin >> n;
        auto answer = fibonacci(n);
        cout << answer.first << " " << answer.second << endl;
    }

    return 0;
}
