#include <iostream>
using namespace std;

// 피자 (Large) 

long long N;

int main() {

	cin >> N;

	cout << N * (N - 1) / 2;

	return 0;
}