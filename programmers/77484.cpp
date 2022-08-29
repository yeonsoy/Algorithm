#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 로또의 최고 순위와 최저 순위

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
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

    int worst = is_same;
    int best = is_same + zero_count;

    if (is_same > 1)
        worst = 7 - is_same;
    else
        worst = 6;

    if (is_same + zero_count > 1)
        best = 7 - (is_same + zero_count);
    else
        best = 6;

    return { best, worst };
}