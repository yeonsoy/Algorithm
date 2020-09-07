#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 위장

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector <string> types;
    vector <int> types_count;

    for (int i = 0; i < clothes.size(); i++)
        types.push_back(clothes.at(i).at(1));

    sort(types.begin(), types.end());
    types.erase(unique(types.begin(), types.end()), types.end());

    int num = 0;
    for (int i = 0; i < types.size(); i++)
    {
        for (int k = 0; k < clothes.size(); k++)
        {
            if (clothes.at(k).at(1) == types.at(i))
                num++;
        }
        types_count.push_back(num);
        num = 0;
    }

    for (int i = 0; i < types_count.size(); i++)
        answer *= (types_count.at(i) + 1);

    answer--;

    return answer;
}
