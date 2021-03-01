#include <iostream>
#include <queue>
using namespace std;

// 물통

struct water {
	int a, b, c;
};

int A, B, C;
bool visited[202][202];
bool answer[202];

int main() {

	cin >> A >> B >> C;

	queue <water> que;
	que.push({ 0, 0, C });

	while (!que.empty()) {
		water n = que.front();
		que.pop();

		if (visited[n.a][n.b])
			continue;

		visited[n.a][n.b] = true;

		if (n.a == 0)
			answer[n.c] = true;

		// a -> b
		if (n.a + n.b > B)
			que.push({ (n.a + n.b) - B, B, n.c });
		else
			que.push({ 0, n.a + n.b, n.c });

		// a -> c
		if (n.a + n.c > C)
			que.push({ (n.a + n.c) - C, n.b, C });
		else
			que.push({ 0, n.b, n.a + n.c });

		// b -> a
		if (n.b + n.a > A)
			que.push({ A, (n.a + n.b) - A, n.c });
		else
			que.push({ n.a + n.b, 0, n.c });

		// b -> c
		if (n.b + n.c > C)
			que.push({ n.a, (n.b + n.c) - C, C });
		else
			que.push({ n.a, 0, n.b + n.c });

		// c -> a
		if (n.c + n.a > A)
			que.push({ A, n.b, (n.a + n.c) - A });
		else
			que.push({ n.a + n.c, n.b, 0 });

		// c -> b
		if (n.c + n.b > B)
			que.push({ n.a, B, (n.b + n.c) - B });
		else
			que.push({ n.a, n.b + n.c, 0 });
	}

	for (int i = 0; i <= C; i++)
		if (answer[i])
			cout << i << " ";

	return 0;
}