#include <iostream>
#include <vector>
using namespace std;

// 유레카 이론

vector <int> tri_num;
bool isPossible[1001];

int main() {

	int n = 0;
	int idx = 1;
	while (n < 1000) {
		n += idx;
		tri_num.push_back(n);
		idx++;
	}

	for (int i = 0; i < tri_num.size(); i++)
		for (int j = 0; j < tri_num.size(); j++)
			for (int k = 0; k < tri_num.size(); k++)
				if (tri_num[i] + tri_num[j] + tri_num[k] > 1000)
					break;
				else
					isPossible[tri_num[i] + tri_num[j] + tri_num[k]] = true;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> idx;
		cout << isPossible[idx] << "\n";
	}

	return 0;
}