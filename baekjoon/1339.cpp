#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 단어 수학

int N;
vector <string> words;
int number_index['Z' - 'A' + 1];
int number[10];
bool isUsed[10];
set <char> alphabet;
int answer;

int getNum(string str)
{
	int res = 0;
	int cur = 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		res += number[number_index[str[i] - 'A']] * cur;
		cur *= 10;
	}
	return res;
}

void solve(int idx, int count)
{
	if (count == 9 - alphabet.size())
	{
		int res = 0;
		for (int i = 0; i < words.size(); i++)
			res += getNum(words[i]);

		answer = max(res, answer);
		return;
	}

	for (int i = 0; i < alphabet.size(); i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			number[i] = count;
			solve(i, count - 1);
			isUsed[i] = false;
		}
	}
}

int main() {

	cin >> N;
	words.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
		for (int j = 0; j < words[i].size(); j++)
			alphabet.insert(words[i][j]);
	}

	int idx = 0;
	for (auto ch : alphabet)
		number_index[ch - 'A'] = idx++;

	solve(0, 9);
	
	cout << answer << "\n";
	
	return 0;
}