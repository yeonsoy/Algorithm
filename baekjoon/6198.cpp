#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 옥상 정원 꾸미기

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int N;
long long answer;
vector <long long> building;

int main() {

	fastio();

	cin >> N;

	building.resize(N);
	for (int i = 0; i < N; i++)
		cin >> building[i];

	stack <int> st;

	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && st.top() <= building[i])
			st.pop();

		st.push(building[i]);

		answer += st.size() - 1;
	}

	cout << answer << "\n";
}