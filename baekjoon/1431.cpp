#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 시리얼 번호

int N;
vector <string> serial;

bool compare(string a, string b) {
	if (a.size() == b.size())
	{
		int a_sum = 0;
		for (int i = 0; i < a.size(); i++)
			if (a[i] >= '0' && a[i] <= '9')
				a_sum += a[i] - '0';

		int b_sum = 0;
		for (int i = 0; i < b.size(); i++)
			if (b[i] >= '0' && b[i] <= '9')
				b_sum += b[i] - '0';

		if (a_sum == b_sum) {
			return a < b;
		}
		else
			return a_sum < b_sum;
	}
	else
		return a.size() < b.size();
}

int main() {

	cin >> N;

	serial.resize(N);

	for (int i = 0; i < N; i++)
		cin >> serial[i];

	sort(serial.begin(), serial.end(), compare);

	for (int i = 0; i < N; i++)
		cout << serial[i] << "\n";

	return 0;
}