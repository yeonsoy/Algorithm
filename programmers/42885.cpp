#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 구명보트

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    int pivot = 0;
    int i = people.size() - 1;

    while (i >= pivot)
    {
        if (people[i] + people[pivot] <= limit)
        {
            answer++;
            pivot++;
        }
        else
            answer++;

        i--;
    }

    return answer;
}