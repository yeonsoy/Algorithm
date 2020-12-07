#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

// 민트 초코

int N;
int divide[100001];

void factorization(int n, bool flag)
{
	if (n < 0)
		n = -n;

	for (int i = 2; i * i <= n; i++)
		while (n % i == 0)
		{
			if (flag)
				divide[i]++;
			else
				divide[i]--;

			n /= i;
		}

	if (n > 1)
		if (flag)
			divide[n]++;
		else
			divide[n]--;
}

int main() {

	fastio();

	int temp;
	char oper = '*';
	string str;

	cin >> N;
	cin >> temp;


	if (N == 1)
	{
		cout << "mint chocolate";
		return 0;
	}

	factorization(temp, true);

	bool flag = false;

	if (temp == 0)
		flag = true;

	for (int i = 1; i < N; i++)
	{
		cin >> oper >> temp;

		if (!flag)
		{
			if (temp == 0)
			{
				flag = true;
				continue;
			}

			if (oper == '*')
				factorization(temp, true);
			else if (oper == '/')
				factorization(temp, false);
		}
	}

	if (!flag) {
		for (int i = 2; i < 100001; i++) {
			if (divide[i] < 0)
			{
				cout << "toothpaste";
				return 0;
			}
		}
	}

	cout << "mint chocolate";

	return 0;
}