#include <iostream>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// LCS 2

string a, b;
int LCS[1001][1001];
string answer;

int main() {

	fastio();

	cin >> a >> b;
	
	int i = 1;
	int j = 1;

	for (i = 1; i <= a.size(); i++)
		for (j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
		}


	i = a.size();
	j = b.size();

	while (LCS[i][j] != 0) {
		if (LCS[i - 1][j] == LCS[i][j]) {
			i--;
		}

		else if (LCS[i][j] == LCS[i][j - 1]) {
			j--;
		}

		else {
			answer = a[i - 1] + answer;
			i--;
			j--;
		}
	}

	cout << LCS[a.size()][b.size()] << "\n";

	if (LCS[a.size()][b.size()] != 0)
		cout << answer;
	return 0;
}