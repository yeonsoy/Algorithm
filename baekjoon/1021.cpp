#include <iostream>
#include <deque>
using namespace std;

// 회전하는 큐

int N, M;
deque <int> dq;
int answer;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		dq.push_back(i + 1);
	
	int number;
	for (int i = 0; i < M; i++)
	{
		cin >> number;

		int left = 0;
		for (int j = 0; j < dq.size(); j++)
			if (number == dq[j])
			{
				left = j;
				break;
			}

		int right = dq.size() - left - 1;
		int temp = 0;

		while (true)
		{
			if (left == 0)
			{
				dq.pop_front();
				break;
			}

			if (left <= right)
			{
				temp = dq.front();
				dq.pop_front();
				if (temp == number) break;
				answer++;
				dq.push_back(temp);
			}
			else {
				temp = dq.back();
				dq.pop_back();
				answer++;
				if (temp == number) break;
				dq.push_front(temp);
			}
		}
	}

	cout << answer << endl;


	return 0;
}