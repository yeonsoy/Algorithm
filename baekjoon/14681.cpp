#include <iostream>
using namespace std;

// 사분면 고르기

int x, y;

int main() {
	cin >> x >> y;

	if (x > 0 && y > 0)
		cout << 1 << "\n";
	else if (x < 0 && y > 0)
		cout << 2 << "\n";
	else if (x < 0 && y < 0)
		cout << 3 << "\n";
	else
		cout << 4 << "\n";

	return 0;
}