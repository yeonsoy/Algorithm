#include <iostream>
using namespace std;

// 크로아티아 알파벳

string word;
string croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj","s=", "z=" };
int answer = 0;

bool check(string str) {
	for (int i = 0; i < 8; i++)
		if (croatia[i] == str)
			return true;

	return false;
}

int main() {
	cin >> word;

	int i = 0;
	string cur = "";
	while (i < word.size()) {
		bool isCroatia = false;
		cur += word[i];
		for (int j = i + 1; j < i + 3 && j < word.size(); j++) {
			cur += word[j];

			if (check(cur)) {
				isCroatia = true;
				i = j + 1;
				break;
			}
		}

		answer++;
		cur = "";
		if (isCroatia)
			continue;

		i++;
	}

	cout << answer;

	return 0;
}