#include <iostream>
using namespace std;

// 숫자의 개수 2

long long answer;
long long A, B, C;
int number[10];

int main() {

	cin >> A >> B >> C;

	answer = A * B * C;

	while (answer) {
		number[answer % 10]++;
		answer /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << number[i] << "\n";

	return 0;
}