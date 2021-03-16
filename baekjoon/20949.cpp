#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// 효정과 새 모니터

int N;
vector <pair<double, int>> monitor;

bool compare(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	} return a.first > b.first;
}

int main() {
	cin >> N;
	monitor.resize(N);

	int W, H;
	for (int i = 0; i < N; i++) {
		cin >> W >> H;
		monitor[i].first = sqrt(W * W + H * H) / 77;
		monitor[i].second = i + 1;
	}

	sort(monitor.begin(), monitor.end(), compare);

	for (int i = 0; i < N; i++)
		cout << monitor[i].second << "\n";

	return 0;
}