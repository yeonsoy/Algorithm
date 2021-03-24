#include <iostream>
using namespace std;

// Alphabet Cake (Small)

int T;
int R, C;
char cake[30][30];

void makeCake() {

	// 왼쪽 -> 오른쪽
	for (int i = 0; i < R; i++)
		for (int j = 1; j < C; j++)
			if (cake[i][j] == '?' && cake[i][j - 1] >= 'A' && cake[i][j - 1] <= 'Z')
				cake[i][j] = cake[i][j - 1];

	// 오른쪽 -> 왼쪽
	for (int i = 0; i < R; i++)
		for (int j = C - 2; j >= 0; j--)
			if (cake[i][j] == '?' && cake[i][j + 1] >= 'A' && cake[i][j + 1] <= 'Z')
				cake[i][j] = cake[i][j + 1];

	// 위쪽 -> 아래쪽
	for (int i = 1; i < R; i++)
		for (int j = 0; j < C; j++)
			if (cake[i][j] == '?' && cake[i - 1][j] >= 'A' && cake[i - 1][j] <= 'Z')
				cake[i][j] = cake[i - 1][j];

	// 아래쪽 -> 위쪽
	for (int i = R - 2; i >= 0; i--)
		for (int j = 0; j < C; j++)
			if (cake[i][j] == '?' && cake[i + 1][j] >= 'A' && cake[i + 1][j] <= 'Z')
				cake[i][j] = cake[i + 1][j];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << cake[i][j];
		cout << "\n";
	}
}

int main() {

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> cake[i][j];

		cout << "Case #" << test_case + 1 << ":\n";
		makeCake();
	}

	return 0;
}