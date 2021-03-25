#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 떡국

int N;
vector <int> soup;
unordered_map<int, int> m;
int answer = 1;

int main() {

	cin >> N;
	soup.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> soup[i];
		m[soup[i]]++;

		answer = max(answer, m[soup[i]]);
	}

	cout << answer << "\n";

	return 0;
}