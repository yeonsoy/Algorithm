#include <iostream>
#include <string>
#include <set>
using namespace std;

// 숫자판 점프

int map[5][5];
set <string> answer;

void solve(int r, int c, string str)
{
	if (str.size() == 6)
	{
		answer.insert(str);
		return;
	}

	if (r + 1 < 5)
		solve(r + 1, c, str + to_string(map[r + 1][c]));

	if (c + 1 < 5)
		solve(r, c + 1, str + to_string(map[r][c + 1]));

	if (r - 1 >= 0)
		solve(r - 1, c, str + to_string(map[r - 1][c]));

	if (c - 1 >= 0)
		solve(r, c - 1, str + to_string(map[r][c - 1]));
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			solve(i, j, to_string(map[i][j]));

	cout << answer.size() << "\n";

	return 0;
}