#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int n = -1; // 사탕 종류의 수
    double m; // 상근이가 가지고 있는 돈의 양
    int c; // 사탕의 칼로리
    double p; // 사탕의 가격

    vector<int> answer;

    while (n != 0)
    {
        cin >> n >> m;

        if (n == 0)
            break;

        vector <int> dp;

        for (int i = 0; i < 10001; i++) // 사탕 가격을 정수로 변환했을 때 최대 값은 10000
            dp.push_back(0);

        int m_int = (m * 100 + 0.5); // 현금 정수로 변환

        for (int i = 0; i < n; i++)
        {
            cin >> c >> p;
            int p_int = (p * 100 + 0.5); // 사탕 가격 정수로 변환

            for (int j = p_int; j < m_int + 1; j++) // dp[j] j원이 있을 때 구매할 수 있는 가장 높은 사탕 칼로리
                dp[j] = max(dp[j], dp[j - p_int] + c); // max(기존에 j원 만큼 사탕을 구매했을 때 높았던 칼로리, 현재 사탕을 포함해서 j원 만큼 구매했을 때 칼로리)
        }

        answer.push_back(dp[m_int]);
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;
}
