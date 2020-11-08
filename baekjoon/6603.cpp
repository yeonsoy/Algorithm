#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 로또

vector <int> rotto;
vector <int> answer(6, 0);

void solve(int idx, int cnt) {

	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < rotto.size(); i++) {
		answer[cnt] = rotto[i];
		solve(i + 1, cnt + 1);
	}
}

int main() {

	fastio();

	int k;
	while (true) {
		cin >> k;

		if (k == 0)
			break;

		rotto.resize(k);

		for (int i = 0; i < k; i++)
			cin >> rotto[i];

		solve(0, 0);

		cout << "\n";
	}
	
	return 0;
}