#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 한빈이와 Spot Mart

int T;
int N, M;
int answer = -1;
vector <int> weight;

int main() {

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int w;
			cin >> w;
			weight.push_back(w);
		}

		sort(weight.begin(), weight.end());
		reverse(weight.begin(), weight.end());

		for (int i = 0; i < N; i++) {
			int pivot = weight[i];
			for (int j = 0; j < N; j++)
			{
				if (i == j) continue;
				if (pivot + weight[j] <= M) {
					answer = max(pivot + weight[j], answer);
					if (answer == M) break;
				}

			}
		}

		cout << "#" << test_case + 1 << " " << answer << endl;
		answer = -1;
		weight.clear();
	}

	return 0;
}