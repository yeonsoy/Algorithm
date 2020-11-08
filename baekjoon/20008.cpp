#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 몬스터를 처치하자! 

typedef pair<int, int> skill;
int N;
int HP;
int answer = -1;
vector <skill> skills;

void solve(int hp_sum, int cool_time, vector <int> check) {

    // 기존에 구한 값보다 더 오랜 시간이 걸리면
    if (answer != -1 && answer < cool_time)
        return;

    if (hp_sum >= HP) {
        if (answer == -1)
            answer = cool_time;
        else
            answer = min(answer, cool_time);

        return;
    }

    for (int i = 0; i < N; i++) {

        vector <int> temp(check);

        bool flag = false;

        if (i < N - 1 && temp[i] != 0) continue;

        if (temp[i] == 0) {
            temp[i] = skills[i].first - 1;
            flag = true;
        }

        for (int j = 0; j < N; j++) {
            if (flag && i == j)
                continue;

            if (temp[j] > 0)
                temp[j]--;
        }

        if (flag)
            solve(hp_sum + skills[i].second, cool_time + 1, temp);
        else
            solve(hp_sum, cool_time + 1, temp);
    }
}

int main() {

    cin >> N >> HP;

    skills.resize(N);
    for (int i = 0; i < N; i++)
        cin >> skills[i].first >> skills[i].second;

    vector <int> isUsed(N, 0);
    solve(0, 0, isUsed);

    cout << answer << "\n";

    return 0;
}
