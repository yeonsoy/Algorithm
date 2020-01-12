#include <iostream>
#include <vector>

using namespace std;
int N; // 동전 종류
int K; // 합
vector <int> coins;

int main()
{
	cin >> N >> K;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		coins.push_back(temp);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (coins[i] <= K)
		{
			int coin_count = K / coins[i]; // 현재 코인을 몇 개나 사용할 것인가

			K = K - (coins[i] * coin_count); // 사용한 코인 만큼 제외
			count += coin_count; // 사용한 코인 개수
		}
	}
	cout << count;
	
	
	return 0;
}