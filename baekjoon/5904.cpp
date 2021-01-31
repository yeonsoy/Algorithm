#include <iostream>
using namespace std;

// Moo 게임

long long N;
long long length[101];

char solve(long long n) {
	if (n <= 3) {
		if (n == 1) return 'm';
		else return 'o';
	}

	long long index = 1;
	// 현재 문자열이 위치한 위치 찾기
	while (n > length[index]) {
		index++;
	}

	if (n <= length[index] - length[index - 1])
		if (n - length[index - 1] == 1) return 'm';
		else return 'o';


	return solve(n - length[index - 1] - (1 + (index + 1) + 1));
}

int main() {

	cin >> N;
	length[0] = 3;

	// S[k] = S(k - 1) + m + o * (k + 2) + S(k - 1) 
	for (int i = 1; i < 100; i++) {
		length[i] = length[i - 1] + 1 + (i + 1) + 1 + length[i - 1];
		if (length[i] > 1e9) break;
	}

	cout << solve(N);

	return 0;
}