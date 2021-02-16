#include <iostream>
#include <vector>
using namespace std;

// 차이를 최대로

int N;
vector <int> A;
vector <int> sum;
bool isVisited[9];
int answer;

void go(int cnt) {
	if (cnt == N) {
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (i + 1 < N)
				res += abs(sum[i] - sum[i + 1]);
		}

		answer = max(res, answer);

		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!isVisited[i]) {
			isVisited[i] = true;
			sum.push_back(A[i]);
			go(cnt + 1);
			sum.pop_back();
			isVisited[i] = false;
		}
	}
}

int main() {

	cin >> N;
	A.resize(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	go(0);

	cout << answer;

	return 0;
}