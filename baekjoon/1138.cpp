#include <iostream>
#include <vector>
using namespace std;

// 한 줄로 서기

int N;
vector <int> height;
int line[11];

void setNumber(int idx) {

	if (idx == 1) {
		line[height[idx - 1]] = 1;
	}
	else {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (count == height[idx - 1]) {
				if (line[i] == 11) {
					line[i] = idx;
					break;
				}
			}

			if (line[i] > idx)
				count++;
		}
	}
}

int main() {

	cin >> N;
	height.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> height[i];
		line[i] = 11;
	}

	for (int i = 0; i < N; i++)
		setNumber(i + 1);

	for (int i = 0; i < N; i++)
		cout << line[i] << " ";

	return 0;
}