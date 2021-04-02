#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 숫자 카드 2

int N, M;
vector <int> num;

int main() {
    fastio();

    cin >> N;
    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    cin >> M;
    int temp;
    for (int i = 0; i < M; ++i) {
        cin >> temp;
        cout << upper_bound(num.begin(), num.end(), temp) - lower_bound(num.begin(), num.end(), temp) << ' ';
    }

    return 0;
}