#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 다이어트

int N;

struct nutrient {
	int mp;
	int mf;
	int ms;
	int mv;
	int price;
};

vector <nutrient> nutrients;
vector <pair<int, vector<int>>> answer;
nutrient min_value;
bool isUsed[16];
int res = 2e9;

bool check(nutrient n)
{
	if (n.mp >= min_value.mp && n.mf >= min_value.mf && n.ms >= min_value.ms && n.mv >= min_value.mv)
		return true;
	else
		return false;
}

void solve(int idx, nutrient cur, vector <int> cb)
{
	if (cur.price < res && check(cur))
	{
		res = cur.price;
		answer.push_back({ cur.price, cb });
		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (!isUsed[i]) {

			nutrient next = nutrients[i];
			isUsed[i] = true;
			cb.push_back(i + 1);
			solve(i + 1, { cur.mp + next.mp, cur.mf + next.mf, cur.ms + next.ms, cur.mv + next.mv, cur.price + next.price }, cb);
			cb.pop_back();
			isUsed[i] = false;
		}
	}
}

bool compare(pair<int, vector<int>> a, pair<int, vector<int>> b)
{
	if (a.first == b.first)
		return a.first;
	else
		return a.first < b.first;
}

int main()
{

	cin >> N;
	nutrients.resize(N);

	cin >> min_value.mp >> min_value.mf >> min_value.ms >> min_value.mv;

	for (int i = 0; i < N; i++)
		cin >> nutrients[i].mp >> nutrients[i].mf >> nutrients[i].ms >> nutrients[i].mv >> nutrients[i].price;

	solve(0, { 0, 0, 0, 0, 0 }, {});

	if (answer.size() == 0)
	{
		cout << -1 << "\n";
	}
	else {
		sort(answer.begin(), answer.end(), compare);
		cout << answer[0].first << "\n";
		for (int i = 0; i < answer[0].second.size(); i++)
			cout << answer[0].second[i] << " ";
	}
	return 0;
}