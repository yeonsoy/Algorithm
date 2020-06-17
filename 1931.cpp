#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 회의실배정

struct contract {
    int start_time;
    int end_time;
};

int N;

bool compare(contract a, contract b)
{
    if (a.end_time < b.end_time) return true;
    if (a.end_time > b.end_time) return false;
    return a.start_time < b.start_time;
}

int main() {

    vector <contract> contracts;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int st, ed;
        cin >> st >> ed;
        contracts.push_back({st, ed});
    }

    sort(contracts.begin(), contracts.end(), compare);

    int now_end = contracts[0].end_time;
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (contracts[i].start_time >= now_end)
        {
            count++;
            now_end = contracts[i].end_time;
        }
    }

    cout << count;
    return 0;
}
