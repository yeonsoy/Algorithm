#include <iostream>
using namespace std;

// SMUPC의 등장

string S;

int main() {

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		int ascii = S[i];
		string temp = to_string(ascii);
		int result = 0;

		for (int j = 0; j < temp.size(); j++)
			result += temp[j] - '0';

		for (int j = 0; j < result; j++)
			cout << S[i];

		cout << "\n";
	}

	return 0;
}