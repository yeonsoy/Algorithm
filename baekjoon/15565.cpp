#include <iostream>
#include <deque>
using namespace std;

// 귀여운 라이언

long long N, K;
long long answer = 2e9;
deque <long long> dq;

int main() {

	cin >> N >> K;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;

		if (n == 1)
			dq.push_back(i);

		if (dq.size() == K) {
			answer = min(dq.back() - dq.front() + 1, answer);
			dq.pop_front();
		}
	}

	if (answer == 2e9)
		answer = -1;

	cout << answer;

	return 0;
}