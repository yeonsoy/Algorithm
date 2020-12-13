#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 김식당

int N, M;
string oper;
vector <pair<int, int>> order;
int isCompleted[101];

void remove(int n)
{
	for (int i = 0; i < order.size(); i++)
	{
		if (order[i].second == n) {
			order[i].second = -1;
			break;
		}
	}
}

void print()
{

	bool isAllCompleted = true;
	for (int i = 0; i < order.size(); i++) {
		if (order[i].second == -1) continue;

		if (isCompleted[order[i].second] != 0) {
			cout << order[i].second << " ";
			isAllCompleted = false;
		}
	}

	if (!isAllCompleted)
		cout << "\n";
	else
		cout << "sleep\n";
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	cin >> N >> M;

	int n, t;
	for (int i = 0; i < N; i++)
	{
		cin >> oper;

		if (oper == "order")
		{
			cin >> n >> t;
			isCompleted[n]++;
			order.push_back({ t, n });
		}
		else if (oper == "sort")
			sort(order.begin(), order.end(), compare);
		else if (oper == "complete") {
			cin >> n;
			remove(n);
			isCompleted[n]--;
		}

		print();
	}

}