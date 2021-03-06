#include <iostream>
#include <unordered_map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// 문자열 집합

int N, M;
unordered_map <string, int> S;
int answer;

int main() {

	fastio();

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		S[str]++;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (S[str] > 0)
			answer++;
	}

	cout << answer << "\n";
	return 0;
}