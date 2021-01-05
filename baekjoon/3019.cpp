#include <iostream>
using namespace std;

// 테트리스

int C, P;
int map[101];
int answer;
int T;

void checkCase1()
{
	for (int i = 0; i < C - 3; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < i + 4; j++)
			if (map[i] != map[j])
			{
				flag = false;
				break;
			}

		if (flag)
			answer++;
	}
}

void checkCase2()
{
	for (int i = 0; i < C - 1; i++)
		if (map[i] == map[i + 1])
			answer++;
}

void checkCase3()
{
	for (int i = 0; i < C - 1; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < i + 2; j++)
			if (map[i] != map[j])
			{
				flag = false;
				break;
			}

		if (flag && map[i + 2] == map[i] + 1)
			answer++;
	}

	for (int i = 0; i < C - 1; i++)
		if (map[i] == map[i + 1] + 1)
			answer++;
}

void checkCase4()
{
	for (int i = 0; i < C - 2; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < i + 3; j++)
			if (map[i] - 1 != map[j])
			{
				flag = false;
				break;
			}

		if (flag)
			answer++;
	}

	for (int i = 0; i < C - 1; i++)
		if (map[i] + 1 == map[i + 1])
			answer++;
}

void check()
{
	for (int i = 0; i < C - 2; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < i + 3; j++)
			if (map[i] != map[j])
			{
				flag = false;
				break;
			}

		if (flag)
			answer++;
	}
}

void checkCase5()
{
	for (int i = 0; i < C - 1; i++)
	{
		if (map[i] - 1 == map[i + 1])
			answer++;

		if (map[i] + 1 == map[i + 1])
			answer++;
	}

	for (int i = 0; i < C - 2; i++)
		if (map[i] == map[i + 2] && map[i] - 1 == map[i + 1])
			answer++;
}

void checkCase6()
{
	for (int i = 0; i < C - 1; i++)
		if (map[i] - 2 == map[i + 1])
			answer++;

	for (int i = 0; i < C - 2; i++)
		if (map[i + 1] == map[i + 2] && map[i] + 1 == map[i + 1])
			answer++;
}

void checkCase7()
{
	for (int i = 0; i < C - 1; i++)
		if (map[i] + 2 == map[i + 1])
			answer++;

	for (int i = 0; i < C - 2; i++)
		if (map[i] == map[i + 1] && map[i] - 1 == map[i + 2])
			answer++;
}


int main() {

	cin >> C >> P;

	for (int i = 0; i < C; i++)
		cin >> map[i];

	switch (P)
	{
		case 1: {
			answer += C;
			checkCase1();
			break;
		}
		case 2: {
			checkCase2();
			break;
		}
		case 3: {
			checkCase3();
			break;
		}
		case 4: {
			checkCase4();
			break;
		}
		case 5: {
			check();
			checkCase5();
			break;
		}
		case 6: {
			check();
			checkCase2();
			checkCase6();
			break;
		}
		case 7: {
			check();
			checkCase2();
			checkCase7();
			break;
		}
		default:
			break;
	}

	cout << answer << '\n';

	return 0;
}