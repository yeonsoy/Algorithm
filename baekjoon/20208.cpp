#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);

// 진우의 민트초코우유

int N, M, H;
typedef pair<int, int> point;
point dir[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int map[11][11];
point home;
vector <point> mint_choco;
vector <int> drink;
bool isDrink[11];
int answer;

int wayTo(point a, point b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int isPossible(point a, point b, int hp) {

	int d = wayTo(a, b);
	if (d > hp)
		return -1;
	else
		return hp - d + H;
}

void go(point cur, int hp) {

	if (drink.size() > 0)
	{
		int d = wayTo(cur, home);
		if (d <= hp)
			answer = max(answer, (int)drink.size());
	}

	for (int i = 0; i < mint_choco.size(); i++)
		if (!isDrink[i]) {
			int cur_hp = isPossible(cur, mint_choco[i], hp);
			if (cur_hp > 0) {
				isDrink[i] = true;
				drink.push_back(i);
				go(mint_choco[i], cur_hp);
				drink.pop_back();
				isDrink[i] = false;
			}
		}
}

int main() {

	fastio();

	cin >> N >> M >> H;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1)
				home = { i, j };
			else if (map[i][j] == 2)
				mint_choco.push_back({ i, j });
		}

	go(home, M);

	cout << answer << "\n";

	return 0;
}