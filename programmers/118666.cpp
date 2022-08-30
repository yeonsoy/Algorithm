#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 성격 유형 검사하기

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	unordered_map <char, int> score;

	for (int i = 0; i < choices.size(); ++i)
	{
		if (choices[i] == 4)
			continue;

		char agree = survey[i][0];
		char disagree = survey[i][1];

		if (choices[i] < 4)
			score[agree] += 3 - (choices[i] - 1);
		else
			score[disagree] += (choices[i] - 1) - 3;
	}

	if (score['R'] < score['T'])
		answer += 'T';
	else
		answer += 'R';

	if (score['C'] < score['F'])
		answer += 'F';
	else
		answer += 'C';

	if (score['J'] < score['M'])
		answer += 'M';
	else
		answer += 'J';

	if (score['A'] < score['N'])
		answer += 'N';
	else
		answer += 'A';

	return answer;
}