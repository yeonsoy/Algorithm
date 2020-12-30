#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 창고 다각형

int N;
int answer;
int warehouse[1001];

void sum(int st, int ed, int pivot)
{
	int cur = 0;
	for (int i = st; i < pivot; i++)
	{
		if (cur < warehouse[i])
			cur = warehouse[i];
		
		answer += cur;
	}

	cur = 0;
	for (int i = ed; i > pivot; i--)
	{
		if (cur < warehouse[i])
			cur = warehouse[i];

		answer += cur;
	}

	answer += warehouse[pivot];
}

int main()
{
	cin >> N;
	
	int idx = 0;
	int st = 1001, ed = 0;
	int max_idx = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> idx;
		cin >> warehouse[idx];
		if (idx < st)
			st = idx;
		if (idx > ed)
			ed = idx;

		if (warehouse[idx] > warehouse[max_idx])
			max_idx = idx;
	}

	sum(st, ed, max_idx);

	cout << answer << endl;

	return 0;
}