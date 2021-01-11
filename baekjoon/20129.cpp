#include <iostream>
#include <deque>
#include <string>
using namespace std;

// 뒤집힌 계산기

int oper[4]; // + - * /
string str;
deque <long long> numbers;
deque <char> opers;

char getPriority(int index) {
	int cur = 0;
	for (int i = 0; i < 4; i++)
		if (oper[i] == index)
		{
			cur = i;
			break;
		}

	switch (cur)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	default:
		return '/';
	}
}

long long calculate(long long a, long long b, char oper) {
	switch (oper)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		return a / b;
	case '*':
		return a * b;
	default:
		break;
	}

	return 0;
}

long long convertToLong(string n) {

	long long d = 1;
	long long res = 0;
	for(int i = n.size() - 1; i >= 0; i--)
	{
		res += (n[i] - '0') * d;
		d *= 10;
	}

	return res;
}

int main() {

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	cin >> str;

	string num = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i];
		else {
			numbers.push_back(convertToLong(num));
			num = "";
			opers.push_back(str[i]);
		}
	}

	numbers.push_back(convertToLong(num));

	if (opers.size() > 0)
	{
		for (int i = 4; i >= 1; i--) {
			char cur = getPriority(i);
			int count = opers.size();
			while (count--) {
				if (numbers.size() == 1)
				{
					cout << numbers.front();
					return 0;
				}

				if (opers.back() == cur) {
					opers.pop_back();
					long long a = numbers.back();
					numbers.pop_back();
					long long b = numbers.back();
					numbers.pop_back();
					numbers.push_back(calculate(a, b, cur));
				}
				else {
					numbers.push_front(numbers.back());
					numbers.pop_back();
					opers.push_front(opers.back());
					opers.pop_back();
				}
			}

			if (numbers.size() > 0)
			{
				numbers.push_front(numbers.back());
				numbers.pop_back();
			}
		}
	}


	cout << numbers.front();

	return 0;
}