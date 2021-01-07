#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAX = 2187; // 3^7

// 종이의 개수

int n;
int paper[MAX][MAX];
int answer[3];

void solve(int x, int y, int cur)
{
	int now = paper[x][y];
	bool check = true;
	for (int i = x; i < x + cur && check; i++)
		for (int j = y; j < y + cur; j++)
			if (now != paper[i][j]) { //만약 종이가 정사각영역 중 아닌 것이 있다면
				check = false;
				break;
			}

	if (check)
	{
		answer[now + 1] ++;
		return;
	}

	int next = cur / 3; // 다음에 탐색할 정사각영역

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + i * next, y + j * next, next);
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solve(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << endl;

	return 0;
}
