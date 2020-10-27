#include <string>
#include <vector>
using namespace std;

// 기능개발

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int k = 1;
	int cur = (100 - progresses[0]) / speeds[0];
	if ((100 - progresses[0]) % speeds[0] != 0)
		cur++;

	for (int i = 1; i < progresses.size(); i++)
	{
		int next = (100 - progresses[i]) / speeds[i];

		if ((100 - progresses[i]) % speeds[i] != 0)
			next++;

		if (cur >= next)
			k++;
		else
		{
			answer.push_back(k);
			k = 1;
			cur = next;
		}
	}

	answer.push_back(k);

	return answer;
}