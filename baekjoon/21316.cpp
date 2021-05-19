#include <iostream>
#include <vector>
using namespace std;

// 스피카

vector <vector<int>> stars;

bool check(int idx) {
	bool isUsed[3] = { false, false, false };

	for (int i = 0; i < stars[idx].size(); i++)
		isUsed[stars[stars[idx][i]].size() - 1] = true;

	return isUsed[0] && isUsed[1] && isUsed[2];
}

int main() {
	stars.resize(12);

	int x, y;
	for (int i = 0; i < 12; i++) {
		cin >> x >> y;
		stars[x - 1].push_back(y - 1);
		stars[y - 1].push_back(x - 1);
	}

	for (int i = 0; i < 12; i++)
		if (stars[i].size() == 3) {
			if (check(i))
			{
				cout << i + 1 << "\n";
				return 0;
			}
		}

	return 0;
}