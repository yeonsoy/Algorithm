#include <vector>
#include <string>
using namespace std;

// 주식가격

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for (int i = 0; i < prices.size(); i++)
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] <= prices[j])
                answer[i]++;
            else
            {
                answer[i]++;
                break;
            }
        }

    return answer;
}
