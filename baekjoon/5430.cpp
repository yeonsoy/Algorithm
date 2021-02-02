#include <iostream>
#include <deque>
#include <string>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// AC

int T;
string p;
int n;
string arr;
deque <int> dq;

string result() {
	string temp = "";
	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i] >= '0' && arr[i] <= '9')
			temp += arr[i];
		else
		{
			dq.push_back(stoi(temp));
			temp = "";
		}
	}

	if (temp != "")
		dq.push_back(stoi(temp));


	bool isReverse = false;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == 'R')
			isReverse = !isReverse;
		else if (p[i] == 'D') {
			if (dq.empty()) {
				return "error";
			}
			else if (!isReverse)
				dq.pop_front();
			else if(isReverse)
				dq.pop_back();
		}
	}

	string res = "[";
	while (!dq.empty()) {
		if (!isReverse) {
			res += to_string(dq.front());
			dq.pop_front();
		}
		else {
			res += to_string(dq.back());
			dq.pop_back();
		}

		if (!dq.empty())
			res += ",";
	}

	res += "]";
	dq.clear();

	return res;
}

int main() {

	fastio();

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> p >> n >> arr;
		cout << result() << "\n";
	}

	return 0;
}