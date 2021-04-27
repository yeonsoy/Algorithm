#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 로또의 최고 순위와 최저 순위

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    int zero_count = 0;
    int is_same = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0)
        {
            zero_count++;
            continue;
        }

        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j])
            {
                is_same++;
                break;
            }
        }
    }

    int first = is_same;
    int seond = is_same + zero_count;

    int best = 0;
    int worst = 0;

    if (first == 6)
        worst = 1;
    else if (first == 5)
        worst = 2;
    else if (first == 4)
        worst = 3;
    else if (first == 3)
        worst = 4;
    else if (first == 2)
        worst = 5;
    else
        worst = 6;

    if (seond == 6)
        best = 1;
    else if (seond == 5)
        best = 2;
    else if (seond == 4)
        best = 3;
    else if (seond == 3)
        best = 4;
    else if (seond == 2)
        best = 5;
    else
        best = 6;

    answer.push_back(best);
    answer.push_back(worst);

    return answer;
}