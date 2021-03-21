#include <iostream>
using namespace std;

// 칠리소스

long long c;
long long answer;

int main() {
	cin >> c;

	int idx = 1;

	// 7의 제곱수가 0, 1, 2번 사용된다.
	// 0, 1, 2를 표현할 수 있게 3진수 형식으로 표현한다.

	while (c) {
		answer += (c % 7) * idx;
		c /= 7;
		idx *= 3;
	}

	cout << answer;

	return 0;
}