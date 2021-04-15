#include <iostream>
#include <unordered_map>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cin.tie(0);

// 숫자 카드

int N, M;
unordered_map <string, bool> umap;

int main() {
	fastio();

	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		umap[str] = true;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> str;
		cout << umap[str] << " ";
	}

	return 0;
}