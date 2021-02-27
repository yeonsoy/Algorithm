#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 카드 놓기

int n, k;
vector <string> cards;
map <string, bool> m;
bool isUsed[5];

void makeNumber(int cnt, string str) {

	if (cnt == k) {
		m[str] = true;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			makeNumber(cnt + 1, str + cards[i]);
			isUsed[i] = false;
		}
	}

}

int main() {

	cin >> n >> k;
	cards.resize(n);

	for (int i = 0; i < n; i++)
		cin >> cards[i];

	makeNumber(0, "");

	cout << m.size();

	return 0;
}