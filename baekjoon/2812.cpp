#include <iostream>
#include <deque>
using namespace std;

// 크게 만들기

int N, K;
string str; 
deque<char> dq;
int main() {

	cin >> N >> K;
	cin >> str;

	for (int i = 0; i < N; i++)
	{ 
		// 현재 수보다 다음 수가 더 크면 현재 수를 제거
		while (K && !dq.empty() && dq.back() < str[i])
		{ 
			dq.pop_back();
			K--;
		}
		dq.push_back(str[i]);
	}

	// 뒤 쪽에 남아있는 K개의 수도 제거
	for (int i = 0; i < dq.size() - K; i++)
		cout << dq[i];

	return 0;
}