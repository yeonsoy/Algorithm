#include <iostream>
#include <vector>
using namespace std;

// 동전 1
// dp 문제

int n, k;
int answer;
int dp[100001];
vector <int> coins;

int main()
{
    cin >> n >> k;
    
    for(int i =0; i<n; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    dp[0] = 1;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 1; j<=k; j++)
           if(j >= coins[i]) // 현재 수가 coins보다 크거나 같은 경우에
                dp[j] = dp[j] + dp[j - coins[i]]; // 경우의 수 더해주기
    }
    cout << dp[k] << endl;
    
    return 0;
}
