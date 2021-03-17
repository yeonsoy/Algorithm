#include <iostream>
using namespace std;

// 곱셈

int A, B;

int main() {
	cin >> A >> B;

	cout << A * (B % 10) << "\n";
	cout << A * ((B / 10) % 10) << "\n";
	cout << A * (B / 100) << "\n";
	cout << A * B << "\n";

	return 0;
}