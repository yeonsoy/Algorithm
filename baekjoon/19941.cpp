#include <iostream>
using namespace std;

// 햄버거 분배

int N, K;
string str;
int answer;
bool isUsed[20001];

int main() {

	cin >> N >> K;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'P')
			for (int j = i - K; j <= i + K; j++) {
				if (j < 0) continue;
				if (str[j] == 'H' && !isUsed[j])
				{
					answer++;
					isUsed[j] = true;
					break;
				}
			}
	}

	cout << answer << endl;

	return 0;
}