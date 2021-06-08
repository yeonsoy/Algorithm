#include <iostream>
#include <stack>
using namespace std;

// 도키도키 간식드리미

int N;
stack <int> students;

int main() {

	cin >> N;

	int cur = 1;
	int student;
	for (int i = 0; i < N; i++) {
		cin >> student;
		students.push(student);
		while (true) {
			if (students.empty()) break;

			if (students.top() == cur) {
				students.pop();
				cur++;
			}
			else
				break;
		}
	}

	if (students.size() == 0)
		cout << "Nice\n";
	else
		cout << "Sad\n";

	return 0;
}