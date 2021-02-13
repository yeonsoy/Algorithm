#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// 수강신청

int K, L;
unordered_map <string, int> m;
map <int, string> students;

int main() {

	fastio();

	cin >> K >> L;

	string n;
	for (int i = 0; i < L; i++) {
		cin >> n;
		m[n] = i;
	}

	for (auto temp : m)
		students[temp.second] = temp.first;

	int count = 0;
	for (auto temp : students) {
		cout << temp.second << "\n";
		count++;

		if (count == K)
			break;
	}

	return 0;
}