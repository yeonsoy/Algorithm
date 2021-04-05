#include <iostream>
#include <map>
using namespace std;

// 베스트셀러

int N;
map <string, int> m;
int max_count = 0;
string answer; 

int main() {

	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str]++;
	}

	for (auto book : m)
		if (book.second > max_count) {
			answer = book.first;
			max_count = book.second;
		}

	cout << answer << "\n";

	return 0;
}