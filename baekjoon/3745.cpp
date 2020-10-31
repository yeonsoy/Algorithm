#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 오름세

int N;

int main() {

	fastio();

	while (cin >> N) {

		vector <int> arr(1, 0);
		int cur;
		for (int i = 0; i < N; i++)
		{
			cin >> cur;
			if (arr.back() < cur)
				arr.push_back(cur);
			else
				*lower_bound(arr.begin(), arr.end(), cur) = cur;
		}

		cout << arr.size() - 1 << "\n";
	}

	return 0;
}