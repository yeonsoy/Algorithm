#include <iostream>
using namespace std;

// 골드 러시

int t;
long long n, a, b;

int main() {
	cin >> t;

	for (int test_case = 0; test_case < t; test_case++) {
		cin >> n >> a >> b;

		int answer = -1;
		long long gold = 1;

		if (a % 2 == 1)
			cout << n << "\n";
		else {
			for(int i = 0; i<n; i++)
				gold *= 2;

			while (a > 0) {
				if (a >= gold)
					a -= gold;

				gold /= 2;
				answer++;
			}

			cout << answer << "\n";
		}

	}

	return 0;
}