#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// 구간 합 구하기 4

int N, M;
vector <int> numbers;
vector <int> sum;

int main() {

	fastio();

	cin >> N >> M;
	numbers.resize(N + 1);
	sum.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> numbers[i];
		sum[i] = sum[i - 1] + numbers[i];
	}

	int i, j;
	for (int test_case = 0; test_case < M; test_case++) {
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}

	return 0;
}