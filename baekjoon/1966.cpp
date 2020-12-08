#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 프린터 큐

int test_case;
typedef pair<int, int> print;

int main()
{
	cin >> test_case;
	vector <int> answer;

	for (int i = 0; i < test_case; i++)
	{
		int count = 0;
		queue <print> q;
		priority_queue <int> pq;
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			int p;
			cin >> p;
			q.push({ i, p });
			pq.push(p);
		}

		while (!q.empty())
		{
			int index = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (pq.top() == priority) // 현재 우선 순위와 정렬된 우선 순위가 일치하면
			{
				pq.pop();
				count++;

				if (index == m) // 동시에 현재 index와 목표 m이 일치하면
				{
					answer.push_back(count);
					break;
				}
			}
			else
				q.push({ index, priority }); // 뒤로 보내주기
		}

	}


	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;


	return 0;
}