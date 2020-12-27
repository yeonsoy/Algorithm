#include <iostream>
using namespace std;

// 오목

int board[21][21];

bool check(int r, int c, int color)
{
	bool res = true;

	if (c + 4 < 19)
	{
		// 오른쪽
		for (int i = 0; i < 5; i++)
			if (board[r][c + i] != color)
			{
				res = false;
				break;
			}

		if (c - 1 >= 0)
			if (board[r][c - 1] == color)
				res = false;

		if (c + 5 < 19)
			if (board[r][c + 5] == color)
				res = false;

		if (res)
			return true;
	}
	if (r + 4 < 19)
	{
		res = true;
		// 아래
		for (int i = 0; i < 5; i++)
			if (board[r + i][c] != color)
			{
				res = false;
				break;
			}

		if (r - 1 >= 0)
			if (board[r - 1][c] == color)
				res = false;

		if (r + 5 < 19)
			if (board[r + 5][c] == color)
				res = false;

		if (res)
			return true;
	}
	if (r + 4 < 19 && c + 4 < 19)
	{
		res = true;
		// 대각선 (오른쪽 아래)
		for (int i = 0; i < 5; i++)
			if (board[r + i][c + i] != color)
			{
				res = false;
				break;
			}

		if (r - 1 >= 0 && c - 1 >= 0)
			if (board[r - 1][c - 1] == color)
				res = false;

		if (r + 5 < 19 && c + 5 < 19)
			if (board[r + 5][c + 5] == color)
				res = false;

		if (res)
			return true;
	}
	if (r - 4 >= 0 && c + 4 < 19)
	{
		res = true;
		// 대각선 (오른쪽 위)
		for (int i = 0; i < 5; i++)
			if (board[r - i][c + i] != color)
			{
				res = false;
				break;
			}

		if (r - 5 >= 0 && c + 5 < 19)
			if (board[r - 5][c + 5] == color)
				res = false;

		if (r + 1 < 19 && c - 1 >= 0)
			if (board[r + 1][c - 1] == color)
				res = false;

		if (res)
			return true;
	}

	return false;
}

int main() {

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			if (board[i][j] != 0)
			{
				if (check(i, j, board[i][j]))
				{
					cout << board[i][j] << "\n";
					cout << i + 1 << " " << j + 1 << "\n";
					return 0;
				}
			}

	cout << "0" << "\n";

	return 0;
}