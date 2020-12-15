#include <iostream>
using namespace std;

// 시험 점수

struct score {
    int c, m, s, e;
};
score minguk;
score manse;

int main() {

    cin >> minguk.c >> minguk.m >> minguk.s >> minguk.e;
    cin >> manse.c >> manse.m >> manse.s >> manse.e;

    int sum_m = minguk.c + minguk.m + minguk.s + minguk.e;
    int sum_s = manse.c + manse.m + manse.s + manse.e;

    cout << max(sum_m, sum_s);

    return 0;
}
