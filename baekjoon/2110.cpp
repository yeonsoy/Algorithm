#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 공유기 설치

int N, C;
vector <int> home;
int answer;

bool isPossible(int dist)
{
	int cur = home.front();
	int count = 1;
	for (int i = 1; i < N; i++)
		if (cur + dist <= home[i])
		{
			count++;
			cur = home[i];
		}

	return (count >= C);
}

int main() {

	cin >> N >> C;
	home.resize(N);

	for (int i = 0; i < N; i++)
		cin >> home[i];

	sort(home.begin(), home.end());

	int st = 1;
	int ed = home.back() - home.front();

	while (st <= ed)
	{
		int mid = (st + ed) / 2;

		if (isPossible(mid))
		{
			answer = max(answer, mid);
			st = mid + 1;
		}
		else
			ed = mid - 1;
	}

	cout << answer;

	return 0;
}