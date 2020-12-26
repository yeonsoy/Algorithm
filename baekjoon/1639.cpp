#include <iostream>
using namespace std;

// 행운의 티켓

string S;

int main()
{
	cin >> S;

	int answer = 0;

	int temp = 2;

	while (temp <= S.size())
	{
		for (int i = 0; i < S.size(); i++)
		{
			int st = i;
			int ed = st + temp;

			if (ed > S.size())
				break;

			int left_sum = 0;
			int right_sum = 0;
			for (int j = st; j < (st + ed) / 2; j++)
				left_sum += S[j] - '0';

			for (int j = (st + ed) / 2; j < ed; j++)
				right_sum += S[j] - '0';

			if (left_sum == right_sum)
				answer = max(answer, temp);
		}

		temp += 2;
	}

	cout << answer << endl;

	return 0;
}