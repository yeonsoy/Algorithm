#include <iostream>
using namespace std;

// 곱셈

int A, B, C;

int pow(int n, int k) {
	if (k == 0) return 1;

	long long temp = pow(n, k / 2);
	long long res = temp * temp % C;

	if (k % 2 == 1)
		res = res * n % C;

	return res;
}

int main() {

	cin >> A >> B >> C;
	cout << pow(A, B) << endl;

	return 0;
}