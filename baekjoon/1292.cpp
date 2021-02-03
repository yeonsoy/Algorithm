#include <iostream>
using namespace std;

// 쉽게 푸는 문제 

int A, B;
int arr[1001];

int main() {

	int idx = 1;
	int cur = 0;
	while (true) {
		int i = cur;
		for(i = cur; i < cur + idx && i < 1001; i++)
			arr[i] = idx;

		idx++;
		cur = i;

		if (cur > 1000)
			break;
	}

	cin >> A >> B;

	int answer = 0;
	for (int i = A - 1; i < B; i++)
		answer += arr[i];

	cout << answer;

	return 0;
}