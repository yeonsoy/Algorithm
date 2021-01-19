#include <iostream>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// 중앙값 구하기

int T;
int M;

int main() {

	fastio();

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> M;
		int number;
		priority_queue <int, vector<int>, less<int>> max_pq;
		priority_queue <int, vector<int>, greater<int>> min_pq;

		cin >> number;
		int mid = number;

		cout << (M + 1) / 2 << "\n";
		cout << mid << " ";

		for (int i = 1; i < M; i++)
		{
			cin >> number;

			if (number < mid)
				max_pq.push(number);
			else
				min_pq.push(number);

			if (i % 2 == 0)
			{
				if (max_pq.size() < min_pq.size())
					max_pq.push(mid);
				else
					min_pq.push(mid);

				if (max_pq.size() > min_pq.size()) {
					mid = max_pq.top();
					max_pq.pop();
				}
				else {
					mid = min_pq.top();
					min_pq.pop();
				}

				cout << mid << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}