#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 수 정렬하기 2

int N;
vector <int> num;

int main() {

    fastio();

    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    for (int i = 0; i < N; i++)
        cout << num[i] << "\n";

    return 0;
}
