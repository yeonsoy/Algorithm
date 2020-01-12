#include <iostream>
#include <vector>
#include <math.h>

int n;
using namespace std;
vector <int> stair;
vector <int> dp;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cin >> n; // 1 ~ 100
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		stair.push_back(temp);
		dp.push_back(temp);
	}

	// 조건 : 첫 번째 계단을 밟고 이어 두 번째나, 세 번째 계단으로 오를 수 있다
	// 첫 번째 계단을 밟고 네 번째 계단으로 올라가는 것은 불가능하다.
	// 첫 번째, 두 번째, 세 번째 계단을 연속으로 밟을 수 없다.
	
	// 따라서, 처음 계단을 밟을 수 있는 계단은 첫 번째, 두 번째 중 하나이다.
	// 마지막 도착 계단은 반드시 밟아야 한다.

	dp[0] = stair[0]; // 첫 번째
	dp[1] = max(stair[1] + stair[0], stair[1]); // 두 번째 1 + 2 or 1
	dp[2] = max(stair[2] + stair[0], stair[1] + stair[2]); // 세 번째 1 + 2 or 2 + 3
	
	// 마지막 계단을 밟는 경우 (= dp[n]의 경우)
	// dp[n] = max (dp[n-2] + stair[n], dp[n-1] + dp[n-3] + stair[n]);
	// 마지막 계단 + 전 전 계단 or 마지막 계단 + 전 계단 + 전 전 전 계단

	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);

	cout << dp[n - 1];

	return 0;
}