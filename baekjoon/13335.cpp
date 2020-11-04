#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 트럭

int n, w, L;
vector <int> truck;
int answer;

int main() {

	cin >> n >> w >> L;
	truck.resize(n);

	for (int i = 0; i < n; i++)
		cin >> truck[i];

	queue <int> que;
	int st = 0;
	int ed = 0;
	int sum = 0;

	while (ed != n) {

		if (que.size() >= w) {
			int front = que.front();
			sum -= front;
			que.pop();

			if (front != 0)
				ed++;
		}
		
		if (st < n && truck[st] + sum <= L) {
			que.push(truck[st]);
			sum += truck[st];
			st++;
		}
		else
			que.push(0);

		answer++;
	}

	cout << answer << "\n";

	return 0;
}