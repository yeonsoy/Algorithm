#include <iostream>
using namespace std;

// 팩토리얼 0의 개수

int N;

int main()
{
	cin >> N;

	int two = 0, five = 0;

	for (int i = 2; i <= N; i *= 2)
		two += N / i;

	for (int i = 5; i <= N; i *= 5)
		five += N / i;

	if (two < five)
		cout << two;
	else
		cout << five;

	return 0;
}