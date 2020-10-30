#include <iostream>
#include <queue>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 최대 힙

int N;
priority_queue <int> pq;

int main() {

	fastio();

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;

		if (temp == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}


	return 0;
}
