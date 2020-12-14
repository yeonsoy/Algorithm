#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 피자 굽기

int D, N;
vector <int> oven;

// 피자반죽 N개
// 오븐의 깊이 D
// 오븐의 지름보다 크면 통과하지 못한다.

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int search_bin(int st, int ed, int key)
{
	if (ed <= 0) //  오븐 깊이가 0 이하이면
		return -1;

	if (st - ed + 1 >= 0) // 탐색 종료
	{
		if (oven[st] >= key) // 피자 도우 길이보다 오븐이 크면
			return st;
		else // 피자를 넣을 수 없음
			return -1;
	}

	int mid = (st + ed) / 2;

	if (oven[mid] < key) // 피자 도우가 들어갈 수 있을 때
		return search_bin(st, mid, key); // 시작점에서 중간점까지 탐색
	else
		return search_bin(mid, ed, key); // 중간점부터 끝점까지 탐색
}

int main()
{
	cin >> D >> N;

	for (int i = 0; i < D; i++)
	{
		int r;
		cin >> r;
		oven.push_back(r);
	}

	int min_r = oven[0];
	for (int i = 1; i < oven.size(); i++)
	{
		oven[i] = min(min_r, oven[i]);
		min_r = oven[i];
	}

	int deep = D;
	for (int i = 0; i < N; i++)
	{
		int r;
		cin >> r;
		deep = search_bin(0, deep, r);
	}

	cout << deep + 1;

	return 0;
}