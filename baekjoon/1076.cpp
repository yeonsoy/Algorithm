#include <iostream>
using namespace std;

// 저항

string str;

int main()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> str;
		if (i == 2)
		{
			if (count != 2) {
				if (str == "brown")
					cout << "0";
				else if (str == "red")
					cout << "00";
				else if (str == "orange")
					cout << "000";
				else if (str == "yellow")
					cout << "0000";
				else if (str == "green")
					cout << "00000";
				else if (str == "blue")
					cout << "000000";
				else if (str == "violet")
					cout << "0000000";
				else if (str == "grey")
					cout << "00000000";
				else if (str == "white")
					cout << "000000000";
			}
		}
		else
		{
			if (str == "black")
			{
				if (i != 0)
					cout << "0";
				count++;
			}
			else if (str == "brown")
				cout << "1";
			else if (str == "red")
				cout << "2";
			else if (str == "orange")
				cout << "3";
			else if (str == "yellow")
				cout << "4";
			else if (str == "green")
				cout << "5";
			else if (str == "blue")
				cout << "6";
			else if (str == "violet")
				cout << "7";
			else if (str == "grey")
				cout << "8";
			else if (str == "white")
				cout << "9";
		}
	}

	return 0;
}