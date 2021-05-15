#include <iostream>
using namespace std;

// 홀짝 칵테일

int A, B, C;
long long answer = 1;

int main() {

	cin >> A >> B >> C;

	if (A % 2 == 1)
		answer *= A;
	
	if (B % 2 == 1)
		answer *= B;

	if (C % 2 == 1)
		answer *= C;

	if (A % 2 == 0 && B % 2 == 0 && C % 2 == 0)
		answer = A * B * C;

	cout << answer << "\n";

	return 0;
}