#include <iostream>
#include <vector>
using namespace std;

// 주유소

int N;
vector <long long> length;
vector <long long> oil;
long long answer;

int main() {

	cin >> N;

	length.resize(N - 1);
	oil.resize(N);

	for (int i = 0; i < N - 1; i++)
		cin >> length[i];
	for (int i = 0; i < N; i++)
		cin >> oil[i];

	answer += oil[0] * length[0];

	long long cur = oil[0];
	for (int i = 1; i < N - 1; i++)
	{
		if (cur > oil[i])
			cur = oil[i];
			
		answer += cur * length[i];
	}

	cout << answer;

	return 0;
}