#include <iostream>
using namespace std;

// 다이어트

int G;
long long answer;
bool isPossible = false;

int main() {

	cin >> G;

	long long past = 1, cur = 1;

	while (true) {

		long long diff = cur * cur - past * past;

		if (diff == G) {
			isPossible = true;
			cout << cur << "\n";
		}

		if (cur - past == 1 && diff > G)
			break;

		if (diff > G)
			past++;
		else
			cur++;
	}

	if (!isPossible)
		cout << -1 << "\n";

	return 0;
}