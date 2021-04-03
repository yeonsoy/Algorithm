#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자 더하기

int N;
vector<int> number;
long long answer = 2e9;
int zero = 0;

long long makeNumber(string str) {
	long long res = 0;
	long long idx = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		res += (str[i] - '0') * idx;
		idx *= 10;
	}

	return res;
}

void go(string a, string b, int idx, int remain_zero) {
	if (idx == number.size() && remain_zero == 0 && a.size() > 0 && b.size() > 0) {
		answer = min(makeNumber(a) + makeNumber(b), answer);
		return;
	}

	if (idx < number.size()) {
		go(a + to_string(number[idx]), b, idx + 1, remain_zero);
		go(a, b + to_string(number[idx]), idx + 1, remain_zero);
	}

	if (remain_zero > 0) {
		if (a.size() > 0)
			go(a + "0", b, idx, remain_zero - 1);
		if (b.size() > 0)
			go(a, b + "0", idx, remain_zero - 1);
	}
}


int main() {

	while (true) {
		cin >> N;
		if (N == 0)
			break;

		int temp = 0;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			if (temp == 0)
				zero++;
			else
				number.push_back(temp);
		}

		sort(number.begin(), number.end());
		go("", "", 0, zero);

		cout << answer << "\n";
		answer = 2e9;
		zero = 0;
		number.clear();
	}

	return 0;
}