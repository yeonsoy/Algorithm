#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 로프

int N;
int answer;
vector <int> rope;

int main() {

	cin >> N;

	rope.resize(N);

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope.begin(), rope.end());

	for (int i = 0; i < N; i++)
		answer = max((N - i) * rope[i], answer);

	cout << answer << "\n";

	return 0;
}