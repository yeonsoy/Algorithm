#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A → B 

long long A, B;
unordered_map <long long, bool> m;
queue <pair<long long, long long>> que;

int main() {

	cin >> A >> B;

	que.push({ A, 0 });
	m[A] = true;

	while (!que.empty()) {
		long long cur = que.front().first;
		long long dist = que.front().second;
		que.pop();

		if (cur == B)
		{
			cout << dist + 1 << "\n";
			return 0;
		}

		long long oper[2] = { cur * 2, cur * 10 + 1 };

		for (int i = 0; i < 2; i++) {
			if (oper[i] > B || m[oper[i]])
				continue;

			m[oper[i]] = true;
			que.push({ oper[i], dist + 1 });
		}
	}

	cout << -1 << "\n";

	return 0;
}