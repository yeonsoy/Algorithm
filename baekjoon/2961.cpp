#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 도영이가 만든 맛있는 음식

struct flavor {
	int s;
	int b;
	bool isUsed;
};

int N;
vector <flavor> fl;
int recipe = 999999;

void findRecipe(int count, int pos, int s, int b)
{
	if (count > 0) {
		int diff = abs(s - b); // 신맛과 쓴맛의 차
		recipe = recipe > diff ? diff : recipe; // 기존 레시피보다 diff가 작으면 diff로 레시피 변경
	}

	for (int i = pos; i < N; i++)
	{
		if (!fl[i].isUsed)
		{
			fl[i].isUsed = true;
			findRecipe(count + 1, i, s * fl[i].s, b + fl[i].b); // 이 재료를 썼을 때의 최소값
			fl[i].isUsed = false;
		}
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int s, b;
		cin >> s >> b;
		fl.push_back({ s, b, false });
	}

	findRecipe(0, 0, 1, 0);

	cout << recipe;

	return 0;
}